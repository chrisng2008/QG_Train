from PyQt5.QtGui import QIcon
from PyQt5.QtWidgets import QWidget
from PyQt5.QtCore import pyqtSignal, Qt
from PyQt5.QtWidgets import QApplication    # 登陆窗口类
import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from util.common_util import msg_box
from UserManagement import user_management
from PyQt5.QtWidgets import QTableWidgetItem
import pymysql
from UserCF import UserCF
from ui.rec_book import Ui_Form
from pymysql.converters import escape_string
from detial_book import book_detial

class rec_book(Ui_Form,QWidget):
    def __init__(self, username=None):
        super(rec_book, self).__init__()
        self.setupUi(self)
        self.init_ui()
        self.username = username
        self.update_data()
        self.recommend_books = None
        self.update_table()
        self.myid = None
        self.show_detial()



    def init_ui(self):
        self.setWindowTitle('书籍推荐')


    def rec_book_name(self):

        user = UserCF(str(self.myid))
        self.recommend_books = user.recommend_book()
        # 获取书名
        book_name = []
        for book in self.recommend_books:
            name = book[0]
            book_name.append(name)
        return book_name


    def update_table(self):

        books_name = self.rec_book_name()
        # 连接数据库获取数据
        conn = pymysql.connect(
            host="localhost",
            user="root",
            password="123456",
            database="test",
            charset="utf8"
        )
        cursor = conn.cursor()  # 得到一个可执行的游标对象
        row_num = len(books_name)
        # print(books_name)
        book = []
        for row in range(row_num):
            sql = "SELECT * FROM `douban_book_release` WHERE `book_name`='%s' " % (books_name[row])
            is_exist = cursor.execute(sql)
            if is_exist == 0:
                continue
            data = cursor.fetchall()
            # print(data)
            book_name = books_name[row]
            author = data[0][1]
            score = data[0][4]
            year = data[0][3]
            rating_num = data[0][5]
            book.append([book_name, author, score, year, rating_num])

        row_num = len(book)
        self.tableWidget.setRowCount(row_num)
        for row in range(row_num):
            # print(book[row])
            self.tableWidget.setItem(row, 0, QTableWidgetItem(book[row][0]))
            self.tableWidget.setItem(row, 1, QTableWidgetItem(book[row][1]))
            self.tableWidget.setItem(row, 2, QTableWidgetItem(str(book[row][2])))
            self.tableWidget.setItem(row, 3, QTableWidgetItem(str(book[row][3])))
            self.tableWidget.setItem(row, 4, QTableWidgetItem(str(book[row][4])))


    def update_data(self):
        '''
        update or insert the data info from `user_info` to `douban_book_release`
        :return:None
        '''
        conn = pymysql.connect(  # 连接本地数据库
            host="localhost",
            user="root",
            password="123456",  # 填上自己的密码
            database="test",
            charset="utf8"
        )
        cursor = conn.cursor()
        sql = "SELECT * FROM `user_info` WHERE `Account`='%s'" % (self.username)
        cursor.execute(sql)
        data = cursor.fetchall()
        my_id = str(data[0][0])
        self.myid = data[0][0]
        nickname = data[0][1]
        books = data[0][3]
        # 获取read_num
        books_dict = eval(books)
        read_num = len(books_dict)
        # 存在则更新，不存在则插入
        sql_2 = "SELECT * FROM `douban_book_users` WHERE `id`='%s'" % (my_id)
        is_exist = cursor.execute(sql_2)
        if is_exist == 0:   # 不存在
            sql_3 = "INSERT INTO `douban_book_users`(`id`,`nickname`,`read_num`,`read_book_and_score`)VALUES (%s,%s,%s,%s)"
            info = [(my_id, nickname, read_num, books)]
            cursor.executemany(sql_3, info)
            conn.commit()
            conn.close()
        else:    #存在，更新
            books = escape_string(books)
            sql_3 = "UPDATE `douban_book_users` SET `read_num`='%s',`read_book_and_score`='%s' WHERE `id` = '%s' " % (read_num,books,my_id)
            cursor.execute(sql_3)
            conn.commit()
            conn.close()

    def show_detial(self):
        self.tableWidget.cellPressed.connect(self.getPosContent)

    def getPosContent(self, row, col):
        try:
            content = self.tableWidget.item(row, 0).text()
            self.details = book_detial(self.username, content)
            self.details.show()
        except:
            return


if __name__ =='__main__':
    app = QApplication(sys.argv)
    rec = rec_book('admin')
    rec.show()
    sys.exit(app.exec_())





