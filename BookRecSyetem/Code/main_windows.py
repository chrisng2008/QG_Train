from PyQt5.QtGui import QIcon
from PyQt5.QtWidgets import QMainWindow, QMessageBox, QWidget,QLabel
import sys
from ui.mainwindows import Ui_MainWindow
from PyQt5.QtWidgets import QApplication
from PyQt5 import QtCore, QtGui, QtWidgets
import pymysql
from UserManagement import user_management
from operator import itemgetter
from PyQt5.QtWidgets import QTableWidgetItem
from add_book import Add_Book
from util.common_util import msg_box
from rec_book import rec_book
from detial_book import book_detial
from person import person
from search_windows import search

class main_windows(Ui_MainWindow, QMainWindow):
    def __init__(self, username, parent=None):
        super(main_windows, self).__init__()
        self.username = username
        self.setupUi(self)
        self.init_ui()
        self.set_hot_table()
        self.init_slot()
        self.add_win = None
        self.update_table()
        self.rec =None
        self.details = None
        self.show_detial()
        self.person = None
        self.search = None

        # self.resize(400, 200)


    def init_ui(self):
        self.setWindowTitle('图书推荐系统-Version_1.0 beta')
        _translate = QtCore.QCoreApplication.translate
        self.label_4.setText(_translate("MainWindow", "账户名称：%s" % self.username))
    #
    # # 数据库载入数据
    # def hot_book(self):
    #     conn = pymysql.connect(
    #         host="localhost",
    #         user="root",
    #         password="123456",
    #         database="test",
    #         charset="utf8"
    #     )
    #     cursor =conn.cursor()  # 得到一个可执行的游标对象

    def load_data(self, path):
        with open(path, 'r', encoding='UTF-8') as f:
            for i, line in enumerate(f):
                if i == 0:
                    continue    #删除第一行的无关数据
                line = line.strip('\n')
                yield line

    def set_data(self, path):
        data = {}
        for line in self.load_data(path):
            userid, nickname, read_num, read_book_and_score = line.split('\t')  # txt中以制表符为分割
            # print(read_book_and_score)
            try:
                read_book_and_score1 = eval(read_book_and_score)  # 数据转换成字典
                read_book_and_score2 = eval(read_book_and_score1)  # 转换成字典
                self.data.setdefault(userid, {})
                for key, value in read_book_and_score2.items():
                    data[userid][key] = value
            except:
                continue

        book_count = {}
        for userid,books in data.items():
            for book in books:
                if book not in book_count:
                    book_count.setdefault(book, 0)
                book_count[book] += 1

        return sorted(book_count.items(), key=itemgetter(1), reverse=True)[0:50]    # 推荐25本书

    def set_hot_table(self):
        user = user_management()
        hot_books = self.set_data(path='F://QG//最终考核//附件1//douban_book_users.txt')
        # self.tableWidget_2.setRowCount(25)
        conn = pymysql.connect(
                host="localhost",
                user="root",
                password="123456",
                database="test",
                charset="utf8"
            )
        cursor =conn.cursor()  # 得到一个可执行的游标对象
        sql = "SELECT * FROM `douban_book_release`"
        # sql = "SELECT * FROM {} WHERE {}= '{}' ".format('douban_book_release', 'book_name', book_name)
        cursor.execute(sql)
        data = cursor.fetchall()
        data = list(data)
        hot_books = sorted(data, key=itemgetter(5), reverse=True)[:50]
        row_num=len(hot_books)
        self.tableWidget_2.setRowCount(row_num)
        for row in range(row_num):
            self.tableWidget_2.setItem(row,0,QTableWidgetItem(hot_books[row][0]))
            self.tableWidget_2.setItem(row, 1, QTableWidgetItem(hot_books[row][1]))
            self.tableWidget_2.setItem(row, 2, QTableWidgetItem(str(hot_books[row][5])))
            self.tableWidget_2.setItem(row, 3, QTableWidgetItem(str(hot_books[row][4])))

    def init_slot(self):
        '''
        初始化信号槽
        :return: None
        '''
        self.add_book.clicked.connect(lambda :self.bin_slot('add'))
        self.rec_button.clicked.connect(lambda :self.bin_slot('rec_book'))
        self.person_button.clicked.connect(lambda :self.bin_slot('person'))
        self.search_button.clicked.connect(lambda :self.bin_slot('search'))
        self.fresh_button.clicked.connect(lambda :self.bin_slot('fresh'))

    def update_table(self):
        conn = pymysql.connect(
            host="localhost",
            user="root",
            password="123456",
            database="test",
            charset="utf8"
        )
        cursor = conn.cursor()  # 得到一个可执行的游标对象
        try:
            sql = "SELECT * FROM `user_info` WHERE Account ='%s'" % (self.username)
            cursor.execute(sql)
            data = cursor.fetchall()
            books = data[0][3]  # 字符串
            books = eval(books)
            books = [[book, score] for book, score in books.items()]
            # 获取作者
            # 在总表中核实
            row_num = len(books)
            for row in range(row_num):
                sql_1 = "SELECT * FROM `douban_book_release` WHERE book_name ='%s'" % (books[row][0])
                is_exist = cursor.execute(sql_1)
                if is_exist == 0:
                    author = None
                    score = books[row][1]
                    books[row].append(author)
                    continue
                data = cursor.fetchall()
                author = data[0][1]
                score = books[row][1]
                books[row].append(author)
            conn.close()
            self.tableWidget.setRowCount(row_num)
            for row in range(row_num):
                self.tableWidget.setItem(row, 0, QTableWidgetItem(books[row][0]))
                self.tableWidget.setItem(row, 1, QTableWidgetItem(books[row][2]))
                self.tableWidget.setItem(row, 2, QTableWidgetItem(str(books[row][1])))
        except:
            return
        cursor.close()


    def bin_slot(self, tag):
        if tag =='add':
            '''
            书籍管理
            '''
            self.add_win = Add_Book(self.username)
            self.add_win.show()

        if tag == 'fresh':
            self.update_table()
            msg_box(self, '提示', '刷新列表成功')


        if tag == 'rec_book':
            self.rec = rec_book(self.username)
            self.rec.show()

        if tag == 'person':
            self.person = person(self.username)
            self.person.show()

        if tag == 'search':
            self.search = search()
            self.search.show()




    def show_detial(self):
        self.tableWidget.cellPressed.connect(self.getPosContent)
        self.tableWidget_2.cellPressed.connect(self.getPosContent2)


    def getPosContent(self,row,col):
        try:
            content = self.tableWidget.item(row, 0).text()
            self.details = book_detial(self.username, content)
            self.details.show()
        except:
            return

    def getPosContent2(self, row, col):
        try:
            content = self.tableWidget_2.item(row, 0).text()
            self.details = book_detial(self.username, content)
            self.details.show()
        except:
            return

















if __name__ =='__main__':
    app = QApplication(sys.argv)
    win = main_windows('admin')
    # win.init_ui('chris')
    win.show()
    win.set_hot_table()
    sys.exit(app.exec_())



