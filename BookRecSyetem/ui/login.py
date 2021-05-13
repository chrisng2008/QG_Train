# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'login.ui'
#
# Created by: PyQt5 UI code generator 5.12.3
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_Form(object):
    def setupUi(self, Form):
        Form.setObjectName("Form")
        Form.resize(533, 283)
        self.pushButton_login = QtWidgets.QPushButton(Form)
        self.pushButton_login.setGeometry(QtCore.QRect(110, 160, 93, 28))
        self.pushButton_login.setObjectName("pushButton_login")
        self.label = QtWidgets.QLabel(Form)
        self.label.setGeometry(QtCore.QRect(30, 70, 31, 16))
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(Form)
        self.label_2.setGeometry(QtCore.QRect(30, 120, 31, 16))
        self.label_2.setObjectName("label_2")
        self.pushButton_register = QtWidgets.QPushButton(Form)
        self.pushButton_register.setGeometry(QtCore.QRect(110, 200, 93, 28))
        self.pushButton_register.setObjectName("pushButton_register")
        self.Logo = QtWidgets.QLabel(Form)
        self.Logo.setGeometry(QtCore.QRect(290, 60, 191, 161))
        self.Logo.setText("")
        self.Logo.setPixmap(QtGui.QPixmap("../ui/figure/logo.png"))
        self.Logo.setScaledContents(True)
        self.Logo.setObjectName("Logo")
        self.Head = QtWidgets.QLabel(Form)
        self.Head.setGeometry(QtCore.QRect(80, 30, 161, 16))
        self.Head.setObjectName("Head")
        self.Account_text = QtWidgets.QLineEdit(Form)
        self.Account_text.setGeometry(QtCore.QRect(70, 60, 191, 31))
        self.Account_text.setObjectName("Account_text")
        self.Password_text = QtWidgets.QLineEdit(Form)
        self.Password_text.setGeometry(QtCore.QRect(70, 110, 191, 31))
        self.Password_text.setObjectName("Password_text")

        self.retranslateUi(Form)
        QtCore.QMetaObject.connectSlotsByName(Form)

    def retranslateUi(self, Form):
        _translate = QtCore.QCoreApplication.translate
        Form.setWindowTitle(_translate("Form", "图书推荐系统登陆"))
        self.pushButton_login.setText(_translate("Form", "登陆"))
        self.label.setText(_translate("Form", "账号"))
        self.label_2.setText(_translate("Form", "密码"))
        self.pushButton_register.setText(_translate("Form", "注册"))
        self.Head.setText(_translate("Form", "欢迎来到图书推荐系统"))
