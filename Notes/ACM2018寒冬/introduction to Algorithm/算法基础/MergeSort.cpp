#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 22;
// int a[]={0,2,4,5,7,1,2,3,6};
int a[] = {0, 5, 2, 4, 6, 1, 3};
int L[maxn], R[maxn];
int ans;
void merge(int *d, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	for(int i = 1; i <= n1; i++) L[i] = d[p+i-1];
	for(int i = 1; i <= n2; i++) R[i] = d[q+i];
	int i = 1, j = 1;
	L[n1+1] = R[n2+1] = inf;
	for(int k=p; k<=r; k++) 
		if(L[i] <= R[j]) d[k] = L[i++];
		else d[k] = R[j++], ans++;
}
void mergesort(int *d, int p, int r)
{
	puts("");
	if(p < r){
		for(int i=p; i<=r; i++) cout<<a[i]<<" ";
		int q = (p+r)>>1;
		mergesort(d, p, q);
		mergesort(d, q+1, r);
		merge(d, p, q, r);
	}
}
int main() {
	int cnt = sizeof(a)/sizeof(int) - 1;
	cout<<"数组大小："<<cnt<<endl;
	mergesort(a, 1, cnt);
	for(int i=1; i<=cnt; i++) cout<<a[i]<<" ";
	cout<<endl<<"逆序对数："<<ans;
}
