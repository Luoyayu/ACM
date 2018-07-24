$Fast \ Fourier \ Transform$($FFT$)解决的问题是

$A(x)=\sum_{j=0}^{n-1}a_jx^j ,\ B(x)=\sum_{j=0}^{n-1}b_jx^j$
($n$为多项式项数,记$degree(A)=k$)  

任何一个大于一个多项式次数的整数都是该多项式的***次数界***

$\displaystyle C(x)=A(x)×B(x)=\sum_{j=0}^{2n-2}(\sum_{k=0}^{j}a_kb_{j-k})x^j$ 

$A(x)=a[0]+a[1]x+a[2]x^2+a[3]x^3+···+a[n-1]x^{n-1}$
$B(x)=b[0]+b[1]x+b[2]x^2+b[3]x^3+···+a[n-1]x^{n-1}$
$C(x)=c[0]+c[1]x+c[2]x^2+c[3]x^3+···+c[2n-2]x^{2n-2}$

$c[0]=a[0]×b[0];\ c[1]=a[0]×b[1]+b[0]×a[1]; \ c[3]=a[1]×b[2]+a[2]×b[1]$

$\displaystyle c_j=\sum_{j=0}^{2n-2}(\sum_{k=0}^{j}a_kb_{j-k})x^j$  
$\displaystyle c[j+k]=\sum_{j=0}^{n-1}\sum_{k=0}^{n-1}a_j b_k$

* $O(n^2)$

```cpp
void calC(double *a,double *b,double *c,int n) {
    for(int i=0;i<(n<<1);i++) c[i]=0;//init
    for(int i=0;i<=(n-1)<<1;i++)
    for(int j=0;j<=i&&j<n;j++)
        c[i] += a[j] * b[i-j];
  	
    //or
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            c[i+j] += a[i] * b[j];
}
```

* 优化到$(nlogn)$    注：下面使用专用符号$i$表示$\sqrt{-1}$   

多项式系数表示法通过系数向量$\textbf{A}=${$a_0,a_1,...a_{n-1}$}来确定唯一的多项式

​$A(x)=a_0+a_1x+a_2x^2+a_3x^3+···+a_{n-1}x^{n-1}$

多项式在$x_0$处求值可系通过数表达式利用***霍纳法则***$O(n)$输出$A(x_0)$

一个次数界为$n$的多项式的点值表达式就是一个由$n$各点值对组成的集合

{ $(x_0,y_0), (x_1,x_2),(x_3,y_3),...,(x_{n-1},y_{n-1})$ }

使得对于任意的整数$k=0,1,2,···,n-1, \ x_k$各不相同，其中$y_k=A(x_k)$

可以证明对于一组互不相同的{ $x_0,x_1,x_2,x_3,...,x_{n-1}$ }(称为该种表示法的基), 且该表示的多项式唯一

$A(x)=\sum_{j=0}^{n-1} a_jx^j=a_0+a_1x+a_2x^2+···+a_{n-1}x^{n-1}$

$c_j=\sum_{k=0}^{j}a_kb_{j-k}$对应的向量$\textbf{c}$即多项式$A×B$的系数向量称为输入向量$\textbf{a}$和$\textbf{b}$的**卷积**$(convolution)$,表达成$c=a\otimes b$ 

求值计算的逆称为**插值** [定理30.1：插值多项式的唯一性](1)：当插值多项式的次数界等于点值表达式的点值对插值才是明确的

* 点值表达式下多项式加法运算$C$ ：{$(x_0,y_0+{y_0}'), (x_1,y_1+{y_1}'),···,(x_k,y_{n-1}+{y_{n-1}}') $}

* 点值表达式下多项式乘法运算：$degree(C)=degree(A)+degree(B)$需扩展$A(x),B(x)$为$2n$项

  得出$C$： { $(x_0,y_0{y_0}'), (x_1,y_1{y_1}'),···,(x_k,y_{n-1}{y_{n-1}}') $ 

目前的思路由系数表达式霍斯法则$O(4n)$求$4n$个点的多项式值转换成点值表达式相乘$O(n)$,得出的结果通过求逆$O(n^2)$~$O(n^3)$再转换成系数表达式

* 此处还能进行的优化通过$DFT$(离散傅里叶变换)在特定的***单位复数根*** 处达到$O(nlogn)$求值和插值

下面着重于***单位复数根***

$n$次单位复数根是满足$\omega^n=1$的复数$\omega，$n$次单位复数根恰好有$n$个 :对于$k=0,1,2,3···n-1$ ，$\omega_n=e^{\frac{2\pi ik}{n}}(k=1)$称为主$n$次单位根

* 复数的指数定义即欧拉公式: $e^{iu}=cos(u)+isin(u)$ 

可得这$n$个单位复数根均匀地分布在复平面的原点为圆心的单位半径的圆周上

$n$个$n$次单位复数根 $\omega_n^0,\omega_n^1,\omega_n^2,···,\omega_n^{n-1}$,且在乘法意义下形成一个与加法群具有相同结构的群

***单位根基本性质*** 

* $\omega_n^n=\omega_n^0=1$,$\omega_n^{-1}=\omega_n^{n-1}$, $\omega_n^j\omega_n^k=\omega_n^{(j+k)mod \ n}$
* 消去引理: $\omega_{dn}^{dk}={(e^{\frac{2 \pi i}{dn}})}^{dk}=e^{\frac{2 \pi ik}{n}}=\omega_n^{k}$,该引理得出$(\omega_n^k)^2=\omega_{\frac{n}{2}}^k$
* 折半引理:对于$(k>0的偶数)$那么这$n$个$n$次单位复数根的平方的集合就是$\frac{n}{2}$个$\frac{n}{2}$单位复数根集合。由$\omega_n^n=1易证:${(\omega^{\frac{n}{2}+k}})^2={(\omega_n^k)}^2(k=0,1,2,3···，n-1)$ 那么如果对$n$次单位复数根进行平方将得到每个$\frac{n}{2}$次单位根$2$次
* 求和引理: $\sum_{j=0}^{n-1}=(\omega_n^k)^j=0$ 

**$DFT与FFT$**(求$A(x_0)$)

* **$DFT$** 

$A(x)=\sum_{j=0}^{n-1}a_jx^j$  在 $\omega_n^0,\omega_n^1,\omega_n^2, ···,\omega_n^{n-1}$即在$n$个$n$次单位复数根处的值(此处$n$实际是$2n$个)组成的向量即为$DFT_n(a)$  

假设$A(x)$的系数表示$a=(a_0,a_1,a_2,···,a_{n-1})$ 对$(k=0,1,2,···,n-1)$定义结果$y_k$:

$y_k=A(\omega_n^k)=\sum_{j=0}^{n-1}a_j\omega^{kj}$

记结果向量$\textbf{y}=(y_0,y_1,···,y_{n-1})$就是系数向量 $\textbf{a}=(a_0,a_1,a_2,···,a_{n-1})$的离散傅里叶变换$(DFT)$记$y=DFT_n(a)$

* ***$FFT$*** 

前置假设$n$是$2$的幂次, $FFT$ 采用奇偶分治

定义两个形式一致的次数界为$\frac{n}{2}$的多项式$A^{[0]}(x),A^{[1]}(x)$

​                    $A^{[0]}(x)=a_0+a_2x+a_4x^2···+a_{n-2}x^{\frac{n}{2}-1}$

​                   $A^{[1]}(x)=a_1+a_3x+a_5x^2···+a_{n-1}x^{\frac{n}{2}-1}$

​    一致形式$A(x)=a_0+a_1x+a_2x^2+···+a_{\frac{n}{2}-1}x^{\frac{n}{2}-1}$  

有$A(x)=A^{[0]}(x^2)+xA^{[1]}(x^2)$

那么求$A(x)$在$\omega_n^0,\omega_n^1,\omega_n^2, ···,\omega_n^{n-1}$ 处的值就转换成:

* 求次数界为$\frac{n}{2}$的多项式在$A^{[0]}(x)和A^{[1]}(x)$ 在

  ​                        $(\omega_n^0)^2,(\omega_n^1)^2,(\omega_n^2)^2, ···,(\omega_n^{n-1})^2$  

  处的取值

* 由*折半引理* 可知上式有$\frac{n}{2}$个不同的数，成功把规模为$n$的$DFT_n$ 划分成两个规模为$\frac{n}{2}$的$DFT_{\frac{n}{2}}$ 

$FFT$递归求解$n$个元素构成的 $\textbf{a}=(a_0,a_1,a_2,···,a_{n-1})$的$DFT$ 

- 小结：给出系数向量$\textbf{a}$,求解DTF_n(a)$过程为先求出$n$个$n$次单位复数根的平方。如果只有一个元素$a_0$ 那么单位根为$\omega_n^0=1$,$y_0=a_0w_n^0=a0$ ,将$\frac{n}{2}$个元素带入一致形式，转换成程序语言就是不断对$\textbf{a}$向量划分奇偶,每次划分求值。

1. 对于$k=0,1,2,3···,\frac{n}{2}-1$我们定义$y$为分治后的结果向量,

   有$y_{k}^{[0]}=A^{[0]}(\omega_{\frac{n}{2}}^k)$ , $y_k^{[1]}=A^{[1]}(\omega_{\frac{n}{2}}^k)$ 

​               那么有  $y_k=y_k^{[0]}+w_n^ky_k^{[1]} =A^{[0]}(\omega_{\frac{n}{2}}^k)+w_n^kA^{[1]}(\omega_{\frac{n}{2}}^k)$

​                                                           $=A^{[0]}(\omega_n^k)+w_n^kA^{[1]}(\omega_n^k)=A(\omega_n^k)$ 

2. 对于$k=\frac{n}{2},\frac{n}{2}+1,\frac{n}{2}+2,\frac{n}{2}+3···,n-1$那么

   $y_{k+\frac{n}{2}}=y_k^{[0]}-w_n^ky_k^{[1]} =A^{[0]}(\omega_n^{2k})+w_n^{k+\frac{n}{2}}A^{[1]}(\omega_n^{2k})$

   ​          $=A^{[0]}(\omega_n^{2k+n})+w_n^{2k+n}A^{[1]}\omega_n^{2k+n}$ 

   ​          $=A(\omega_n^{2k+n})= A(\omega_n^{k+\frac{n}{2}})$                               $(\omega_{\frac{n}{2}}^k=\omega_{n}^{2k}$ , $\omega_n^{2k+n}=-\omega_n^k)$ 

```cpp
//FFT求值C++
vector<Complex> recursive-FFT(vector<Complex>const &a) {
    int n = a.size();
  	if(n == 1) return a;
  	Complex w_n = complex(cos(2*pi/n), sin(2*pi/n));//构造主n次单位根 
  	Complex w(1,0);
  	vector<Complex> a0,a1,y;
  	a0.reserve(n/2); a1.reserve(n/2); y.reserve(n)
  	for(int i=0;i<n/2;i++) {
        a0.push_back(a[i*2]);//make_vector(a0,a2,a4,...,a n-2);//划分奇偶
      	a1.push_back(a[i*2+1]);//make_vector(a1,a3,a5,...,a n-1);
    }
  	vector<Complex> y0 = recursive-FFT(a0);//分治递归成下标为偶数的向量
  	vector<Complex> y1 = recursive-FFT(a1);//奇数
  	for(int k=0; k<n/2; k++){//0~n/2-1
        y[k] = y0[k] + w * y1[k];
        y[k+n/2] = y0[k] - w * y1[k];
      	w = w * w_n;
    }
  	return y;
}
```



模板

```cpp
#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
struct Complex {
    double r,i;
    Complex(double _r = 0.0,double _i = 0.0):r(_r),i(_i){}
    Complex operator +(const Complex &b) {
        return Complex(r+b.r,i+b.i);
    }
    Complex operator -(const Complex &b) {
        return Complex(r-b.r,i-b.i);
    }
    Complex operator *(const Complex &b) {
        return Complex(r*b.r-i*b.i,r*b.i+i*b.r);
    }
};
void change(Complex y[],int len) {
    for(int i = 1, j = len>>1;i < len-1; i++){
        if(i < j)swap(y[i],y[j]);
        int k = len>>1;
        while( j >= k)
            j -= k,k >>=1;
        if(j < k) j += k;
    }
}
/*
 * on==1时是DFT，on==-1时是逆DFT IDFT
 */
void fft(Complex y[],int len,int on) {
    change(y,len);
    for(int h = 2; h <= len; h <<= 1) {
        Complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j+=h) {
            Complex w(1,0);
            for(int k = j;k < j+h/2;k++) {
                Complex u = y[k];
                Complex t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
}
const int MAXN = 200010;
Complex x1[MAXN],x2[MAXN];
char str1[MAXN/2],str2[MAXN/2];
int sum[MAXN];

int main() {
    while(scanf("%s%s",str1,str2)==2) {
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int len = 1;

        while(len < len1*2 || len < len2*2) len<<=1;
        for(int i = 0;i < len1;i++)
            x1[i] = Complex(str1[len1-1-i]-'0',0);
        for(int i = len1;i < len;i++)
            x1[i] = Complex(0,0);
        for(int i = 0;i < len2;i++)
            x2[i] = Complex(str2[len2-1-i]-'0',0);
        for(int i = len2;i < len;i++)
            x2[i] = Complex(0,0);

        //求DFT
        fft(x1,len,1);
        fft(x2,len,1);

        for(int i = 0;i < len;i++) x1[i] = x1[i]*x2[i];//点积x1 x2
        fft(x1,len,-1);
        for(int i = 0;i < len;i++) {
            sum[i] = (int)(x1[i].r+0.5);
            printf("%d ",sum[i]);
        }printf("\n");
      
        for(int i = 0;i < len;i++){//
            sum[i+1]+=sum[i]/10;
            sum[i]%=10;
        }
        len = len1+len2-1;
        while(sum[len] <= 0 && len > 0) len--;
        for(int i = len;i >= 0;i--)
            printf("%c",sum[i]+'0');
        printf("\n");
    }
    return 0;
}
```

[1]:参见算法导论中文版P529