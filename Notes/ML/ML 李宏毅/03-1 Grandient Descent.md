# Gradient Descent



$\theta^*=\underset{\lambda}{arg \min} \ L(\theta)$ 	L: loss function  $\theta$: parameters

$\triangledown  L(\theta)= \begin{bmatrix}  \partial L(\theta_1)/ \partial \theta_1 \\ \partial L(\theta_2)/ \partial \theta_2 \\ ...\end{bmatrix}_{gradient}$

$\theta^n_i=\theta^{n-1}_i - \eta \triangledown L(\theta^{n-1}_i)$ 

Gradient : Loss 的等高綫的法綫方向

## Tips

1.  ### Tuning learning rate

    ​	No. of parameters updates to Loss change can be visualized

    #### Adaptive Learning Rates

    *   at the beginning far from the destination we use large learning rate
    *   several epochs close to the destination so we reduce the learning rate
    *   **Giveing different parameters different learning rate**

    #### Adagrad

    *   Divide the lr of each para by the RMS(均方根) of its previous derivatives

        $\displaystyle para_i^{t+1}\leftarrow para_i^t-\frac{\eta^t}{\sigma^t}g^t$ 		$\displaystyle g^t=\frac{\partial L(\theta^t)}{\partial \theta}$	 

        $\sigma^t$: $RMS$ of the previous derivatives of  $para_i$ 

        $\displaystyle \sigma^t=\sqrt{\frac{1}{t+1}\sum_{i=0}^t(g^i)^2}$ 

        $\displaystyle para_i^{t+1}\leftarrow para_i^t-\frac{\eta^tg^t}{\sqrt{\frac{1}{t+1}\displaystyle  \sum_{i=0}^t(g^i)^2}}$ 

        Let $\displaystyle \eta^t=\frac{\eta}{t+1}$ , we can simplify to: 

        $\displaystyle para_i^{t+1}\leftarrow para_i^t-\frac{\eta}{\sqrt{\displaystyle  \sum_{i=0}^t(g^i)^2}}g^t$ 

        Adagrad造成反差的效果，跨參數 best step sis : 一次微分/二次微分

        **$\sigma^t \approx $ *second derivative*** 

2.  ### Stochastic(隨機) Gradient Descent 

    Pick an example $x^n$ ,calculate loss function $L^n$ with $x^n$ then update that parameter

3.  ### Feature Scaling

    E.g. $y = b + w_1x_1 + w_2x_2$

    to make different features have the same scaling

    ![FeatureScaling](C:\Users\Tongyu\Pictures\Saved Pictures\FeatureScaling.png)

    diferent parameter effects differently on $y$

    ![對比](C:\Users\Tongyu\Pictures\Saved Pictures\對比.png)

    *feature scaling* better to update parameters

    **One Ways :** for each dimension $i$: calculate mean $m_i$ and standard deviation $\sigma_i$

    E.g.  $\displaystyle x_i^r \leftarrow \frac{x_i^r-m_i}{\sigma_i}$ 

## Theory

