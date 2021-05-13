import UserManagement
import pandas as pd
import numpy as np
import math
from operator import itemgetter


class itemCF()
    def __init__(self):
        self.n_sim_user = 5
        self.n_rec_book = 5
        self.user_sim_matrix = {}
        self.book_count = 0
        self.data = {}
        self.userid=None
        self.get_id()




    def load_data(self, path):
        '''
        按行处理
        :param path:
        :return:
        '''
        with open(path, 'r', encoding='UTF-8') as f:
            for i, line in enumerate(f):
                if i == 0:
                    continue  # 删除第一行的无关数据
                line = line.strip('\n')
                yield line

    def set_data(self, path):
        '''
        读取txt文件中的数据
        :param path:
        :return:
        '''
        for line in self.load_data(path):
            userid, nickname, read_num, read_book_and_score = line.split('\t')  #txt中以制表符为分割
            # print(read_book_and_score)
            try:
                read_book_and_score1 = eval(read_book_and_score) # 数据转换成字典
                read_book_and_score2 = eval(read_book_and_score1) # 转换成字典
                self.data.setdefault(userid, {})
                for key, value in read_book_and_score2.items():
                    self.data[userid][key] = value
            except:
                print(userid+' is false')
                continue

    def item_sim(self):
        C = {}  # 书和书的共现矩阵
        N = {}  # 书被多少个用户阅读过
        for user,
