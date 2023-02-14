#include<stdio.h>
#include<stdio.h>
#define MaxQSize 100
typedef struct sqQueue{
    int *base;
    int front;
    int rear;
}SqQueue;
void InitQueue(SqQueue *queue){
    queue->base = (int *)malloc(MaxQSize*sizeof(SqQueue));
    if(!queue->base){
        printf("error\n");
    }
    queue->front = queue->base = 0;
}
int QueueLength(SqQueue *queue){
    return queue->rear-queue->front;
}
void EnQueue(SqQueue *queue,int e){
    if((queue->rear+1)%MaxQSize == queue->front){
        printf("full\n");
    }
    queue->base[queue->rear];
    queue->rear = (queue->rear+1)%MaxQSize;
}
int DeQueue(SqQueue *queue){
    int e;
    if(queue->rear==queue->front){
        printf("empty\n");
    }
    e = queue->base[queue->rear];
    queue->front = (queue->front+1)%MaxQSize;
    return e;
}
