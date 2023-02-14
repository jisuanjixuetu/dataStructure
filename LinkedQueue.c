#include<stdio.h>
#include<stdlib.h> 
#include<stdbool.h>
typedef struct qNode{
    int data;
    struct Qnode *next;
}QNode,*Queueptr;
typedef struct linkqueue{
    Queueptr front;
    Queueptr rear;
}Linkqueue;
void InitQueue(Linkqueue *queue){
    queue->front = queue->rear = (Queueptr)malloc(sizeof(QNode));
    if(!queue->front){
        exit(1);
    }
    queue->front->next = NULL;
}
void DestroyQueue(Linkqueue *queue){
    while (queue->front){
        queue->rear = queue->front->next;
        free(queue->front);
        queue->front = queue->rear;
    }
}
void EnQueue(Linkqueue *queue,int e){
    Queueptr p = (Queueptr)malloc(sizeof(QNode));
    if (!p) {
        exit(1);
    }
    p->data = e;
    p->next = NULL;
    queue->rear->next = p;
    queue->rear = p;
}
int DeQueue(Linkqueue *queue){
    if(queue->front == queue->rear){
        printf("error\n");
    }
    Queueptr p;
    p = queue->front->next;
    int e = p->data;
    queue->front->next = p->next;
    if(queue->rear == p){
        queue->rear = queue->front;
    }
    free(p);
    return e;
}
bool IsQueueEmpty(Linkqueue *queue){
    return queue->front == queue->rear;
}
int main(void){
    Linkqueue queue;
    InitQueue(&queue);
    for(int i = 0;i<10;i++){
        int e;
        printf("please enter the %d qnode\n",i+1);
        scanf("%d",&e);
        EnQueue(&queue,e);
    }
    while(!(queue.front==queue.rear)) {
        printf("%d\n",DeQueue(&queue));
    }
    return 0;
}
