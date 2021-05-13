from PyQt5.QtWidgets import QWidget
from PyQt5.QtCore import pyqtSignal, Qt
from PyQt5.QtWidgets import QApplication
import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from util.common_util import msg_box
import pymysql
from pymysql.converters import escape_string
from ui.edit_book import Ui_Form

class edit_book_view(Ui_Form, QWidget):
    def __init__(self, username=None):
        super(edit_book_view, self).__init__()
        self.setupUi(self)
        self.username = username
        self.init_ui()
        self.init_slot()
        self.edit = None



    def init_ui(self):
        self.setWindowFlags(Qt.WindowCloseButtonHint | Qt.WindowMinimizeButtonHint)
        self.setWindowTitle("书籍修改")


    def init_slot(self):
        self.pushButton.clicked.connect(lambda :self.bin_slot('edit'))


    def bin_slot(self, tag):
        if tag == 'edit':
            self.edit_data()



    def edit_data(self):
        conn = pymysql.connect(
            host="localhost",
            user="root",
            password="123456",
            database="test",
            charset="utf8"
        )
        cursor = conn.cursor()
        sql = "SELECT * FROM `user_info` WHERE `Account` = '%s'" % (self.username)
        result = cursor.execute(sql)
        print(result)
        data = cursor.fetchall()
        data = data[0]
        books = data[3]
        # 转化成字典
        books = eval(books)


        old_book_name = self.lineEdit_0.text()
        new_book_name = self.lineEdit.text()
        author = self.lineEdit_2.text()
        score = self.lineEdit_3.text()
        key = list(books.keys())
        # print(key)
        if old_book_name not in key:
            msg_box(self, '提示', '书库中没有此书籍')
            return
        if new_book_name in key and new_book_name != old_book_name:
            msg_box(self, '提示', '书库中此书已存在')
            return
        if '' in [old_book_name, new_book_name, author, score]:
            msg_box(self, '提示', '输入不能为空')
            return
        try:
            score = float(score)
            if score > 10 or score < 0:
                msg_box(self, '提示', '评分范围为0-10')
                return
        except:
            msg_box(self, '提示', '评分输入错误，请重新输入')
            return
        del books[old_book_name]
        # print(books)
        books[new_book_name] = score
        # print(books)
        # to str
        books = str(books)
        books = escape_string(books)

        sql_2 = "UPDATE `user_info` SET `read_book_and_score`='%s' WHERE `Account` = '%s' " % (books, self.username)
        cursor.execute(sql_2)
        conn.commit()
        conn.close()
        msg_box(self, "提示", "书籍修改成功")



if __name__ =="__main__":
    app = QApplication(sys.argv)
    win = edit_book_view("admin")
    win.show()
    sys.exit(app.exec())
