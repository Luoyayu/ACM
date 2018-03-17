#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 666;
int n;
int main(){
    while(scanf("%d", &n)!=EOF){
        set<int> s;
        for(int i=1;i<=n;i++){
            int x;scanf("%d", &x);
            if(x) s.insert(x);
        }
        printf("%lu\n", s.size());
    }
    return 0;
}