from ui.detial import Ui_Form
from PyQt5.QtWidgets import QApplication    # 登陆窗口类
import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from util.common_util import msg_box
from PyQt5.QtWidgets import QListWidgetItem
from PyQt5.QtWidgets import QWidget
import pymysql


class book_detial(Ui_Form, QWidget):
    def __init__(self, username=None, book_name=None):
        super(book_detial, self).__init__()
        self.setupUi(self)
        self.username = username
        self.book_name = book_name
        self.init_ui()

        self.get_detial()



    def init_ui(self):
        self.setWindowTitle("书籍详细页面")
        self.label.setScaledContents(False)
        path = "../book_covers_release_jpg/"+self.book_name+".jpg"
        self.pixmap = QtGui.QPixmap(path)
        scaled = self.pixmap.scaled(200, 300, QtCore.Qt.KeepAspectRatio)
        self.label.setPixmap(scaled)
        self.label.setAlignment(QtCore.Qt.AlignVCenter | QtCore.Qt.AlignHCenter)



    # 获取书籍数据
    def get_detial(self):
        conn = pymysql.connect(
            host="localhost",
            user="root",
            password="123456",
            database="test",
            charset="utf8"
        )

        cursor = conn.cursor()  # 获取游标
        sql = "SELECT * FROM `douban_book_release` WHERE `book_name`='%s'" % (self.book_name)
        cursor.execute(sql)
        data = cursor.fetchall()
        _translate = QtCore.QCoreApplication.translate
        __sortingEnabled = self.listWidget.isSortingEnabled()

        item_0 = QtWidgets.QListWidgetItem()
        self.listWidget.addItem(item_0)
        book_name = data[0][0]
        item_0 = self.listWidget.item(0)
        item_0.setText(_translate("Form", "书籍名称："+book_name))

        item_1 = QtWidgets.QListWidgetItem()
        self.listWidget.addItem(item_1)
        author = data[0][1]
        item_1 = self.listWidget.item(1)
        item_1.setText(_translate("Form", "作者：" + author))

        item_2 = QtWidgets.QListWidgetItem()
        self.listWidget.addItem(item_2)
        press = data[0][2]
        item_2 = self.listWidget.item(2)
        item_2.setText(_translate("Form", "出版社：" + press))

        item_3 = QtWidgets.QListWidgetItem()
        self.listWidget.addItem(item_3)
        year = data[0][3]
        item_3 = self.listWidget.item(3)
        item_3.setText(_translate("Form", "出版年份：" + year))

        item_4 = QtWidgets.QListWidgetItem()
        self.listWidget.addItem(item_4)
        score = data[0][4]
        item_4 = self.listWidget.item(4)
        item_4.setText(_translate("Form", "综合评分：" + str(score)))

        item_5 = QtWidgets.QListWidgetItem()
        self.listWidget.addItem(item_5)
        rating_num = data[0][5]
        item_5 = self.listWidget.item(5)
        item_5.setText(_translate("Form", "评价人数：" + str(rating_num)))

        item_6 = QtWidgets.QListWidgetItem()
        self.listWidget.addItem(item_6)
        page_num = data[0][6]
        item_6 = self.listWidget.item(6)
        item_6.setText(_translate("Form", "书籍名称：" + str(page_num)))

        item_7 = QtWidgets.QListWidgetItem()
        self.listWidget.addItem(item_7)
        price = data[0][7]
        item_7 = self.listWidget.item(7)
        item_7.setText(_translate("Form", "书籍名称：" + str(price)))

        item_8 = QtWidgets.QListWidgetItem()
        self.listWidget.addItem(item_8)
        isbn = data[0][8]
        item_8 = self.listWidget.item(8)
        item_8.setText(_translate("Form", "国际标准书号：" + str(isbn)))

        item_9 = QtWidgets.QListWidgetItem()
        self.listWidget.addItem(item_9)
        content_introduction = data[0][9]
        item_9 = self.listWidget.item(9)
        item_9.setText(_translate("Form", "内容简介：" + content_introduction))

        # cover_url = data[0][10]
        #
        #
        # readers_url = data[0][11]
        conn.close()


















if __name__ =="__main__":
    app = QApplication(sys.argv)
    win = book_detial(username="admin", book_name='大卫・科波菲尔（英汉对照）')
    win.show()
    sys.exit(app.exec_())
