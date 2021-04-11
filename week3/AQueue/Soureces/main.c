#include "AQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* s_gets(char* st, int n);
void setType();
int read();
void Display();
void select(AQueue* Q);
void setVoid(AQueue* Q);

int main()
{
    AQueue* Q;

    Q = (AQueue*)malloc(sizeof(AQueue));
    puts("**********************************************************");
    puts("请输入队列的类型  a.整型  b.字符型  c.浮点型  d.字符串型");
    puts("**********************************************************");
    setType();
    Display();
    select(Q);
    return 0;

}

//选择操作
void select(AQueue* Q)
{
    int i = 0;
    void* t;
    puts("请选择你的操作");
    switch (read())
    {
    case 1:
    	{
    		InitAQueue(Q);
    		puts("初始化队列成功!\n\n");
    		break;
    	}
    case 2:
    	{
    		DestoryAQueue(Q);
    		break;
    	}
    case 3:
    	{

    		if (IsEmptyAQueue(Q))
			puts("该队列为空");
		else
			puts("该队列不为空");
		break;
    	}
    case 4:
        {
		if(IsFullAQueue(Q))
			puts("该队列为满");
		else
			puts("该队列不为满");
		break;
        }
    case 5:
    	{
    		if (GetHeadAQueue(Q, t))
		{
		printf("获取头结点成功，头节点为");
		APrint(t);
		printf("\n");
		}
		else puts("操作失败,队列为空");
		break;
    	}
    case 6:i = LengthAQueue(Q); printf("队列长度为%d\n", i);
        break;
    case 7:
    	{
    		if (IsFullAQueue(Q))
			puts("操作失败,队列已满");
		else {
		setVoid(Q);
		puts("操作成功");
	}
    	}
          break;
    case 8:
    	{
    		if(DeAQueue(Q))
			puts("出队成功");
		else
			puts("操作失败，队列为空");
    		break;
    	}
    case 9:
    	{
    		ClearAQueue(Q);
    		puts("队列已清空");
		break;
    	}


    case 10:
    	{
    		if (TraverseAQueue(Q, APrint))
			puts("操作成功");
		else puts("操作失败");
		break;
    	}
    case 11:
    	{
    		system("cls");
    		Display();
    		break;
    	}
    default:
    	puts("输入错误");
    }
    select(Q);
}

//打印菜单
void Display()
{
	printf("###################################\n");
	printf("##     1. 初始化顺序队列         ##\n");
	printf("##     2. 销毁顺序队列           ##\n");
	printf("##     3. 判断队列是否为空       ##\n");
	printf("##     4. 判断队列是否为满       ##\n");
	printf("##     5. 获取队头元素           ##\n");
	printf("##     6. 获取队列的长度         ##\n");
	printf("##     7. 入队操作               ##\n");
	printf("##     8. 出队操作               ##\n");
	printf("##     9. 清空队列               ##\n");
	printf("##     10. 遍历队列并打印元素    ##\n");
	printf("##     11. 清空当前屏幕          ##\n");
	printf("###################################\n");
}

//确定泛型
void setType()
{
    char t[3];

    s_gets(t, 3);
    if (t[0] == 'a' && t[1] == '\0')
    {
        type = 'i';
        typeSize = sizeof(int);
    }
    else if (t[0] == 'b' && t[1] == '\0')
    {
        type = 'c';
        typeSize = sizeof(char);
    }
    else if (t[0] == 'c' && t[1] == '\0')
    {
        type = 'd';
        typeSize = sizeof(double);
    }
    else if (t[0] == 'd' && t[1] == '\0')
    {
        type = 's';
        typeSize = sizeof(char) * 100;
    }
    else {
        puts("输入错误！请重新输入");
        setType();
    }

}

//获取int
int read()
{
    char in[10];
    int t;

    s_gets(in, 10);
    t = atoi(in);
    if (t == 0) {
        if (in[1] != 0 || in[2] != '\0')
        {
            printf("输入错误，请重新输入！\n");
            t = read();
        }
    }
    return t;
}

//读取键盘输入
char* s_gets(char* st, int n)
{
    char* ret_val;
    char* find;

    fflush(stdin);
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;

}

//入队数据操作
void setVoid(AQueue* Q)
{
    char c[100];

    if (type == 'i')
    {
        int a = 0;

        puts("请输入数据");
        a = read();
        EnAQueue(Q, &a);
    }
    else if (type == 'c')
    {
        puts("请输入数据");
        s_gets(c, 3);
        if (c[2] != '\0')
        {
            puts("类型错误，请重新输入");
            s_gets(c, 3);
        }
        EnAQueue(Q, &c[0]);
    }
    else if (type == 'd')
    {
        double d;


        puts("请输入数据");
        s_gets(c, 100);

    skip:  d = atof(c);
        if (d == 0) {
            int i = 0;
            while (c[i++] != '\0')
            {
                if (c[i] != '0' && c[i] != '.')
                {
                    puts("输入错误，请重新输入\n");
                    s_gets(c, 100);
                    goto skip;
                }
            }
        }
        EnAQueue(Q, &d);
    }
    else if (type == 's')
    {
        puts("请输入数据");
        s_gets(c, 100);
        EnAQueue(Q, &c);
    }
    else if (type == '*')
    {
        EnAQueue(Q, &c[Q->length]);

    }
}

