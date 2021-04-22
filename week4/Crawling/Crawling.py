#!/usr/bin/env python
# coding: utf-8

# In[1]:


import lxml
import pymysql
from urllib.request import urlopen
import requests
from lxml import etree
import urllib
import html
import time
import random
import http
import re


# In[2]:


# 登陆来爬取
def login_douban():
    login_url= 'https://accounts.douban.com/j/mobile/login/basic'
    data={'name':'########',
          'password': '###########',
          'remember': 'false'}
    headers={'Cookie':'ll="118281"; bid=6k4D4UvewhU; gr_user_id=b057d2a7-2726-4d47-9486-25044db1c016; _pk_ref.100001.2fad=%5B%22%22%2C%22%22%2C1618933620%2C%22https%3A%2F%2Fsec.douban.com%2F%22%5D; _pk_id.100001.2fad=99b2f2328cefa0be.1618933620.1.1618934723.1618933620.; push_doumail_num=0; __utmv=30149280.14442; push_noty_num=0; ap_v=0,6.0; __gads=ID=9a0f946ac5a01053:T=1619002297:S=ALNI_MYjRvk8BUpqPhYL3rbIzPNMiQaJJQ; __utma=30149280.860125068.1618913183.1619002280.1619009283.8; __utmc=30149280; __utmz=30149280.1619009283.8.6.utmcsr=baidu|utmccn=(organic)|utmcmd=organic; __utmt=1; apiKey=; __utmb=30149280.3.10.1619009283; login_start_time=1619009317128',
           'Referer': 'https://accounts.douban.com/passport/login_popup?login_source=anony',
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.128 Safari/537.36'}
    try:
        res = requests.post(login_url,headers=headers,data=data)
        res.raise_for_status()
    except:
        print("登陆失败")
    print(res.text)
login_douban()


# In[3]:


conn = pymysql.connect(  # 连接本地数据库
    host="localhost",
    user="root",
    password="9834459687", # 填上自己的密码
    database="test",
    charset="utf8"
)
conn.set_charset('utf8')#设置编码
cursor = conn.cursor()  # 得到一个可以执行SQL语句的光标对象

#cursor.execute("DROP TABLE IF EXISTS DouBanTop250LAST2") # 如果表存在则删除


# In[4]:


sql = """
    CREATE TABLE DouBanTop250LAST2 (
    `id` INT auto_increment PRIMARY KEY ,
    `MovieRank` VARCHAR(10) NOT NULL,
    `MovieTitle` VARCHAR(255) NOT NULL,
    `MovieType` VARCHAR(255),
    `Year` VARCHAR(10),
    `OtherTitle` VARCHAR(255),
    `MovieQuote` VARCHAR(255),
    `MovieStar` VARCHAR(255) ,
    `MovieScore`VARCHAR(10) ,
    `evaluateNum` VARCHAR(50),
    `Directer` VARCHAR(255),
    `MoiveURL` VARCHAR(255) ,
    `ImageURL` VARCHAR(255),
    `Summary` MEDIUMTEXT)
"""
try:
    cursor.execute(sql) # 执行创建表操作
except Exception as e:
    print(e)
    # 发生错误则回滚
    conn.rollback()
conn.close()


# In[5]:


# 在电影界面中获取简介和导演信息
def getData(url):
    Data = {}
    headers={'Cookie':'ll="118281"; bid=6k4D4UvewhU; gr_user_id=b057d2a7-2726-4d47-9486-25044db1c016; _pk_ref.100001.2fad=%5B%22%22%2C%22%22%2C1618933620%2C%22https%3A%2F%2Fsec.douban.com%2F%22%5D; _pk_id.100001.2fad=99b2f2328cefa0be.1618933620.1.1618934723.1618933620.; push_doumail_num=0; __utmv=30149280.14442; push_noty_num=0; ap_v=0,6.0; __gads=ID=9a0f946ac5a01053:T=1619002297:S=ALNI_MYjRvk8BUpqPhYL3rbIzPNMiQaJJQ; __utma=30149280.860125068.1618913183.1619002280.1619009283.8; __utmc=30149280; __utmz=30149280.1619009283.8.6.utmcsr=baidu|utmccn=(organic)|utmcmd=organic; __utmt=1; apiKey=; __utmb=30149280.3.10.1619009283; login_start_time=1619009317128',
           'Referer': 'https://accounts.douban.com/passport/login_popup?login_source=anony',
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.128 Safari/537.36'}
    response = requests.get(url,headers=headers)
    time.sleep(random.randint(3,5)*3)
    content = response.text
    html = etree.HTML(content)
    Data['summary'] = "".join(html.xpath('//span[@property="v:summary"]/text()'))
    Data['summary'] = Data['summary'].replace(' ','')
    Data['summary'] = Data['summary'].replace('\u3000','')
    Data['Directer']="".join(html.xpath('//a[@rel="v:directedBy"]/text()'))
    return Data


# In[6]:


# 爬取信息和储存到数据库
def crawling(page_num):
    headers={'Cookie':'ll="118281"; bid=6k4D4UvewhU; gr_user_id=b057d2a7-2726-4d47-9486-25044db1c016; _pk_ref.100001.2fad=%5B%22%22%2C%22%22%2C1618933620%2C%22https%3A%2F%2Fsec.douban.com%2F%22%5D; _pk_id.100001.2fad=99b2f2328cefa0be.1618933620.1.1618934723.1618933620.; push_doumail_num=0; __utmv=30149280.14442; push_noty_num=0; ap_v=0,6.0; __gads=ID=9a0f946ac5a01053:T=1619002297:S=ALNI_MYjRvk8BUpqPhYL3rbIzPNMiQaJJQ; __utma=30149280.860125068.1618913183.1619002280.1619009283.8; __utmc=30149280; __utmz=30149280.1619009283.8.6.utmcsr=baidu|utmccn=(organic)|utmcmd=organic; __utmt=1; apiKey=; __utmb=30149280.3.10.1619009283; login_start_time=1619009317128',
           'Referer': 'https://accounts.douban.com/passport/login_popup?login_source=anony',
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.128 Safari/537.36'}
    url='https://movie.douban.com/top250?start=%d'%page_num
    time.sleep(random.randint(1,3)*2)
    response = requests.get(url,headers=headers)
    content = response.text
    html = etree.HTML(content)
    datas= html.xpath('//*[@id="content"]/div/div[1]/ol/li')
    
    for data in datas:
        rank = "".join(data.xpath('div/div[1]/em/text()'))
        title= "".join(data.xpath('div/div[2]/div[1]/a/span[1]/text()'))
        other_title="".join(data.xpath('div/div[2]/div[1]/a/span[3]/text()'))
        movie_type = "".join(data.xpath('div/div[2]/div[2]/p[1]/text()[2]'))
        
        # year
        year=re.search(r'\d(.*)',movie_type)
        year=year.group()
        year=year.split()
        year=year[0]
        
        # type
        movie_type=re.search(r'\/[\s\S]*',movie_type)
        movie_type=movie_type.group()

        
        
        star= "".join(data.xpath('./div/div[2]/div[2]/div/span[1]/@class'))
        score="".join(data.xpath('div/div[2]/div[2]/div/span[2]/text()'))
        #DireAndPer="".join(data.xpath('div/div[2]/div[2]/p[1]/text()[1]'))
        
        
        #DireAndPer=DireAndPer.replace('\xa0',' ')
        #DireAndPer=re.search(r'导演: (.*)',DireAndPer)
        #DireAndPer=DireAndPer.group()
        
        quote = "".join(data.xpath('div/div[2]/div[2]/p[2]/span/text()'))
        evaluteNum="".join(data.xpath('div/div[2]/div[2]/div/span[4]/text()'))
        movieURL = "".join(data.xpath('div/div[1]/a/@href'))
        imageURL= "".join(data.xpath('div/div[1]/a/img/@src'))
        Data = getData(movieURL)
        summary = Data['summary']
        # 导演
        directer = Data['Directer']
        
        # 打开数据库连接
        conn = pymysql.connect(  # 连接本地数据库
            host="localhost",
            user="root",
            password="9834459687", # 填上自己的密码
            database="test",
            charset="utf8"
        )
        # 使用cursor()方法获取操作游标 
        cursor = conn.cursor()
        # SQL 插入语句
        sql = """
        INSERT INTO `DouBanTop250LAST2`(`MovieRank`,`MovieTitle`,`MovieType`,`Year`,`OtherTitle`,`Directer`,`MovieStar`,`MovieScore`,`MovieQuote`,`evaluateNum`,`MoiveURL`,`ImageURL`,`Summary`)
          VALUES (%s, %s, %s, %s, %s, %s, %s, %s, %s, %s,%s,%s,%s)
          """
        data=[(rank,title,movie_type,year,other_title,directer,star,score,quote,evaluteNum,movieURL,imageURL,summary)]
        try:
            cursor.executemany(sql,data)
            conn.commit()
            print(('第 '+str(rank)+' 名的电影 《'+str(title)+'》 成功爬取！'))
        except Exception as e:
            print(e)
            # 发生错误则回滚
            conn.rollback()
        conn.close()


# In[7]:


num = 0
while(num<250):
    crawling(num)
    num = num + 25


# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:




