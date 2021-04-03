#include "LinkStack.h"
#include <stdio.h>
int main()
{
	int i, n;
	printf("Enter the num the test the function!\n");
	printf("         **输入0结束**\n");
	printf("###################################\n");
	printf("##     1. 初始化链栈             ##\n");
	printf("##     2. 判断链栈是否为空       ##\n");
	printf("##     3. 获取栈顶元素           ##\n");
	printf("##     4. 清空栈                 ##\n");
	printf("##     5. 销毁栈                 ##\n");
	printf("##     6. 获取栈的长度           ##\n");
	printf("##     7. 入栈操作               ##\n");
	printf("##     8. 出栈操作               ##\n");
	printf("##     9. 清空当前屏幕           ##\n");
	printf("###################################\n");

	LinkStackPtr s;
	do
	{
		scanf_s("%d", &n);
		switch (n)
		{
		case 0:
			break;
		case INITSTACK:
		{
			if (initLStack(&s))
				printf("初始化链栈成功！\n\n");
			break;
		}

		case ISEMPTY:
		{
			if (isEmptyLStack(&s))
				printf("该链栈为空\n\n");
			else
				printf("该链栈不为空\n\n");
			break;
		}
		case GETTOPLSTACK:
		{
			ElemType e;
			if (getTopLStack(&s, &e)){
				printf("获取栈顶元素成功！\n");
				printf("当前栈顶元素为%d\n\n", e);
			}
			else
				printf("获取栈顶元素失败!该链栈为空\n\n");
			break;
		}
		case CLEARLSTACK:
		{
			if (clearLStack(&s))
				printf("清空栈成功！\n\n");
			else
				printf("清空栈失败！\n\n");
			break;
		}
		case DESTORYLSTACK:
		{
			if (destroyLStack(&s))
				printf("销毁栈成功！\n\n");
			else
				printf("销毁栈失败！\n\n");
			break;
		}

		case LSTACKLENGTH:
		{
			int length;
			if (LStackLength(&s, &length))
			{
				printf("成功获取链栈的长度\n");
				printf("链栈的长度为%d\n\n", length);
			}
			else
				printf("获取链栈长度失败!\n\n");
			break;
		}
		case PUSHSTACK:
		{
			ElemType data;
			printf("请输入入栈元素的数据:");
			scanf_s("%d", &data);
			if (pushLStack(&s, data))
				printf("入栈操作成功!\n\n");
			else
				printf("入栈操作失败！\n\n");
			break;
		}
		case POPLSTACK:
		{
			ElemType data;
			if (popLStack(&s, &data)){
				printf("出栈操作成功！\n");
				printf("出栈结点的数值为:%d\n\n", data);
				}
			else
			{
				printf("出栈操作失败！\n\n");
			}
			break;
		}
		
		default:
			printf("输入错误！请输入0-8之间的整数");
		}
	} while (n != 0);


	return 0;
}



