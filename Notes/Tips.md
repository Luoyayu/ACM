### ***anaconda***
如遇到*anaconda-navigator*打开报错，在相应的*Prompt*中运行重置命令
`anaconda-navigator --reset`

### ***Latex***
1.  `\left\{\begin{matrix} XXX \\ XXX \end{matrix}\right.` 展示多行$\left\{\begin{matrix} XXX \\ XXX \end{matrix}\right.$

2.  `\left \{  \right \}` $\left \{  \right \}$

3.  `\begin{bmatrix} & \\  & \end{bmatrix}` 矩阵`\\`分割行 `&` 分割列 $\begin{bmatrix} x&x \\ x &x \end{bmatrix}​$

4.  一些希腊符号：$\alpha \beta \gamma \delta$          $\epsilon \varepsilon \zeta \eta $         $\theta \vartheta \iota \kappa$           $ \lambda \mu \nu \xi$            $ \pi \varpi \rho \varrho$                                         

    ​                           $\sigma \varsigma \tau \upsilon $        $\phi \varphi \chi \psi          $         $\omega \Gamma \Delta \Theta$      $ \Lambda \Xi \Pi \Sigma$          $ \Upsilon \Phi \Psi \Omega  $

5.  $\hat{x}$   ${x}''$  $\dot{x}$  $\bar{x}$  

### ***ubuntu***




### ***Windows***



### ***Opencv***



### ***python***

1. `# -*- coding: utf-8 -*-`  允许中文注释

2. glob模块用于文件路径名查找，通配符'?', '!', '*'

   `glob.glob` 返回所有匹配的文件路径的列表，参数pathname定义规则，通常在for循环中利用enimerate返回索引和值

   `glob.iglob` 单次返回路径

3. 可持久数据之模块pickle，将python数据结构序列化便于调用：

   建议用同类C实现的cPickle 

   函数：`dump(object)` 返回字符串包含pickle格式的对象；

   ​	 ` load(string)`返回包含在pickle字符串中的对象；

   ​	 ` dump(object, file) `将对象写到文件；

   ​	 ` load(file) `返回包含在pickle文件中的对象