# DVWA之暴力破解攻击

## 一、课程介绍
### 1.1 内容简介

所谓的暴力破解攻击就是攻击者无限次尝试用户名和密码，试图登录网站。如果攻击者无限次的尝试，肯定会把密码尝试出来，所以我们只能把代码写好，尽可能防止这种情况的发生。另外建议朋友们把密码设的复杂一些，这样就会给攻击者增加破解难度。

Burp Suite 是用于攻击web应用程序的集成平台。它包含了许多工具，并为这些工具设计了许多接口，以促进加快攻击应用程序的过程。所有的工具都共享一个能处理并显示HTTP 消息，持久性，认证，代理，日志，警报的一个强大的可扩展的框架。
### 1.2 课程知识点

本课程项目完成过程中将学习：

1. 网站帐号密码暴力破解的方法与原理
2. burpsuite的安装和使用
3. dvwa的部署和使用

## 二、实验准备
### 2.1 部署并设置dvwa
课程已经从dvwa官网下载并添加了简单的部署脚本，按照以下步骤部署dvwa到实验楼环境中:

```
$ wget http://labfile.oss.aliyuncs.com/courses/645/dvwa_deploy.tar.gz
$ tar -zxvf dvwa_deploy.tar.gz
$ sudo apt-get update 
$ ./deploy.sh
```
接着打开浏览器，在地址栏输入localhost/dvwa/setup.php访问初始设定页面，点击图中的按钮初始化数据库。

![此处输入图片的描述](https://dn-anything-about-doc.qbox.me/document-uid8623labid2393timestamp1481181007920.png/wm)

初始化成功后的结果如下：

![此处输入图片的描述](https://dn-anything-about-doc.qbox.me/document-uid8623labid2393timestamp1481181009890.png/wm)

初始化之后，页面将跳转到登录页，输入默认用户名admin和密码password登入系统。

![此处输入图片的描述](https://dn-anything-about-doc.qbox.me/document-uid8623labid2393timestamp1481181010079.png/wm)

下一步需要设置dvwa系统的难度级别，由于它是一个专门的演练系统，因此针对不同的使用场景设计了4种攻击难度级别：

| 难度级别| 说明| 
| ------------ |:-------------:|
| Low       | 低难度，系统未采取任何安全防御措施|
| Medium       | 中级难度，系统有一定的防御手段，但仍然可被利用|
| High       | 难度提升，有更强力的安全措施，但仍有可利用的弱点|
| Impossible       | 几乎没有任何可利用的漏洞，可用来当做对比的正确范本|


登入系统后，点击DVWA Security选项即可看到设置页面。将难度设置为low之后，点击submit让设置生效。有兴趣的同学也可以设置中高难度来学习和练习一些passby技巧。

注意：需为文件分配权限后点击submit才能完成修改。
```
chmod -R 777 /var/www/html/dvwa/
```
![此处输入图片的描述](https://dn-anything-about-doc.qbox.me/document-uid8623labid2393timestamp1481181010462.png/wm)

###2.2 安装burpsuite
下载burpsuite
```
wget http://labfile.oss.aliyuncs.com/courses/726/burpsuite_free.jar
```

![此处输入图片的描述](https://dn-anything-about-doc.qbox.me/document-uid8623labid2393timestamp1481182444536.png/wm)

启动burpsuite(一路默认next然后start burp即可启动)

```
/usr/bin/java -Xmx2g  -jar  burpsuite_free.jar
```
![此处输入图片的描述](https://dn-anything-about-doc.qbox.me/document-uid8623labid2393timestamp1481182877249.png/wm)

##三、实验步骤
###漏洞利用 LOW
####1、暴力破解
因为burp无法抓取本地包，所以我们不能使用localhost或127.0.0.1这样来访问网站抓包破解。先看看ubuntu的ip地址是多少，这里实验机的是192.168.42.2，所以首先我们使用http://192.168.42.2/dvwa/ 登录网站后选择low级别后，再来到Brute Force

![此处输入图片的描述](https://dn-anything-about-doc.qbox.me/document-uid8623labid2393timestamp1481184257211.png/wm)
![此处输入图片的描述](https://dn-anything-about-doc.qbox.me/document-uid8623labid2393timestamp1481184875965.png/wm)

我们的目的就是对这个页面的密码进行暴力破解得到正确的密码
先来看看low级别的服务端代码
```
<?php
if( isset( $_GET[ 'Login' ] ) ) {
	// Get username
	$user = $_GET[ 'username' ];
	// Get password
	$pass = $_GET[ 'password' ];
	$pass = md5( $pass );
	// Check the database
	$query  = "SELECT * FROM `users` WHERE user = '$user' AND password = '$pass';";
	$result = mysql_query( $query ) or die( '<pre>' . mysql_error() . '</pre>' );
	if( $result && mysql_num_rows( $result ) == 1 ) {
		// Get users details
		$avatar = mysql_result( $result, 0, "avatar" );
		// Login successful
		$html .= "<p>Welcome to the password protected area {$user}</p>";
		$html .= "<img src=\"{$avatar}\" />";
	}
	else {
		// Login failed
		$html .= "<pre><br />Username and/or password incorrect.</pre>";
	}
	mysql_close();
}
?>
```
可以看到，服务器只是验证了参数Login是否被设置（isset函数在php中用来检测变量是否设置，该函数返回的是布尔类型的值，即true/false），没有任何的防爆破机制，且对参数username、password没有做任何过滤，存在明显的sql注入漏洞。

接下来就准备进行暴力破解，先需要在浏览器上设置本地burp代理，在浏览器中输入about:preferences#advanced

然后选择网络，点击设置

![此处输入图片的描述](https://dn-anything-about-doc.qbox.me/document-uid8623labid2393timestamp1481181012612.png/wm)

在弹出来的连接设置对话框中选择手动配置代理，填写127.0.0.1和8080端口(burp代理默认使用8080端口)，然后点击确定。

![此处输入图片的描述](https://dn-anything-about-doc.qbox.me/document-uid8623labid2393timestamp1481187581844.png/wm)

这时候打开burp来到proxy选项下的Options，可以看到burp默认使用的8080端口，当然这个代理端口也可以自己修改。

![此处输入图片的描述](https://dn-anything-about-doc.qbox.me/document-uid8623labid2393timestamp1481181013949.png/wm)

一切准备就绪后，在页面登录框中输入帐号admin密码123，并点击login。
这时候可以看到页面一直未响应，而且在burp的Proxy下的intercept选项下抓到了请求包。

![此处输入图片的描述](https://dn-anything-about-doc.qbox.me/document-uid8623labid2393timestamp1481185314450.png/wm)

然后使用快捷键 ctrl+i (先得选中抓到的包内容再按快捷键)将burp抓到的包送到Intruder模块，这个模块用来暴力破解的。点击burp上的Intruder就来到了该模块，在Positions下可以看见发送过来的包

![此处输入图片的描述](https://dn-anything-about-doc.qbox.me/document-uid8623labid2393timestamp1481185407281.png/wm)

可以看到在intruder模块里，给很多变量的值加上了两个$$符号，加上$$符号的意思就是要爆破该变量，在这里我们已知用户名为admin，所以我们只需要爆破密码，就要把一些不相关的变量清除。点击burp右边的Clear$，然后选中password后面的123再点击Add$，给password增加两个$$符号用来声明等下爆破该变量。

![此处输入图片的描述](https://dn-anything-about-doc.qbox.me/document-uid8623labid2393timestamp1481185564417.png/wm)

接下来需要准备一个密码本用来爆破，网上有很多密码本，大家可以自行测试，这里可以简单准备一个密码本，每行一个密码，保存为txt格式。

![此处输入图片的描述](https://dn-anything-about-doc.qbox.me/document-uid8623labid2393timestamp1481185737360.png/wm)

然后再来到Payloads选项下，在下图1处载入密码本，然后在2出点击start attck，即可开始暴力破解，破解结果如下图3处，可以看到密码为password时，响应长度为5329与其他的密码的响应长度不一样，所以可以确定正确的密码就是password了。

![此处输入图片的描述](https://dn-anything-about-doc.qbox.me/document-uid8623labid2393timestamp1481185865302.png/wm)

这个时候返回Proxy选项下将点击一下Intercept is on 将其设置为 Intercept is off，这样就暂时关闭burp代理了。

![此处输入图片的描述](https://dn-anything-about-doc.qbox.me/document-uid8623labid2393timestamp1481185977141.png/wm)

在浏览器中使用admin和password登录成功。

![此处输入图片的描述](https://dn-anything-about-doc.qbox.me/document-uid8623labid2393timestamp1481181015658.png/wm)

####2、SQL注入
之前分析过了，在这个low级别的页面也是存在sql注入漏洞的，可以使用
帐号admin’#   密码为空进行登录，同样可以登录成功。
当使用这个帐号登录的时候，进行数据库查询的语句为

```
$query  = "SELECT * FROM `users` WHERE user = 'admin'#' AND password = '$pass';"
```
可以看到，admin’#的一个‘闭合了前面的’，而#是注释的意思，把后面的语句注释掉，自然也就执行成功了。


###漏洞利用 Medium
```
<?php
if( isset( $_GET[ 'Login' ] ) ) {
	// Sanitise username input
	$user = $_GET[ 'username' ];
	$user = mysql_real_escape_string( $user );
	// Sanitise password input
	$pass = $_GET[ 'password' ];
	$pass = mysql_real_escape_string( $pass );
	$pass = md5( $pass );
	// Check the database
	$query  = "SELECT * FROM `users` WHERE user = '$user' AND password = '$pass';";
	$result = mysql_query( $query ) or die( '<pre>' . mysql_error() . '</pre>' );
	if( $result && mysql_num_rows( $result ) == 1 ) {
		// Get users details
		$avatar = mysql_result( $result, 0, "avatar" );
		// Login successful
		$html .= "<p>Welcome to the password protected area {$user}</p>";
		$html .= "<img src=\"{$avatar}\" />";
	}
	else {
		// Login failed
		sleep( 2 );
		$html .= "<pre><br />Username and/or password incorrect.</pre>";
	}
	mysql_close();
}
?>
```
相比Low级别的代码，Medium级别的代码主要增加了mysql_real_escape_string函数，这个函数会对字符串中的特殊符号（x00，n，r，，’，”，x1a）进行转义，基本上能够抵御sql注入攻击，说基本上是因为查到说 MySQL5.5.37以下版本如果设置编码为GBK，能够构造编码绕过mysql_real_escape_string 对单引号的转义；同时，$pass做了MD5校验，杜绝了通过参数password进行sql注入的可能性。但是，依然没有加入有效的防爆破机制（sleep(2)实在算不上）。
虽然sql注入不再有效，但依然可以使用Burpsuite进行爆破，与Low级别的爆破方法基本一样，这里就不赘述了。
##四、总结

通过上面的实验我们了解了暴力破解的攻击方法，那么针对暴力破解我们该如何进行防御呢?

1、可以在登录界面使用验证码，因为验证码的随机性，可以抵挡大部分攻击者，但是验证码这个东西也有两面性，如果做得太low，会被攻击者编写脚本识别出来，如果做得太high，就会造成用户体验差，比如12306。

2、可以设置登录错误次数限制,超过这个次数就不能输入，比如各大网银。

3、设置一个足够复杂的密码。

</textarea>