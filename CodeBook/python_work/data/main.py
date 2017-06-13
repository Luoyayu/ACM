import requests

test = input("欢迎使用网站状态查询程序，请输入网址并确保正确，例如https://baidu.com或http://acm.hdu.edu.cn，键入exit以退出\n")
while (True):
    if (test == "exit"):
        break
    try:
        var = requests.get(test)
        time = var.elapsed.microseconds / 10000
        code = requests.get(test).status_code

        print("Respond time: ", time, "ms")
        print("Statue code is: ", code)

        print("Website statue: ")
        if (time > 888):
            print("Opps! Time out!\n")
        elif (code == 200):
            print(test, " is normal!\n")
        elif (code == 503):
            print(test, "Service Unavailable!\n")
        elif (code == 111):
            print("Connection refused!\n")
        elif (code == 502 or code == 400):
            print("Bad Gateway!\n")
        elif (code == 404):
            print("Not Found!\n")
        elif (code >= 100 or code < 200):
            print("normal information!\n")
        elif (code == 408):
            print("Request Timeout\n")
    except (ConnectionError, ConnectionResetError):
        print("ConnectionError\n")
    test = input("请输入测试网址或exit：\n")
