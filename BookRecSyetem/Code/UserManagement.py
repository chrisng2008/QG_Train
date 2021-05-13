# 创建一个数据库
# 连接数据库 储存账号密码
import pymysql

class user_management():
    def __init__(self, host="localhost", user="root", password="123456", database="test", charset="utf8"):
        self._conn = pymysql.connect(
            host=host,
            user=user,
            password=password,
            database=database,
            charset=charset
        )
        self._cursor = self._conn.cursor()  # 得到一个可执行的游标对象
        # self._cursor.execute("DROP TABLE IF EXISTS UserManagement")  # 如果表存在则删除
        self.creat_table()

    def creat_table(self):
        '''
        创建一个储存账号和密码的表格
        :return:
        '''
        # 如果UserManagement表格不存在，则创建表格
        sql = """
            CREATE TABLE if NOT EXISTS `user_info`(
            `id` INT auto_increment PRIMARY KEY,
            `Account` VARCHAR(50),
            `Password` VARCHAR(50),
            `read_book_and_score` TEXT
            )
        """
        try:
            self._cursor.execute(sql)  # 执行创建表操作
        except Exception as e:
            print(e)
            # 发生错误则回滚
            self._conn.rollback()
        # self._conn.close()

    def query_super(self, table_name, column_name, condition):
        cursor = self._conn.cursor()
        sql = "SELECT * FROM {} WHERE {}= '{}' ".format(table_name, column_name, condition)
        count = self._cursor.execute(sql)
        res = self._cursor.fetchall()
        return count, res

    def add_user(self, user_info):
        '''
        添加用户
        :param user_info:
        :return:
        '''
        conn = pymysql.connect(  # 连接本地数据库
            host="localhost",
            user="root",
            password="123456",  # 填上自己的密码
            database="test",
            charset="utf8"
        )
        # 使用cursor()方法获取操作游标
        cursor = conn.cursor()
        # SQL 插入语句
        sql = '''INSERT INTO `user_info`(`Account`, `Password`) VALUES (%s, %s)'''
        try:
            self._cursor.executemany(sql, user_info)
            self._conn.commit()
        except Exception as e:
            print(e)
            # 发生错误则回滚
            conn.rollback()
    # def commit(self):
    #     self._conn.commit()



if __name__ == '__main__':
    user = user_management()
