# Regression

*   stock market forecast
*   self-driving car
*   recommendation

*Step 1* : Model

Linear model : $y = b + \sum w_ix_i \left\{\begin{matrix} x_i : attribute \  of \  input —feature\\ w_i:weight \\ b:bias \end{matrix}\right.$ 

*use function $\delta$ to design Model for more factors*

*Step 2* ：Goodness of Function

​	A set of function （Model set:$f_1,f_2$）: function input $x^1$ ，output $\hat{y}^1$

​	**Loss function $L$**：input : a function, output how bad ti is

​	$L(f)=L(w,b)$ 

​	like   $\displaystyle=\sum_{n=1}^{10}(\hat{y}^n-(b+w\cdot x_{cp}^n))^2$ to estimation error

*Step 3*: best Function

​	Pick the "Best" Function $f^*=\underset{f}{arg \ min} \ L(f)$

​					or $w^*,b^*=\underset{w,b}{arg \ min} \ L(w,b)$ 

*Step 3*:Gradient Descent 一阶最优算法，局部最小值$\triangledown L=\begin{bmatrix} \frac{\partial L }{\partial w} \\ \frac{\partial L}{\partial b}  \end{bmatrix} _{gradient}$

梯度下降法拟合Loss Function $w^*,b^*=\underset{w,b}{arg \ min} \ L(w,b)$ 

1.  :arrow_forward:(Randomly) Pick an initial value $w^0,b^0​$
2.  :arrow_forward:compute $\displaystyle \frac{\partial L}{\partial w}|_{w=w^0,b=b^0},\frac{\partial L}{\partial b}|_{w=w^0,b=b^0}$
3.  :arrow_forward:$\displaystyle w^1\leftarrow w^0-\eta\frac{\partial L}{\partial w}|_{w=w^0,b=b^0}$    $\displaystyle b^1\leftarrow b^0-\eta\frac{\partial L}{\partial b}|_{w=w^0,b=b^0}$  ($\eta$ is "learning rate")
4.  :arrow_forward: 拟合到global optimal(in Linear regression  the loss function has *no local optimal*)

![gradient descent](C:\Users\Tongyu\Pictures\Saved Pictures\gradient descent.png)

complex model has good in training data but not better on *testing data*,This is **Overfitting** 

Solution overfitting：Back to step 2 ：*Regularization*

Redefine loss function adding  $\lambda\sum(w_i)^2 $ not consider bias that makes smaller $w_i$ get better and the function get smoother->smoother function has less influence.

How smooth? select $\lambda$ obtaining best model.