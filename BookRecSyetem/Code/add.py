from PyQt5.QtWidgets import QWidget
from PyQt5.QtCore import pyqtSignal, Qt
from ui.add import Ui_Form
from PyQt5.QtWidgets import QApplication    # 登陆窗口类
import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from util.common_util import msg_box
from UserManagement import user_management
import pymysql
from pymysql.converters import escape_string

class Add(Ui_Form,QWidget):
    def __init__(self, username=None):
        super(Add, self).__init__()
        self.username = username
        self.setupUi(self)
        self.init_ui()
        self.init_slot()

    def init_ui(self):
        self.setWindowTitle('添加书籍')


    def init_slot(self):
        self.pushButton.clicked.connect(lambda :self.bin_slot('add'))




    def bin_slot(self, tag):
        if tag == 'add':
            book_name = self.lineEdit.text()
            book_author = self.lineEdit_2.text()
            book_score = self.lineEdit_3.text()

            if '' in [book_name, book_author, book_score]:
                msg_box(self, '提示', '输入不能为空，请重新输入')
                return
            # 将书籍插入数据库中
            # 连接数据库
            conn = pymysql.connect(
                host="localhost",
                user="root",
                password="123456",
                database="test",
                charset="utf8"
            )
            try:
                # 将用户读取的书取出来，转化成字典再插入
                sql_1 = "SELECT * FROM `user_info` WHERE Account = '%s'" % (self.username)
                cursor = conn.cursor()  # 得到一个可执行的游标对象
                cursor.execute(sql_1)
                user = cursor.fetchall()
                book = user[0][3]
                book = eval(book)
                # 判断是否存在
                key = list(book.keys())
                if book_name in key:
                    msg_box(self, '提示', '书库中已存在此书')
                    return

                try:
                    book_score = float(book_score)
                    if book_score>10 or book_score<0:
                        msg_box(self, '提示', '评分的范围为0-10')
                        return
                except:
                    msg_box(self, '提示', '评分输入错误，请重试')
                    return

                book[book_name] = book_score
                book = str(book)
                # 再存入数据库
                book = escape_string(book)
                sql_2 = "UPDATE `user_info` SET read_book_and_score='%s' WHERE Account='%s'" % (book, self.username)
                cursor.execute(sql_2)
                conn.commit()
                msg_box(self, '提示', '增加书籍成功')
            except:
                # 为空
                book = {}
                book_score = float(book_score)
                book[book_name] = book_score
                book = str(book)
                book = escape_string(book)
                sql = "UPDATE `user_info` SET read_book_and_score='%s' WHERE Account='%s'" % (book, self.username)
                cursor.execute(sql)
                conn.commit()
                msg_box(self, '提示', '增加书籍成功')
            cursor.close()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    add = Add('admin')
    add.show()
    sys.exit(app.exec_())
