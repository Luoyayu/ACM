### 概率图模型之 $HMM$

关心的变量的集合$Q$,可观测变量集合$O$,其他变量集合$R$

*   生成式模型考虑联合分布$P(Q,R,O)$
*   判别式模型考虑条件分布$P(Q,R \ |\ O)$

从已知变量推测未知变量的概率分布称为推断($inference$)，

推断求得由$P(Q,R,O)$或$P(Q,R \ | \ O)$得到条件概率分布$P(Q\ |\ O)$

*   有向无环图表示概率图称为贝叶斯网$(Bayesian \ network)$
*   无向图表示下称为马尔可夫网($Markov \ network$)

状态变量$\mathcal{S}\{s_1,s_2,s_3...,s_N\}$，其中$s_i \in \mathcal{S}$ 表示第$i$时刻的隐状态/变量($hidden \ varible$)，$y_i \in \mathcal{Y}$ ,表示第$i$时刻的可见观测值。

<img src="C:\Users\Tongyu\Pictures\Saved Pictures\HMM.png" style="zoom:75%" />

​                                                                               *隐马尔科夫模型的图结构*

在$HMM$模型中系统在$\mathcal{K}$个状态$\mathcal{S}$中转换，隐状态取值空间为$N$个可能取值的离散空间，观测变量取值空间可以连续也可以离散，嘉假定离散下取值范围$\mathcal{Y}=\{o_1,o_2,...,o_M\}$ 。

*   $translation\ probility$ ：隐状态之间的转移概率即 $p(q_{t} \ |\ q_{t-1})$ 也称做*状态转移概率*
*   $emmision \ probility$ ：观测值在隐状态下的概率 即 $p(y_{t} \ | \ q_{t})$ 也称做 *输出观测概率*

$HMM$图模型之马尔科夫链($Markov \ chiain$)[^1]

马尔科夫性质：

*   $P(q_t\ | \ q_1,q_2,...,q_{t-1},y_1,y_2,...,y_{t-1})=P(q_t \ | \ q_{t-1})$ 即：当前隐状态只和前一个隐状态有关
*   $P(y_t \ | \ q_1,q_2,...,q_{t-1},y_1,y_2,...,y_{t-1})=P(y_t \ | \ q_t)$    即：当前观测状态只由当前的隐状态得出

#### $HMM$联合概率分布：

​			$$\displaystyle P(y_1,y_2,...y_n,q_1,q_2,...,q_n)=P(y_1 \ | \ q_1)P(q_1)\prod_{i=2}^{n}P(q_{i} \ | \ q_{i-1})P(y_i \ | \ q_i)$$

​			$\pi(q_1)=P(q_1)$

*   模型在各个状态间转换的概率矩阵$\mathbf{A}=[a_{ij}]_{N*N}$ 其中

    ​	$a_{ij}=P(q_{t+1}=s_j \ | \ q_t=s_i)$             ，$1\leqslant i,j\leqslant N $ 

    ​	$$\displaystyle \sum_{j=1}^{N}a_{ij}=1$$                                            ，$\forall i,j$

    表示在任意时刻$t​$若状态为$s_i​$,则在下一时刻状态为$s_j​$的概率。

*   发射概率矩阵$\mathbf{B}=\{b_i(j)\}=[b_{ij}]_{N\times M}$，其中

    ​	$b_i(j)=b_{ij}=P(y_t=o_j \ | \ q_t=s_i)$                ，$1\leqslant i \leqslant N,j\leqslant M $ 

    表示任意时刻$t$，若状态为$s_i$,则观测值$o_j$被获取的概率即 状态$s_i$生成观测值$o_j$的概率

*   初始状态概率：$\textbf{π} =\{\pi_1,\pi_2,...,\pi_N\}$，其中

    ​	$\pi_i = P(q_1=s_i)$                                  ，$1\leqslant i \leqslant N$

    表示模型初始状态选择某个状态为$s_i$的概率。

$HMM$ 参数$\lambda  = (\mathcal{S},\mathcal{O},\mathbf{A},\mathbf{B},\textbf{π})$ 简记为$(\mathbf{A},\mathbf{B},\textbf{π})$ 

#### 练习1

假设有状态空间$\mathcal{Y} = \{y_1,y_2,y_3\}$,$K$种隐状态 ,求$P(y_1,y_2,y_3)$ ,例如求未来股市的涨跌情况。

#### 解：

​	$$ \displaystyle P(y_1,y_2,y_3)=\sum_{q_1=1}^K \sum_{q_2=1}^K\sum_{q_3=1}^KP(y_1,y_2,y_3,q_1,q_2,q_3)$$

​	$$P(y_1,y_2,y_3,q_1,q_2,q_3) = P(y_3 \ | \ y_1,y_2,q_1,q_2,q_3) \times P(y_1,y_2,q_1,q_2,q_3)$$

​						 $=P(y_3 \ | \ q_3) \times P(y_1,y_2,q_1,q_2,q_3)$

​						 $=P(y_3 \ | \ q_3) \times P(q_3 \ | \ y_1,y_2,q_1,q_2)  \times P(y_1,y_2,q_1,q_2)$

​						 $=P(y_3 \ | \ q_3) \times P(q_3 \ | \ q_2) \times P(y_2 \ |\ q_2) \times P(q_2 \ | \ q_1) \times P(y_1 \ | \ q_1) \times P(q_1)$

​	$$ \displaystyle P(y_1,y_2,y_3)=\sum_{q_1=1}^K \sum_{q_2=1}^K\sum_{q_3=1}^KP(y_3 \ | \ q_3)  P(q_3 \ | \ q_2)  P(y_2 \ |\ q_2)  P(q_2 \ | \ q_1)  P(y_1 \ | \ q_1)P(q_1)$$

​				$\displaystyle =\sum_{q_1=1}^K \sum_{q_2=1}^K\sum_{q_3=1}^K \pi(q_1)\prod_{i=2}^3P(q_i \ | \ q_{i-1})P(y_i \ | \ q_{i})$

​		                $\displaystyle =\sum_{q_1=1}^K \sum_{q_2=1}^K\sum_{q_3=1}^K \pi(q_1)\prod_{i=2}^3\mathbf{A}_{s_{i-1},s_i}\mathbf{B}_{s_i,y_i}$



### $HMM$ 三个基本问题

1.  ###### 评估问题(Evalution)

    给定模型$\lambda  = (\mathbf{A},\mathbf{B},\textbf{π})$,如何有效计算其产生的观测序列$\mathcal{O}=\{o_1,o_2,...,o_N\}$的概率即$P(\mathcal{O \ | \lambda})$，评估模型与观测序列之间的匹配度。使用$EM$算法的特列：前向-后向算法简化计算

2.  ###### 学习问题(Learning)

    即如何在已知观测序列$\mathcal{O}$下，估计模型参数$\lambda$，使得$P(\mathcal{O} \ | \ \lambda)$最大，即$\underset{\lambda}{arg \max}P(O \ | \ \lambda)$

    即如何训练模型使其能更好描述观地测数据。

    使用$Baum-Welch$算法解决学习问题

3.  ###### 解码问题(Decoding)

    给定模型$\lambda  = (\mathbf{A},\mathbf{B},\textbf{π})$ 和观测序列$\mathcal{O}$ ，如何找到与此匹配的状态序列$\mathcal{Q}$ ，如何根据观测序列推出隐藏的模型状态。

    使用$Viterbi$算法解决。



#### 练习：概率计算，求观测序列$P(\mathcal{O} \ | \ \lambda)$

#### 解：

​	$P(\mathcal{O} \ | \ \lambda)=P(y_1,y_2,...,y_T \ | \ \lambda)$

​			 $$\displaystyle =\sum_{q_1=1}^K···\sum_{q_T=1}^KP(y_1,y_2,...,y_T,q_1,q_2,...,q_T \ | \ \lambda)$$

​			 $\displaystyle =\sum_{q_1=1}^K···\sum_{q_T=1}^K \pi(q_1)\prod_{i=2}^TP(q_i \ | \ q_{i-1})P(y_i \ | \ q_i)$

​			 $\displaystyle =\sum_{q_1=1}^K···\sum_{q_T=1}^K \pi(q_1)\prod_{i=2}^T\mathbf{A_{q_{i-1},q_i}} \cdot \mathbf{B}_{q_i,y_i}$

上述计算量$K^T*\sum$

![FBpic](C:\Users\Tongyu\Pictures\Saved Pictures\FBpic.png)

使用$Forward  \ Algorithm$优化计算量到$K*T$（$K$为状态数）

**定义** $\alpha_i(t) = P(y_1,y_2,...,y_t,q_t=s_i \ | \ \lambda)$ ($t$时刻下隐状态为$i$在前向观测下的联合概率)

-   有 $\alpha_i(1)=P(y_1,q_1=s_i) $

    ​		$= P(y_1 \ | \ q_1=s_i)\cdot P(q_1)$ 

    ​		$=\mathbf{B}_{q_1,y_1} \times \pi(q_1)$

-   有$\alpha_j(2) =P(y_1,y_2,q_2=s_j \ | \ \lambda)$ 

    ​	       $\displaystyle =\sum_{i=1}^KP(y_1,y_2,q_1=s_i,q_2=s_j)$ 

    ​	       $\displaystyle =\sum_{i=1}^KP(y_2\ | \ q_2=s_j) \times P(q_2=s_j \ | \ q_1=s_i) \times P(y_1,q_1=s_i)$

    ​	      $\displaystyle =\sum_{i=1}^KP(y_2\ | \ q_2=s_j) \times P(q_2=s_j \ | \ q_1=s_i) \times \alpha_i(1)$ 

    ​	      $\displaystyle =P(y_2 \ | \ q_2=s_j)\sum_{i=1}^K\{P(q_2=s_j \ | \ q_1 = s_i) \times \alpha_i(1)\}$ 

    ​	      $\displaystyle=\mathbf{B}_{j,y_2}\sum_{i=1}^K\mathbf{A}_{s_i,s_j}\alpha_i(1)$

$\displaystyle\Rightarrow \alpha_j(T)=\mathbf{B}_{j,y_T}\sum_{i=1}^K{\mathbf{A}_{i,j}\alpha_i(T-1)}$

而$\displaystyle P(y_1,y_2,...,y_T \ | \ \lambda)=\sum_{j=1}^K\alpha_j(T)$ 故只需要计算$K*T$次即可求得观测序列概率

$backward \ algorithm$ 求在$t$时刻的状态处于隐藏下时$t+1$时刻到最终时刻$T$的观测序列的概率

$\beta_i(t)=P(y_{t+1},y_{t+2},...,y_t \ | \ q_t=s_i,\lambda )$

有$\beta_i(1)=P(y_2,y_3,...,y_T \ | \ q_1=s_i)$

​	      $=P()$

### Viterbi Algorithm

*   寻找最有可能产生观测事件序列的Viterbi path——隐含状态序列

    $HMM$状态空间$\mathcal{S}$有$k$个状态,初始状态为$i$的概率为$\pi_i$

    状态$i$到状态$j$的转移概率为$\mathbf{A}_{i,j}$







































[^1]: 时间和状态都是离散的马尔可夫过程称为马尔科夫链

