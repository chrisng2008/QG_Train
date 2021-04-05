#ifndef CALC_H_INCLUDE
#define CALC_H_INCLUDE


#define MAXSIZE 255
typedef struct sqstack
{
	int data[MAXSIZE];
	int top;
}sqstack;

typedef enum Status
{
	SUCCESS=1,ERROR=0,
}Status;

sqstack *sqstack_create();
Status sqstack_push(sqstack *, int ); 
Status sqstack_pop(sqstack *, int *);
Status sqstack_top(sqstack *, int *); 
Status sqstack_is_empty(sqstack *); 

#endif
