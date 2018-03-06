## 数据表示范围
>unsigned  int   0～4294967295      11    
int  2147483648～2147483647       10  
unsigned long 0～4294967295       10  
long  -2147483648～2147483647      10  
long long的最大值：9223372036854775807      19  
long long的最小值：-9223372036854775808   
unsigned long long的最大值：18446744073709551615  20  
__int64的最大值：9223372036854775807  
__int64的最小值：-9223372036854775808  
unsigned __int64的最大值：18446744073709551615       20
---
pi<45> 
```C++
#define PI acos(-1)  
```
  

---

## 《GCD》
```C++                   
int gcd(int a, int b)
{return !b? a : gcd(b, a%b);}
```
																			 
---
## 《二进制》																		                     
```C++																			 
int main()
{
  int a[10000], n, cnt = 0;
  while (scanf("%d", &n)!=EOF)
        {
        cnt = 0;
        while (n!=0)
        {
            if (n%2==1)
                    a[cnt++] = 1;
            else a[cnt++] = 0;
                n /= 2;
        }
        for (int i = cnt-1; i > 0; i--)
            printf("%d", a[i]);
        printf("%d\n", a[0]);
        }
  return 0;
}
```
---
## 《mod运算》

```C++ 
    ans1 = (ans1 * 10 + a1[i]) % mod
 ```

---
```C++
#include<stdio.h>
#include<string.h>
#define mod 7
#define N 10005
char a[N] = { 0 };
int  b[N] = { 0 };
int main()
{
	while (scanf("%s", a)!=EOF)
	{
		int ans = 0;
		unsigned long len = strlen(a);
		for (int i = 0; i <len; i++)
			b[i] = a[i] - '0';

		for (int i = 0; i <len; i++)
			ans = (ans * 10  + b[i]) % mod;

			printf("%d\n", ans%mod);
			memset(a, 0, sizeof (a));
			memset(b, 0, sizeof (b));
	}
	return 0;
}
```
---
## 《 KMP BF》              
```C++
#include <stdio.h>
int main()
{
	int i, j, T;
	int m, n, a[1000005], b[1000005];
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (i = 0; i<n; i++)
			scanf("%d", &a[i]);
		for (i = 0; i<m; i++)
			scanf("%d", &b[i]);

		for (i = 0; i<n; i++)
		{
			for (j = 0; j<m; j++)
				if (a[j + i] != b[j])
					break;
			if (j == m)
				break;
		}
		if (i == n)
			printf("-1\n");
		else printf("%d\n", i + 1);
	}
	return 0;
}
#endif

```
---
## 《错排公式》  
```C++             
f(n) = (n-1) [f(n-2) + f(n-1)]
```

---
## 《 阶乘递归 》      
```C++      
int jc(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * jc(n - 1);
}
```
组合数C（n,m）=n!/(n-m)!/m!

---

## 《矩阵快速幂模板》
```C++                  
#include<cctype>
#include<cstdio>
#include<cstring>
	struct matrix
	{
		int a[15][15];
	};
	matrix mat1,mat2;
	matrix multi(matrix mat1, matrix mat2, int mod)
	{
		matrix temp;
		memset(temp.a, 0, sizeof(temp.a));
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				for (int k = 0; k < 2; k++)
					temp.a[i][j] = (temp.a[i][j] + mat1.a[i][k] * mat2.a[k][j] % mod) % mod;
		return temp;
	}

	int main()
	{
		int A, B;
		__int64 n;
		int  mod = 7;
		while (scanf("%d%d%I64d", &A, &B, &n) == 3)
		{
			if (A == 0 && B == 0 && n == 0) break;
			mat1.a[0][0] = A; mat2.a[0][0] = A;
			mat1.a[0][1] = B; mat2.a[0][1] = B;
			mat1.a[1][0] = 1; mat2.a[1][0] = 1;
			mat1.a[1][1] = 0; mat2.a[1][1] = 0;
			if (n == 1 || n == 2)
				printf("1\n");
			else
			{
				n = n - 3;
				while (n != 0)
				{
					if (n & 1)
						mat1 = multi(mat1, mat2, mod);
					mat2 = multi(mat2, mat2, mod);
					n >>= 1;
				}
				printf("%d\n", (mat1.a[0][0] + mat1.a[0][1]) % mod);
			}
		}
		return 0;
	}
```
---
                    
## 《三角形有向面积公式》

```C++
    double st(int x1, int y1, int x2, int y2, int x3, int y3) 
{
    return  0.5* (x2 * y3 - x3 * y2 - x1 * y3 + y1 * x3 + x1 * y2 - y1 * x2);
}
```
---

## 《二分查找》
```C++
bool function(int length, int number)
{
	int t, L = 0, mid = 0, R = length;
	while (L <= R)
	{
		t = mid;
		mid = (L + R) / 2;
		if (a[mid] == number)
			return true;
		if (a[mid]<number)
			L = mid;
		else
			R = mid;
		if (t == mid)
			return false;
	}
	return false;
}
```
---
## 《并查集》
```C++
#include<stdio.h>
int bin[1002];
int find(int x)
{
	int r = x;
	while (bin[r] != r)
		r = bin[r];
	return r;
}
void merge(int x, int y)
{
	int fx, fy;
	fx = find(x);
	fy = find(y);
	if (fx != fy)
		bin[fx] = fy;
}
```
---
## m to n进制转换
```C++
#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h>  
#include <string.h>  
#define N 50  
char otoz[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char m2n(char m, char n, char *mNum, char *nNum)
{
	char *np = nNum;
	unsigned int dec;
	char shang[N], tt[N];
	char *sp, *tp, getm, temp;
	strcpy(shang, mNum);
	sp = shang;
	while (*sp != '\0') {
		dec = 0;
		*tt = '\0';
		tp = tt;
		while (*sp != '\0') {
			getm = *sp > '9' ? (toupper(*sp++) - 'A' + 10) : ((*sp++) - '0');
			dec = dec * m + getm;
			if ((temp = dec / n) != 0 || *tp != '\0')
				*tp++ = otoz[temp];
			dec %= n;
		}
		*np++ = otoz[dec];
		*tp = '\0';
		strcpy(shang, tt);
		sp = shang;
	}
	*np-- = '\0';
	while (np>nNum) {
		temp = *np;
		*np-- = *nNum;
		*nNum++ = temp;
	}
	return 0;
}
int main()
{
	char m[N], n[N];
	int nn, mm;
	while (scanf("%d%d", &mm, &nn) != EOF)
	{

		scanf("%s", m);
		if (m[0] == '-')
		{
			m[0] = '0';
			m2n(mm, nn, m, n);
			printf("-%s \n", n);
		}
		else
		{
			m2n(mm, nn, m, n);
			printf("%s \n", n);
		}

	}
	return 0;
}


```
---
## 10转R进制
```C++
#include <stdio.h>
#include <math.h>
int main()
{
	int i, R, num[100];
	long N, a, c;
	while (scanf("%ld%d", &N, &R) != EOF)
	{
		a = abs(N);
		i = 0, c = 1;
		while (c != 0)
		{
			c = a / R;
			num[i++] = a%R;
			a = c;
		}
		if (N<0)
			printf("-");
		for (i = i - 1; i >= 0; i--)
		{
			if (num[i]<10)
				printf("%d", num[i]);
			else
				printf("%c", 'A' + (num[i] - 10));
		}
		printf("\n");
	}
	return 0;
}

```
---
## 快速幂+矩阵快速幂+费马小定理+mod分配律
```C++
#include <cstdio>
#include <cstring>
using namespace std;
const int mod = 1000000007;
struct Matrix
{
    __int64 m[2][2];
};
//单位矩阵 
Matrix E = { 1, 0,
0, 1
};     
//推导出的目标矩阵 
Matrix P = { 0, 1,
1, 1
};         
Matrix matrix_mul(Matrix a, Matrix b)  //矩阵乘法+Mod
{
    int i, j, k;
    Matrix c;
    memset(c.m,0,sizeof c.m);
    for (i = 0; i<2; i++)
        for (j = 0; j<2; j++)
           for (k = 0; k<2; k++)
                c.m[i][j] += (a.m[i][k] * b.m[k][j]) % (mod - 1);
            c.m[i][j] %= (mod-1);

    return c;
}

Matrix quick_Mod_Matrix(__int64 m)  //矩阵快速幂
{
    Matrix mat1 = E, b = P;
    while (m)
    {
        if (m & 1)
            mat1 = matrix_mul(mat1, b);
        m >>= 1;
        b = matrix_mul(b, b);
    }
    return mat1;
}

__int64 quickmod(__int64 a, __int64 b)  //快速幂
{
    __int64 ans = 1;
    __int64 tmp = a % mod;
    while (b)
    {
        if (b & 1)  //b是奇数为真 ，先乘temp 1次
        {
            ans *= tmp;
            ans %= mod;
        }
                   //b为偶数，直接二分 
        tmp *= tmp;
        tmp %= mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int a, b, n;
    while (scanf("%d%d%d", &a, &b, &n)==3)
    {
        Matrix p = quick_Mod_Matrix(n);
        printf("%d\n", (quickmod(a, p.m[0][0]) * quickmod(b, p.m[1][0])) % mod);
    }
    return 0;
}
```
---
## 快速欧拉和表
```C++
#include <cstdio>
using namespace std;
const int N = 3000005;
__int64 Euler[N];
void euler() //super Euler list
{
    Euler[1] = 0;
    for (int i = 2; i < N; i++)
        Euler[i] = i;
    for (int i = 2; i < N; i++)
        if (Euler[i] == i)
            for (int j = i; j < N; j += i)
                Euler[j] = Euler[j] / i * (i - 1);
    for (int i = 2; i < N; ++i)
        Euler[i] += Euler[i - 1];
}
int main() 
{
    euler();
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        printf("%d %d\n" ,Euler[b],Euler[a-1]);
        printf("%I64d\n", Euler[b] - Euler[a - 1]);
    }
    return 0;
}
```
---
## 欧拉表

```C++
#include<cstdio>
#include<cmath>
#include<algorithm>
//super Euler 
using namespace std;
__int64 ans[3000005]={0};
__int64 Euler(int x)
{
    __int64 temp=x,index=x;
    for(__int64 i=2;i*i<=index;i++)
    {
        if(!(x%i))
        	temp-=temp/i;
        while(!(x%i)) 
			x/=i;
    }
    if(x>1) 
    	temp-=temp/x;
    return temp;
}
int main()
{
    __int64 m,n;
    for(int i=1;i<3000005;i++)
        ans[i]=Euler(i);

    while(scanf("%I64d%I64d",&n,&m)!=EOF)
    {
    	__int64 sum=0;
   	for(__int64 i=n;i<=m;i++)
            sum+=ans[i];
        printf("%I64d\n",sum);
    }
    return 0;
}
```
## 筛法素数表
---
```C++
bool vis[10005]={0};
int  main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		memset(vis,0,sizeof(vis));
        int m=sqrt(n+0.5);
        for(int i=2;i<=m;i++)
            if(!vis[i])
                for(int j=i*i;j<=n;j+=i)
                    vis[j]=1;

        for(int i=0;i<n;i++)
            if(vis[i]==0)
            printf("%d ",i);
	}
    return false;
}
```
---

>## 数论常用公式  
>1.威尔逊定理（判断素数）
	当且仅当p为素数时：( p -1 )! ≡ -1 ( mod p )
或者这么写( p -1 )! ≡ p-1 ( mod p )
	若p为质数，则p能被(p-1)!+1整除

>2.欧拉定理（ 欧拉函数是求小于等于n的数中与n互质的数的数目  ）

>3.孙子定理（中国剩余定理）

>4.费马小定理
	假如p是质数，若p不能整除a，则 a^(p-1) ≡1（mod p），若p能整除a，则a^(p-1) ≡0（mod p）。
	或者说，若p是质数，且a,p互质，那么 a的(p-1)次方除以p的余数恒等于1。

>扩展欧几里得算法（化简成形如丢番图公式ax+by=c）
```C++
int extend_Euclid(int a, int b, int &x, int &y)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = extend_Euclid(b, a%b, y, x);
    y -= a/b*x; //这里已经是递归，回溯的过程了，x,y已经颠倒了
    return d;
}
```
*通解*：
```C++  
x = x0 + b*c/gcd(a,b);  求x最小正解=x0-c*a/d   
 如果x*c.d<0 x+a/d为最小正解 
y = y0 - a*c/gcd(a,b); 
```

>卢卡斯定理：
```C++
LL PowMod(LL a,LL b,LL MOD){//快速幂
    LL ret=1;  
    while(b){  
        if(b&1) ret=(ret*a)%MOD;  
        a=(a*a)%MOD;  
        b>>=1;  
    }  
    return ret;  
}  
LL fac[100005];  
LL Get_Fact(LL p){//初始化
    fac[0]=1;  
    for(int i=1;i<=p;i++)  
        fac[i]=(fac[i-1]*i)%p;  
}  
LL Lucas(LL n,LL m,LL p){//Lucas 定理
    LL ret=1;  
    while(n&&m){  
        LL a=n%p,b=m%p;  
        if(a<b) return 0;  
        ret=(ret*fac[a]*PowMod(fac[b]*fac[a-b]%p,p-2,p))%p;  
        n/=p;  
        m/=p;  
    }  
    return ret;  
}
```
---
## 0/1二叉树
```C++
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define ul unsigned long
using namespace std;
//0/1 二叉树
struct node
{
    int cnt;
    node *childs[2];//left and right child tree
    node()//init
    {
        cnt=0;
        for(int i=0;i<2;i++)
            childs[i]=NULL;
    }
};
node *root, *cur, *newnode;
int flag;

void insert(char *str)
{
	int index;
	ul len = strlen(str);
	cur = root;
	for (int i = 0; i < len; i++)
	{
		index = str[i] - '0';
		if (cur->childs[index] != NULL)//节点存在
		{
			cur = cur->childs[index];
			if (i == len - 1 || cur->cnt == 1)
			{
				flag = 0;
				break;
			}
		}
		else
		{
			newnode = new node;//newcode is struct 
			cur->childs[index] = newnode; //构建子树
			cur =cur->childs[index];//equal cur=newnode;
		}
	}
	cur->cnt = 1;//
} 
void del(node *head)
{
	for (int i = 0; i < 2; i++)
		if (head->childs[i] != NULL)
			del(head->childs[i]);
	delete (head);
}
int main()
{
	int kase = 1;
	char str[15];
	while (scanf("%s", str) != EOF)
	{
		flag = 1;
		root = new node;
		insert(str);
		while (scanf("%s", str), strcmp(str, "9"))
		{
			if (!flag)
				continue;
			insert(str);
		}
		if (!flag)
			printf("Set %d is not immediately decodable\n", kase++);
		else
			printf("Set %d is immediately decodable\n", kase++);
		del(root);
	}
	return 0;
}
```

// binary_search
#include <iostream>    
#include <algorithm>  
#include <vector>  
using namespace std;
bool cmp (int i,int j) { return (i>j); }
int main () 
{
   int myints[] = {14,13,12,11,10};
   vector<int>v(myints,myints+sizeof(myints)/sizeof(int));     
	sort (v.begin(), v.end(), cmp);
	int n;
	while(scanf("%d",&n)!=EOF)
	  if ( binary_search (v.begin(), v.end(),n,cmp))
	     cout << "found!\n";
	  else  
	  	cout << "not found.\n";
  return 0;
}
