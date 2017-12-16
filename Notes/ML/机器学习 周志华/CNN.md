###### convolution

连续性卷积：$(f*g)(n)=\int_{-\infty}^{+\infty}f(\tau)g(n-\tau)d\tau$

​					 $n=\tau+(n-\tau)$

离散性卷积：$\displaystyle(f*g)(n)=\sum_{\tau=-\infty}^\infty f(\tau)g(n-\tau)$ 

$descent  \ convolution$栗子：抛两个骰子和为4的概率 $\displaystyle (f\otimes g)(4)=\sum_{i=1}^3f(i)g(4-i)$ 

