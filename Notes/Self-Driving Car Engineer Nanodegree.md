## Self-Driving Car Engineer Nanodegree Program

1. *Calculate Camera Matrix and Distortion Coefficient*
2. 检查内参并把 *raw images* 变成 *gray images*
3. 利用 *Opencv* 阈值函数`threshold()`通过 *color transforms*, *gradients*等完成图像像素级分割提取车道线
4. 利用透视变换完成车道鸟瞰图变换
5. 检测车道像素，找到车道边界
6. 确定车道线曲率(*curvature*)和车辆相对与中心的位置
7. 将检测到测车道线边界转会到*original images*
8. 输出车道线边界的曲率和车辆相对中心的数值表示

#### ⚝1. 阈值化分割

​	从图像中提取我们的关注点

​	`threshold()`函数提供5种阈值化类型，均以该图为例![Threshold Binary](http://www.opencv.org.cn/opencvdoc/2.3.2/html/_images/Threshold_Tutorial_Theory_Base_Figure.png)

- #### 类型1：二进制阈值化

  - 阈值化函数$dst(x,y) =\left\{\begin{matrix} Val  \ \ \ \ \ \ src(x,y)>thresh\\ 0  \  \ \ \ \ \ \ \ \ \ \  \ \ \ \ \ \ \ otherwise\end{matrix}\right. $
  - 阈值化结果：![Threshold Binary](http://www.opencv.org.cn/opencvdoc/2.3.2/html/_images/Threshold_Tutorial_Theory_Binary.png)
  - 说明：对于大于给定的蓝色阈值线set为给定最大灰度值, 否则置零

- #### 类型2：反二进制阈值化

  - 与二进制阈值区别在最后的填充值相反，小于的置为最大灰度值
  - 阈值化结果![Threshold Binary](http://www.opencv.org.cn/opencvdoc/2.3.2/html/_images/Threshold_Tutorial_Theory_Binary_Inverted.png)

- #### 类型3：截断阈值化

  - 阈值函数$dst(x,y) =\left\{\begin{matrix} threshold  \ \ \ \ \ \ src(x,y)>thresh\\ src(x,y)  \  \ \ \ \ \ \ \ \ \ \  \ \ \ \ \ \ \ \  \ otherwise\end{matrix}\right. $
  - 阈值化结果：![Threshold Binary](http://www.opencv.org.cn/opencvdoc/2.3.2/html/_images/Threshold_Tutorial_Theory_Truncate.png)
  - 说明：大于阈值的置为阈值，否则保持

- #### 类型4：阈值化为0

  - 二进制阈值化中，对于大于给定阈值的保持，否则置零

- #### 类型5：反阈值化为0

  - 与阈值化为0相反，大于阈值的置零，小于的保持灰度值

`threshold<>`参数解释

> src_gray 输入的灰度图像地址
>
> dst 输出图像地址
>
> threshold_value 阈值
>
> max_BINARY_value 设定的最大灰度值(在二进制阈值化中)
>
> threshold_type 阈值化类型

