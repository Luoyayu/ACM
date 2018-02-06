#include <bits/stdc++.h>
using namespace std;
// 基本插入排序，复杂度O(n^2)
// 希望排序的数称为**关键词**
// int a[] = {0, 5, 2, 4, 6, 1, 3};
int a[] = {1,8,7,6,7,1,2,2,1,6,3};
void insertsort(int *d, int cnt) {
	for(int i, j = 1; j < cnt; j++) {
		int key = d[j];
		//把第j个关键词正确插入到a[1..j-1]中
		for (i = j - 1; ~i ; i--){ //需要交换来完成有序地插入
			if(d[i] <= key) break;
			swap(d[i+1], d[i]);
		}
		d[i+1] = key;
	}
}
int main() {
	int tot = sizeof(a)/sizeof(int);
	insertsort(a, tot);
	for(int i=0;i<tot;i++) cout<<a[i]<<endl;
}
