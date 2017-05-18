import requests
from lxml import html
import os
import time


# 获取主页列表
def getPage(pageNum):
    baseUrl = 'http://www.mzitu.com/page/{}'.format(pageNum)
    selector = html.fromstring(requests.get(baseUrl).content)
    urls = []
    for i in selector.xpath('//ul[@id="pins"]/li/a/@href'):
        urls.append(i)
    return urls


# 图片链接列表， 标题
# url是详情页链接
def getPiclink(url):
    sel = html.fromstring(requests.get(url).content)
    # 图片总数
    total = sel.xpath('//div[@class="pagenavi"]/a[last()-1]/span/text()')[0]
    print(total)
    # 标题
    title = sel.xpath('//h2[@class="main-title"]/text()')[0]
    # 接下来的链接放到这个列表
    jpgList = []
    for i in range(int(total)):
        # 每一页
        link = '{}/{}'.format(url, i + 1)
        s = html.fromstring(requests.get(link).content)
        # 图片地址在src标签中
        jpg = s.xpath('//div[@class="main-image"]/p/a/img/@src')[0]
        # 图片链接放进列表
        jpgList.append(jpg)
        downloadPic(title, jpgList)


# 下载图片
def downloadPic(title, piclist):
    k = 1
    # 图片数量
    count = len(piclist)
    # 文件夹格式
    dirName = u"【%sP】%s" % (str(count), title)
    # 新建文件夹
    os.mkdir(dirName)
    for i in piclist:
        # 文件写入的名称：当前路径／文件夹／文件名
        filename = '%s/%s/%s.jpg' % (os.path.abspath('.'), dirName, k)
        print(u'开始下载图片:%s 第%s张' % (dirName, k))
        with open(filename, "w+") as jpg:
            jpg.write(str(requests.get(i).content))
            time.sleep(0.5)
        k += 1


if __name__ == '__main__':
    pageNum = input(u'请输入页码：')
    for link in getPage(pageNum):
        getPiclink(link)
