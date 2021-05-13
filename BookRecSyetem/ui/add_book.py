# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'add_book.ui'
#
# Created by: PyQt5 UI code generator 5.12.3
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_Form(object):
    def setupUi(self, Form):
        Form.setObjectName("Form")
        Form.resize(762, 712)
        self.tableWidget = QtWidgets.QTableWidget(Form)
        self.tableWidget.setGeometry(QtCore.QRect(50, 30, 651, 631))
        self.tableWidget.setObjectName("tableWidget")
        self.tableWidget.setColumnCount(3)
        self.tableWidget.setRowCount(0)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(1, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(2, item)
        self.layoutWidget = QtWidgets.QWidget(Form)
        self.layoutWidget.setGeometry(QtCore.QRect(50, 670, 651, 30))
        self.layoutWidget.setObjectName("layoutWidget")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.layoutWidget)
        self.horizontalLayout.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.fresh_button = QtWidgets.QPushButton(self.layoutWidget)
        self.fresh_button.setObjectName("fresh_button")
        self.horizontalLayout.addWidget(self.fresh_button)
        self.edit_button = QtWidgets.QPushButton(self.layoutWidget)
        self.edit_button.setObjectName("edit_button")
        self.horizontalLayout.addWidget(self.edit_button)
        self.delete_button = QtWidgets.QPushButton(self.layoutWidget)
        self.delete_button.setObjectName("delete_button")
        self.horizontalLayout.addWidget(self.delete_button)
        self.add_button = QtWidgets.QPushButton(self.layoutWidget)
        self.add_button.setObjectName("add_button")
        self.horizontalLayout.addWidget(self.add_button)

        self.retranslateUi(Form)
        QtCore.QMetaObject.connectSlotsByName(Form)

    def retranslateUi(self, Form):
        _translate = QtCore.QCoreApplication.translate
        Form.setWindowTitle(_translate("Form", "Form"))
        item = self.tableWidget.horizontalHeaderItem(0)
        item.setText(_translate("Form", "书籍名称"))
        item = self.tableWidget.horizontalHeaderItem(1)
        item.setText(_translate("Form", "作者"))
        item = self.tableWidget.horizontalHeaderItem(2)
        item.setText(_translate("Form", "评分"))
        self.fresh_button.setText(_translate("Form", "刷新列表"))
        self.edit_button.setText(_translate("Form", "修改书籍"))
        self.delete_button.setText(_translate("Form", "删除书籍"))
        self.add_button.setText(_translate("Form", "添加书籍"))
