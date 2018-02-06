#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
const int inf = 0x3f3f3f3f;
char ss[maxn];
int sum[maxn];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%s", ss + 1);
        int n = strlen(ss + 1);
        if (ss[1] == 'P') {
            puts("-1");
            continue;
        }
        int cost = 0;
        for (int i = 1; i <= n; ++i)  {
            if (ss[i] == 'V') ++cost;
            else --cost;
            sum[i] = cost;
        }
        int ans = 0, maxGain = 0, maxIndex = -inf;
		int pos = -1, nowE = 0, lastGain = 0;
        for (int i = 1; i <= n; ++i) {
            if (sum[i] > maxGain) {
                maxGain = sum[i];
                maxIndex = i;
            }
            if (ss[i] == 'V') ++nowE;
            else --nowE;
            
            if (nowE < 0) {
                if (pos != maxIndex) {
                    if (!ans) {
                        ++ans;
                        pos = maxIndex;
                    } else {
                        pos = maxIndex;
                    }
                    nowE += (maxGain - lastGain) * ans;
                    lastGain = maxGain;
                } else {
                    ++ans;
                    nowE += maxGain;
                }
            }
        }
        printf("%d\n", ans + 1);
    }
	return 0;
}
