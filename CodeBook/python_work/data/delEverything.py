import os
print("注意以下操作请谨慎，基于系统的删除无法还原！")
start = input("开始吧,我的大刀已经饥渴难耐")
location = input("说真的请小心输入不包含引号的地址，否则呵呵\n")

type1 = input("客观删什么类型的文件？例如你可以输入 .o \n")

while (True):
    n = 0
    if (type1[0] != '.'):
        break

    for root, dirs, files in os.walk(location):
        for name in files:
            if (name.endswith(type1)):
                n += 1
                print("Python", n, "杀")
                os.remove(os.path.join(root, name))
    if (n == 0):
        print("没有该类型文件,仿佛在逗我!")
    else:
        print('团灭!')
    type1 = input("还要吗？请胡乱按键盘退出\n")

os.system("pause")
