#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 7;
const int inf = 0x3f3f3f3f;
struct node {
	int low, high, sum;
}l,r,c;
node find_max_crossing_subarray(int *a, int low, int mid, int high) {
	int left_sum = -inf, max_left;
	int sum = 0;
	for(int i=mid;i>=low;i--) {
		sum += a[i];
		if(sum > left_sum)
			left_sum = sum, max_left = i;
	}
	int right_sum = -inf, max_right;
	for(int j=mid + 1;j<=high;j++) {
		sum += a[j];
		if(sum > right_sum)
			right_sum = sum, max_right = j;
	}
	return node{max_left, max_right, left_sum + right_sum};
}

node find_maximum_subarray(int *a, int low, int high) {
	if(high == low) return node2{lo, high, a[low]};
	else {
		
	}
}
int main(){

}
