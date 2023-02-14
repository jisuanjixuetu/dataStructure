#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}Node,*DLinkedList;
void InitList(DLinkedList*list){
    (*list)->next=(*list);
    (*list)->prev=(*list);
}
void CreatDLinkedList(DLinkedList *list){
    Node*r,*p;
    r=(*list);
    for(int i = 0;i< MaxSize;i++){
        p = (Node*)malloc(sizeof(Node));
        printf("please enter the %d node\n",i+1);
        scanf("%d",&p->data);
        p->next = r->next;
        r->next = p;
        p->prev=r; 
        r = p;
        (*list)->prev=p;
    }
}
void InsertDLinkedList(int n,DLinkedList*list){
    Node *p = (Node *)malloc(sizeof(Node));
    p = *list;
    for (int i = 0; i < n-1; i++){
        p = p->next;
    }
    Node *s = (Node*)malloc(sizeof(Node));
    printf("please enter the data of the node\n");
    scanf("%d",&s->data);
    s->next=p->next;
    p->next->prev=s;
    p->next=s;
    s->prev=p;
}
int main(){
    DLinkedList head = (DLinkedList)malloc(sizeof(Node));
    InitList(&head);
    CreatDLinkedList(&head);
    InsertDLinkedList(3,&head);
    Node *temp;
    temp = head->next;
    while (temp!=head) {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    temp = head->prev;
    while (temp != head) {
        printf("%d\n",temp->data);
        temp=temp->prev;
    }
    return 0;
}