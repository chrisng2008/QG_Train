import UserManagement
# import pandas as pd
# import numpy as np
import math
from operator import itemgetter
import pymysql

class UserCF():
    def __init__(self, id=None):
        self.id = id
        self.n_sim_user = 300
        self.n_rec_book = 200
        self.user_sim_matrix = {}
        self.book_count = 0
        self.data = {}
        self.set_data()
        self.calc_sim()

    # 通过本地IO流来读取数据
    # def load_data(self,path):
    #     with open(path, 'r', encoding='UTF-8') as f:
    #         for i, line in enumerate(f):
    #             if i == 0:
    #                 continue    #删除第一行的无关数据
    #             line = line.strip('\n')
    #             yield line
    #
    # def set_data(self, path):
    #     for line in self.load_data(path):
    #         userid, nickname, read_num, read_book_and_score = line.split('\t')  #txt中以制表符为分割
    #         # print(read_book_and_score)
    #         try:
    #             read_book_and_score1 = eval(read_book_and_score) # 数据转换成字典
    #             read_book_and_score2 = eval(read_book_and_score1) # 转换成字典
    #             self.data.setdefault(userid, {})
    #             for key, value in read_book_and_score2.items():
    #                 self.data[userid][key] = value
    #         except:
    #             print(userid+' is false')
    #             continue

    # 通过MySQL来读取数据
    def set_data(self):
        conn = pymysql.connect(  # 连接本地数据库
            host="localhost",
            user="root",
            password="123456",  # 填上自己的密码
            database="test",
            charset="utf8"
        )
        cursor = conn.cursor()
        # 读取数据
        sql = "SELECT `id`,`read_book_and_score` FROM `douban_book_users`"
        cursor.execute(sql)
        user_infos = cursor.fetchall()
        row_num = len(user_infos)
        for row in range(row_num):
            try:
                userid = user_infos[row][0]
                books = user_infos[row][1]
                books = eval(books)     # 转化成字典
                self.data.setdefault(userid, {})
                for book, score in books.items():
                    self.data[userid][book] = score
            except:
                userid = user_infos[row][0]
                books = user_infos[row][1]+'}'  # 补充缺失符号
                books = eval(books)
                self.data.setdefault(userid, {})
                for book, score in books.items():
                    self.data[userid][book] = score

    def printdata(self):
        for key, values in self.data.items():
            print(key)
            print(values)
            print('\n')

    def calc_sim(self):
        book_user = {}      # 构建一个 书-用户 的矩阵

        for userid, books in self.data.items():
            for book in books:  # 建立“物品—用户”的倒排表
                if book not in book_user:
                    book_user[book] = set()  # 设置一个没有重复的集合
                book_user[book].add(userid)     # 读过这本的书的用户
        self.book_count = len(book_user)
        print('书的数量是', self.book_count)

        # 构建用户两两对物品喜爱的矩阵
        for book, userids in book_user.items():
            # 统计阅读过本书的用户数量
            for user1 in userids:
                for user2 in userids:
                    if user1 == user2:
                        continue
                    self.user_sim_matrix.setdefault(user1, {})
                    self.user_sim_matrix[user1].setdefault(user2, 0)
                    self.user_sim_matrix[user1][user2] += 1
        print('建立用户-用户共同阅读书籍的矩阵成功！')

        # 相似度计算
        for user, related_user in self.user_sim_matrix.items():
            for value, count in related_user.items():
                self.user_sim_matrix[user][value] = count / math.sqrt(len(self.data[user]) * len(self.data[value]))
        print('计算相似度成功！')

    # 针对特定用户，找到最相似的用户，推荐k本书籍
    def recommend_book(self):
        sim_user_num = self.n_sim_user
        rec_book_num = self.n_rec_book

        rank = {}
        read_book = self.data[self.id]  # 特定userId 读过的书
        # 权重计算
        for user, factor in sorted(self.user_sim_matrix[self.id].items(), key=itemgetter(1), reverse=True)[0:sim_user_num]:
            for book in self.data[user]:
                if book in read_book:
                    continue
                rank.setdefault(book, 0)
                rank[book] += factor
        return sorted(rank.items(), key=itemgetter(1), reverse=True)[0:rec_book_num]

    def get_data(self):
        return self.data



if __name__ == '__main__':
    example = UserCF('1')
    rec_book = example.recommend_book()
    print(example.id =='1')
    print('推荐的书籍是', rec_book)
