#include<bits/stdc++.h>
using namespace std;
// 通过归并排序求解逆序对的数量 
// 利用部分有序来快速计算
typedef long long ll;
const int maxn = 10e5+7;
const int inf = 0x3f3f3f3f;
int a[maxn];
int L[maxn], R[maxn];
ll ans;
void merge_inv(int *d, int p, int q, int r) {
	int l1 = q - p + 1;
	int l2 = r - q;
	for(int i=1; i<=l1; i++) L[i] = d[i+p-1];
	for(int i=1; i<=l2; i++) R[i] = d[i+q];
	L[l1+1] = R[l2+1] = inf;
	int i = 1, j = 1;
	for(int k = p; k <= r; k++) {
		if(L[i] <= R[j]) d[k] = L[i++];
		else {
			d[k] = R[j++];
			ans += l1 - i + 1;
		}
	}
}

void mergesort(int *d, int p, int r) {
	if(p < r) {
		int q = (p+r) >> 1;
		mergesort(d, p, q);
		mergesort(d, q+1, r);
		merge_inv(d, p, q, r);
	}
}

int main() {
	int n, k;
	while(scanf("%d %d",&n, &k)!=EOF) {
		ans = 0;
		for(int i=1;i<=n;i++) scanf("%d", &a[i]);
		mergesort(a, 1, n);
		//cout<<"逆序对数："<<ans<<endl;
		if(ans>k) printf("%lld\n",ans-k);  
        else printf("0\n"); 
	}
	return 0;
}
