## Where does the error come from

error due to "bias"(偏差) and "variance"(方差)

### Estimator

$\hat{y}=\hat{f}(x)$ optimal function

we find $f^* $ from training data

#### Bias and Variance of Estimator

$E[f^*]=\bar{f}$

Bias 靶向 ，Variance 使得數據偏離靶向。

Simple model has small Variance but large Bias;

Complex model has small bias but large variance.

error from *variance* called *Overfitting*, from *bias* called *Underfitting*.

Case1. for large bias

-   redesign model：add more features and more complex model

Case2. for large variance 

-   More data(not practical)
-   Regularization(redefine loss function but harmful to Bias)

### Model Selection

Balance bias and variance

NOT do : use models to adapt Testing Set(not real Testing Set)

splitting Training :Traning Set form Models and Validation Set to Validate Models

​				or N-fold Cross Validation





