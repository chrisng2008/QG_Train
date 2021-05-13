from ui.add_book import Ui_Form
from PyQt5.QtGui import QIcon
from PyQt5.QtWidgets import QWidget
from PyQt5.QtCore import pyqtSignal, Qt
from PyQt5.QtWidgets import QApplication    # 登陆窗口类
import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from util.common_util import msg_box
from UserManagement import user_management
from add import Add
from PyQt5.QtWidgets import QTableWidgetItem
import pymysql
from delete_book import Delete_book
from edit_book_view import edit_book_view


class Add_Book(Ui_Form, QWidget):
    # 登陆界面类构造函数，初始化类属性
    def __init__(self,username):
        super(Add_Book, self).__init__()
        self.setupUi(self)
        self.username=username
        self.init_ui()
        self.init_slot()
        self.add = None
        self.edit = None
        self.delete = None
        self.update_table()

    def init_ui(self):
        self.setWindowTitle('书籍管理')


    def init_slot(self):
        self.add_button.clicked.connect(lambda :self.slot_bin('add'))
        self.edit_button.clicked.connect(lambda: self.slot_bin('edit'))
        self.delete_button.clicked.connect(lambda: self.slot_bin('delete'))
        self.fresh_button.clicked.connect(lambda :self.slot_bin('fresh'))




    def slot_bin(self, tag):
        if tag == 'add':
            self.add = Add(self.username)
            self.add.show()

        if tag =='fresh':
            self.update_table()
            msg_box(self, '提示', '刷新列表成功')

        if tag == 'delete':
            self.delete = Delete_book(self.username)
            self.delete.show()

        if tag == 'edit':
            self.edit = edit_book_view(self.username)
            self.edit.show()



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
            books = data[0][3]  #字符串
            books=eval(books)
            books = [[book, score] for book, score in books.items()]
            # 获取作者
            # 在总表中核实
            row_num = len(books)
            for row in range(row_num):
                sql_1 = "SELECT * FROM `douban_book_release` WHERE book_name ='%s'" % (books[row][0])
                is_exist=cursor.execute(sql_1)
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




if __name__ == '__main__':
    app = QApplication(sys.argv)
    add_book = Add_Book('admin')
    add_book.show()
    sys.exit(app.exec_())


