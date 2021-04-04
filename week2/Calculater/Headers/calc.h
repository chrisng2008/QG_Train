#ifndef CALC_H_INCLUDE
#define CALC_H_INCLUDE

#define MAXSIZE 255
typedef struct sqstack
{
	int data[MAXSIZE];
	int top;/*栈顶，栈为空时top=1*/
}sqstack;

typedef enum Status
{
	SUCCESS=1,ERROR=0,
}Status;

Status *sqstack_create();
Status sqstack_push(sqstack *, int ); /*入栈*/
Status sqstack_pop(sqstack *, int *); /*出栈*/
Status sqstack_top(sqstack *, int *); /*查看栈顶的值*/
Status sqstack_is_empty(sqstack *); /*判断栈是否为空*/
Status sqstack_display(sqstack *);/*显示栈内容*/

#endif