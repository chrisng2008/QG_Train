from PyQt5.QtWidgets import QWidget
from PyQt5.QtCore import pyqtSignal, Qt
from ui.person import Ui_Form
from PyQt5.QtWidgets import QApplication    # 登陆窗口类
import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from register_window import RegisterWindow
from util.common_util import msg_box
import pymysql

class person(Ui_Form, QWidget):
    def __init__(self, username=None):
        super(person, self).__init__()
        self.username = username
        self.setupUi(self)
        self.init_ui()
        self.init_slot()
        self.person = None


    def init_ui(self):
        self.setWindowTitle("个人中心")

    def init_slot(self):
        self.pushButton.clicked.connect(lambda : self.bin_slot('edit'))

    def bin_slot(self, tag):
        if tag == 'edit':
            conn = pymysql.connect(
                host="localhost",
                user="root",
                password="123456",
                database="test",
                charset="utf8"
            )
            cursor = conn.cursor()
            sql = "SELECT * FROM `user_info` WHERE `Account` = '%s'" % (self.username)
            is_success = cursor.execute(sql)
            data = cursor.fetchall()
            name = data[0][1]
            password = data[0][2]
            new_password1 = self.lineEdit.text()
            new_password2 = self.lineEdit_2.text()


            if '' in [new_password1, new_password2]:
                msg_box(self, '提示', '密码不能为空')
                return
            if new_password1 != new_password2:
                msg_box(self, '提示', '两次密码输入不一致，请重试')
                return
            if password == new_password1:
                msg_box(self, '提示', '密码不能和原密码一致')
                return
            sql_2 = "UPDATE `user_info` SET `Password`='%s' WHERE `Account` = '%s'" % (new_password1, self.username)
            cursor.execute(sql_2)
            conn.commit()
            msg_box(self, '提示', '密码修改成功')
            print('修改成功，新的密码为：'+str(new_password1))
            conn.close()

if __name__ == "__main__":
    app = QApplication(sys.argv)
    win = person('admin')
    win.show()
    sys.exit(app.exec_())



