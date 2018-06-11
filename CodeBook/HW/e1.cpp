#include <bits/stdtr1c++.h>
#include "feature.h"

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 50;
int a[] = {25, 55, 96, 62, 36, 10, 51, 18, 71, 93, 42, 59, 48, 34, 16, 15, 96, 60};

void Merge(int *d, int p, int q, int r) {
    int L[maxn], R[maxn];
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    int n1 = q - p + 1;
    int n2 = r - q;
    for (int i = 1; i <= n1; i++) L[i] = d[p + i - 1];
    for (int i = 1; i <= n2; i++) R[i] = d[q + i];
    int i = 1, j = 1;
    L[n1 + 1] = R[n2 + 1] = inf;
    for (int k = p; k <= r; k++)
        if (L[i] <= R[j]) d[k] = L[i++];
        else d[k] = R[j++];
}

void MergeSort(int *d, int p, int r) {
    if (p < r) {
        int m = r - p + 1;
        auto bsize = static_cast<int>(sqrt(m + 0.5));
        int bnum = m / bsize;
        if (m % bnum) bnum++;

        for (int i = 0; i < bsize; i++) MergeSort(d, p + i * bsize, p + (i + 1) * bsize - 1);
        if (bnum > bsize) MergeSort(d, p + bsize * bsize, r);

        for (int j = 1; j < bsize; j++) Merge(d, p, p + bsize * j - 1, p + bsize * (j + 1) - 1);
        if (bnum > bsize) Merge(d, p, p + bsize * bsize - 1, r);
    }
}

int main() {
    int cnt = sizeof(a) / sizeof(int);
    cout << "array size：" << cnt << endl;
    MergeSort(a, 0, cnt - 1);
    for (auto x:a) cout << x << " ";
    cout << endl;
}
