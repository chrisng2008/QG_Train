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
from ui.delete_book import Ui_Form
from pymysql.converters import escape_string

class Delete_book(Ui_Form, QWidget):
    def __init__(self, username=None):
        super(Delete_book, self).__init__()
        self.username = username
        self.setupUi(self)
        self.init_ui()
        self.init_slot()

    def init_ui(self):
        self.setWindowTitle('删除书籍')


    def init_slot(self):
        self.delete_button.clicked.connect(lambda :self.bin_slot('delete'))


    def bin_slot(self,tag):
        if tag == 'delete':
            self.delete()




    def delete(self):
        book_name = self.lineEdit.text()

        conn = pymysql.connect(
            host="localhost",
            user="root",
            password="123456",
            database="test",
            charset="utf8"
        )
        cursor = conn.cursor()
        try:
            sql = "SELECT * FROM `user_info` WHERE `Account` ='%s'" % (self.username)
            cursor.execute(sql)
            data = cursor.fetchall()
            data = data[0]
            book = data[3]  # 字符串
            # 转化成字典
            books = eval(book)
            del books[book_name]
            books = str(books)
            books = escape_string(books)
            sql_2 = "UPDATE `user_info` SET `read_book_and_score`='%s' WHERE `Account`='%s'"%(books, self.username)
            cursor.execute(sql_2)
            conn.commit()
            conn.close()
            msg_box(self, '提示', '删除书籍成功')
        except:
            msg_box(self, '提示', '删除书籍错误，请检查后重新输入')











if __name__ == '__main__':
    app = QApplication(sys.argv)
    delete_book = Delete_book('admin')
    delete_book.show()
    sys.exit(app.exec_())

