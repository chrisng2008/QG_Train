# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'register.ui'
#
# Created by: PyQt5 UI code generator 5.12.3
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_Form(object):
    def setupUi(self, Form):
        Form.setObjectName("Form")
        Form.resize(534, 283)
        Form.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.Account = QtWidgets.QLabel(Form)
        self.Account.setGeometry(QtCore.QRect(90, 50, 31, 16))
        self.Account.setObjectName("Account")
        self.Password = QtWidgets.QLabel(Form)
        self.Password.setGeometry(QtCore.QRect(90, 100, 31, 16))
        self.Password.setObjectName("Password")
        self.Password2 = QtWidgets.QLabel(Form)
        self.Password2.setGeometry(QtCore.QRect(170, 180, 111, 20))
        self.Password2.setObjectName("Password2")
        self.register_pushButton = QtWidgets.QPushButton(Form)
        self.register_pushButton.setGeometry(QtCore.QRect(130, 210, 93, 28))
        self.register_pushButton.setObjectName("register_pushButton")
        self.cancel_pushButton = QtWidgets.QPushButton(Form)
        self.cancel_pushButton.setGeometry(QtCore.QRect(230, 210, 93, 28))
        self.cancel_pushButton.setObjectName("cancel_pushButton")
        self.Password2_text = QtWidgets.QLineEdit(Form)
        self.Password2_text.setGeometry(QtCore.QRect(130, 140, 191, 31))
        self.Password2_text.setObjectName("Password2_text")
        self.Password_text = QtWidgets.QLineEdit(Form)
        self.Password_text.setGeometry(QtCore.QRect(130, 90, 191, 31))
        self.Password_text.setObjectName("Password_text")
        self.Account_text = QtWidgets.QLineEdit(Form)
        self.Account_text.setGeometry(QtCore.QRect(130, 40, 191, 31))
        self.Account_text.setObjectName("Account_text")

        self.retranslateUi(Form)
        QtCore.QMetaObject.connectSlotsByName(Form)

    def retranslateUi(self, Form):
        _translate = QtCore.QCoreApplication.translate
        Form.setWindowTitle(_translate("Form", "账号注册"))
        self.Account.setText(_translate("Form", "账号"))
        self.Password.setText(_translate("Form", "密码"))
        self.Password2.setText(_translate("Form", "请再次输入密码"))
        self.register_pushButton.setText(_translate("Form", "注册"))
        self.cancel_pushButton.setText(_translate("Form", "取消"))
