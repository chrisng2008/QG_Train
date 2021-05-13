# 账号注册页面
import sys

from PyQt5.QtCore import Qt
from PyQt5.QtGui import QIcon
from UserManagement import user_management
from PyQt5.QtWidgets import QWidget, QApplication
from ui.register import Ui_Form
from util.common_util import msg_box
class RegisterWindow(Ui_Form, QWidget):

    def __init__(self):
        super(RegisterWindow, self).__init__()   # 父类初始化
        self.setupUi(self)
        self.role = None
        self.resgister()
        # self.retranslateUi(self)
        self.init_ui()
        self.register_pushButton.clicked.connect(self.resgister)
        # self.cancel_pushButton.clicked.connect(self.cancel)


    def init_ui(self):
        self.setWindowFlags(Qt.WindowCloseButtonHint | Qt.WindowMinimizeButtonHint)

    def resgister(self):
        account = self.Account_text.text()
        password = self.Password_text.text()
        confirm = self.Password2_text.text()

        if '' in [account, password, confirm]:
            msg_box(self, '提示', '输入不能为空，请重新输入')
            return
        user_manage = user_management()
        count, res = user_manage.query_super(table_name='user_info', column_name='Account', condition=account)
        if count != 0:
            msg_box(self, '错误', '用户名已存在')
            return
        if password != confirm:
            msg_box(self, '错误', '两次输入的密码不一致')
            return
        user_info = [(account,password)]
        user_manage.add_user(user_info)
        # user_manage.commit()
        # user_management.instance = None
        del user_manage
        msg_box(self, '提示', '注册成功')
        self.close()


if __name__ == '__main__':
    app = QApplication(sys.argv)
    win = RegisterWindow()
    win.show()
    sys.exit(app.exec_())
    # user_manage = user_management()
    # user_info = [('admin', '123456')]
    # user_manage.add_user(user_info)




