 #include "AQueue.h"
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 void InitAQueue(AQueue *Q)
 {
     for(int i = 0; i < MAXQUEUE; i++)
         Q->data[i] = (void *)malloc(typeSize);
 	Q->front = Q->rear = Q->length = 0;
 }

 void DestoryAQueue(AQueue *Q)
 {
     int i = 0;
 	while (Q->length--)
         free(Q->data[i++]);
 	exit(0);
 }

 Status IsFullAQueue(const AQueue *Q)
 {
     if (Q->length == MAXQUEUE)
         return TRUE;
     return FALSE;
 }

 Status IsEmptyAQueue(const AQueue *Q)
 {
     if (!Q->length) return TRUE;
     return FALSE;
 }

 Status GetHeadAQueue(AQueue *Q, void *e)
 {
     if (IsEmptyAQueue(Q)) return FALSE;
     memcpy(e,Q->data[0],typeSize);
     return TRUE;
 }

 int LengthAQueue(AQueue *Q)
 {
     return Q->length;
 }

 Status EnAQueue(AQueue *Q, void *data)
 {
     if (IsFullAQueue(Q))
 	{
 		printf("队列满了\n");
 		return FALSE;
 	}
 	memcpy(Q->data[Q->rear], data, typeSize);
     Q->rear = (Q->rear + 1) % MAXQUEUE;
 	Q->length++;
 	return TRUE;
 }

 Status DeAQueue(AQueue *Q)
 {
     if (IsEmptyAQueue(Q))
     {
         printf("队列是空的！\n");
         return FALSE;
     }
     Q->front = (Q->front+1)%MAXQUEUE;
     Q->length--;
     return TRUE;
 }

 void ClearAQueue(AQueue *Q)
 {
     Q->front = Q->rear = Q->length = 0;
 }

 Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 {
     if (IsEmptyAQueue(Q))
     {
         puts("队列为空！");
         return FALSE;
     }
     for (int i = Q->front,j = Q->length;j > 0;j--)
     {
         foo(Q->data[i]);
         i = (i+1)%MAXQUEUE;
     }
         return TRUE;
 }

 void APrint(void *q)
 {
      if  (type == 'd')
             printf("--> %.2lf", *(double*)q);
     else if (type == 'c')
             printf("--> %c", *(char*)q);
     else if (type == 'i')
             printf("--> %d ", *(int*)q);
     else if (type == 's')
             printf("--> %s ", (char*)q);
 }
