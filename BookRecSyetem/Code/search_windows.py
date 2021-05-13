from PyQt5.QtWidgets import QWidget
from PyQt5.QtCore import pyqtSignal, Qt
from PyQt5.QtWidgets import QApplication    # 登陆窗口类
import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from util.common_util import msg_box
from UserManagement import user_management
from PyQt5.QtWidgets import QTableWidgetItem

import pymysql
from ui.search import Ui_Form
import re
from detial_book import book_detial


class search(Ui_Form, QWidget):
    def __init__(self, username=None):
        super(search, self).__init__()
        self.setupUi(self)
        self.init_ui()
        self.init_slot()
        self.username = username
        self.detial = None
        self.show_detial()


    def init_ui(self):
        self.setWindowTitle("书籍搜索")

    def init_slot(self):
        self.pushButton_book.clicked.connect(lambda :self.bin_slot('book'))
        self.pushButton_author.clicked.connect(lambda: self.bin_slot('author'))


    def bin_slot(self, tag):
        if tag == 'book':
            self.update_table_book()
        if tag == 'author':
            self.update_table_author()

    def fuzzy_finder_book(self, input):
        conn = pymysql.connect(
            host="localhost",
            user="root",
            password="123456",
            database="test",
            charset="utf8"
        )
        cursor = conn.cursor()
        # 获取书籍名字
        sql = "SELECT `book_name` FROM `douban_book_release`"
        cursor.execute(sql)
        book_name = []
        books = cursor.fetchall()
        conn.close()
        for book in books:
            book_name.append(book[0])

        search_book = []
        pattern = '.*?'.join(input)
        regex = re.compile(pattern)
        for book in book_name:
            match = regex.search(book)
            if match:
                search_book.append((len(match.group()), match.start(), book))

        return [x for _, _, x in sorted(search_book)]

    def fuzzy_finder_author(self, input):
        '''
        模糊搜索作者
        return list
        '''
        conn = pymysql.connect(
            host="localhost",
            user="root",
            password="123456",
            database="test",
            charset="utf8"
        )
        cursor = conn.cursor()
        # 获取书籍名字
        sql = "SELECT * FROM `douban_book_release`"
        cursor.execute(sql)
        author_all = []
        authors = cursor.fetchall()
        conn.close()
        for author in authors:
            author_all.append(author[1])

        search_author = []
        pattern = '.*?'.join(input)
        regex = re.compile(pattern)
        for author in author_all:
            match = regex.search(author)
            if match:
                search_author.append((len(match.group()), match.start(), author))

        return [x for _, _, x in sorted(search_author)]

    def search_book(self):
        input = self.lineEdit.text()
        # print(input)
        result = self.fuzzy_finder_book(input)

        # print(result)
        return result

    def update_table_book(self):
        books_name = self.search_book()
        if len(books_name) == 0:
            msg_box(self, ' 提示', '搜索失败，书库中没有此书')
        # 获取书籍的其余信息
        # print(books_name)
        conn = pymysql.connect(
            host="localhost",
            user="root",
            password="123456",
            database="test",
            charset="utf8"
        )
        cursor = conn.cursor()
        books = []
        for book_name in books_name:
            print(book_name)
            sql = "SELECT * FROM `douban_book_release` WHERE `book_name`='%s'" % (book_name)
            cursor.execute(sql)
            data = cursor.fetchall()
            book = data[0]
            name = book[0]
            author = book[1]
            score = book[4]
            rating_num = book[5]
            print([name, author, score, rating_num])
            books.append([name, author, score, rating_num])


        row_num = len(books)
        self.tableWidget.setRowCount(row_num)
        for row in range(row_num):
            self.tableWidget.setItem(row, 0, QTableWidgetItem(books[row][0]))   # book_name
            self.tableWidget.setItem(row, 1, QTableWidgetItem(books[row][1]))   # author
            self.tableWidget.setItem(row, 2, QTableWidgetItem(str(books[row][2])))   # score
            self.tableWidget.setItem(row, 3, QTableWidgetItem(str(books[row][3])))   # rating_num
        msg_box(self, '提示', '搜索成功,匹配到%d本书' % (row_num))

    def update_table_author(self):
        input = self.lineEdit.text()
        authors = self.fuzzy_finder_author(input)
        authors = set(authors)  #   转化成集合
        print(authors)
        conn = pymysql.connect(
            host="localhost",
            user="root",
            password="123456",
            database="test",
            charset="utf8"
        )
        cursor = conn.cursor()
        # search_book = []
        books_name = []
        for author in authors:
            sql = "SELECT * FROM `douban_book_release` WHERE `author` = '%s'" % (author)
            cursor.execute(sql)
            data = cursor.fetchall()
            book_num = len(data)
            # 获取书名
            for num in range(book_num):
                books_name.append(data[num][0])

        books = []
        for book_name in books_name:
            # print(book_name)
            sql = "SELECT * FROM `douban_book_release` WHERE `book_name`='%s'" % (book_name)
            cursor.execute(sql)
            data = cursor.fetchall()
            book = data[0]
            name = book[0]
            author = book[1]
            score = book[4]
            rating_num = book[5]
            # print([name, author, score, rating_num])
            books.append([name, author, score, rating_num])
        conn.close()
        row_num = len(books)
        self.tableWidget.setRowCount(row_num)
        for row in range(row_num):
            self.tableWidget.setItem(row, 0, QTableWidgetItem(books[row][0]))  # book_name
            self.tableWidget.setItem(row, 1, QTableWidgetItem(books[row][1]))  # author
            self.tableWidget.setItem(row, 2, QTableWidgetItem(str(books[row][2])))  # score
            self.tableWidget.setItem(row, 3, QTableWidgetItem(str(books[row][3])))  # rating_num
        msg_box(self, '提示', '搜索成功,匹配到%d本书' % (row_num))


    def show_detial(self):
        self.tableWidget.cellPressed.connect(self.getPosContent)

    def getPosContent(self, row, col):
        try:
            content = self.tableWidget.item(row, 0).text()
            self.details = book_detial(self.username, content)
            self.details.show()
        except:
            return



if __name__ == "__main__":
    app = QApplication(sys.argv)
    win = search('admin')
    win.show()
    sys.exit(app.exec_())




