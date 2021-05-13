from PyQt5.QtGui import QIcon
from PyQt5.QtWidgets import QWidget
from PyQt5.QtCore import pyqtSignal, Qt
from ui.login import Ui_Form
from PyQt5.QtWidgets import QApplication    # 登陆窗口类
import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from register_window import RegisterWindow
from util.common_util import msg_box
from UserManagement import user_management
from main_windows import main_windows



class LoginWindow(Ui_Form, QWidget):

    # 登陆界面类构造函数，初始化类属性
    def __init__(self):
        super(LoginWindow, self).__init__()
        self.setupUi(self)
        self.role = None
        self.init_slot()
        self.init_ui()
        # self.main_window = None
        self.register_win = None

    def init_ui(self):
        self.setWindowFlags(Qt.WindowCloseButtonHint | Qt.WindowMinimizeButtonHint)

    def init_slot(self):
        '''
        初始化信号槽
        '''
        self.pushButton_login.clicked.connect(lambda:self.bin_slot('login'))
        self.pushButton_register.clicked.connect(lambda: self.bin_slot('register'))
        # self.login_done_signal.connect(self.handle_login)

    def bin_slot(self, tag):
        '''
        按键点击事件槽函数
        :param tag:
        :return:
        '''
        # register
        if tag == 'register':
            self.register_win = RegisterWindow()
            self.register_win.show()

        if tag == 'login':
            username = self.Account_text.text()
            password = self.Password_text.text()
            if '' in [username, password]:
                msg_box(self, '提示', '请输入用户名或密码!')
                return
            self.login(username, password)

        # login
        #if tag == 'login':

    def login(self, account, password):
        user_manage = user_management()
        count, res = user_manage.query_super(table_name='user_info', column_name='Account', condition=account)
        if count == 0:
            msg_box(self, '提示', '用户不存在，请重试')
            return
        user_password = res[0][2]
        if user_password != password:
            msg_box(self, '提示', '用户名或密码输入错误，请重试')
            return
        # 密码正确，登陆
        if user_password == password:
            msg_box(self, '提示', '登陆成功')
            # 需要在main_win前加self，否则会闪退
            self.main_win = main_windows(account)
            # self.main_win.init_ui(account)
            self.main_win.show()
            # self.main_win.set_hot_table()
            self.close()







    #def init_ui(self):
        # 初始化界面UI的函数
        # self.setWindowTitle('用户登录')
        # self.setWindowIcon(QIcon(APP_ICON))
        # self.pushButton.setProperty('class', 'Aqua')
        # self.pushButton_2.setProperty('class', 'Aqua')
        # self.setStyleSheet(SYS_STYLE)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    win = LoginWindow()
    win.bin_slot('register')
    # win.show()
    sys.exit(app.exec_())