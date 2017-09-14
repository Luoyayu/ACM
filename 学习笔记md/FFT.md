$Fast \ Fourier \ Transform$)解决的问题是把函数$$A(x)=\sum_{i=0}^{n-1}a_ix^i \ B(x)=\sum_{i=0}^{n-1}b_ix^i$$($n$为多项式项数)

求多项式$$C(x)=A(x)×B(x)=\sum_{i=0}^{2n-2}(\sum_{j=0}^{i}a_jb_{i-j})x^i$$

$$O(n^2)$$方法

$$A(x)=a[0]+a[1]x+a[2]x^2+a[3]x^3+···+a[n-1]x^{n-1}$$$$B(x)=b[0]+b[1]x+b[2]x^2+b[3]x^3+···+a[n-1]x^{n-1}$$$$C(x)=c[0]+c[1]x+c[2]x^2+c[3]x^3+···+c[2n-2]x^{2n-2}$$

$$c[0]=a[0]×b[0];\ c[1]=a[0]×b[1]+b[0]×a[1]; \ c[3]=a[1]×b[2]+a[2]×b[1]$$

$$c[i]=\sum_{i=0}^{2n-2}(\sum_{j=0}^{i}a_jb_{i-j})$$ 

$$c[i+j]=\sum_{i=0}^{n-1}\sum_{j=0}^{n-1}a[i]×b[j]$$

```cpp
void calC(double *a,double *b,double *c,int n)
{
  	for(int i=0;i<(n<<1);i++) c[i]=0;
  	for(int i=0;i<=(n-1)<<1;i++)
      for(int j=0;j<=i&&j<n;j++)
        c[i] += a[j] * b[i-j];
  	
  	//或者
  	for(int i=0;i<n;i++)
      	for(int j=0;j<n;j++)
          	c[i+j] += a[i] * b[j];
}
```

优化到$$nlogn$$

多项式系数表示法$A=${$$a_0,a_1,...a_{n-1}$$}来确定唯一的多项式$$A(x)=a_0+a_1x+a_2x^2+a_3x^3+···+a_{n-1}x^{n-1}$$

另一种称为点值表示法{$$(x_0,y_0)(x_1,x_2)(x_3,y_3)...(x_{n-1},y_{n-1})​$$}其中$$y_i=A(x_i)​$$

可以证明对于一组互不相同的{$$x_0,x_1,x_2,x_3,...,x_{n-1}$$}该方法表示唯一

