from login_window import LoginWindow
from PyQt5.QtWidgets import QApplication
import sys

import subprocess




if __name__ == '__main__':
    # cmd = 'your command'
    # res = subprocess.call(cmd, shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    app = QApplication(sys.argv)
    win = LoginWindow()
    win.show()
    sys.exit(app.exec_())