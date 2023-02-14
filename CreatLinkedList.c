#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef struct node
{
    int data;
    struct node *next;
} Node, *LinkedList;
void InitList(LinkedList *list)
{
    *list = (LinkedList)malloc(sizeof(Node));
    (*list)->next = NULL;
}
// void InsertList(int n,LinkedList *list){
//     Node*temp = (Node*)malloc(sizeof(Node));
//     temp = *list;
//     for (int i = 0; i < n-1; i++) {
//         temp = temp->next;
//     }
//     Node *p = (Node*)malloc(sizeof(Node));
//     printf("please entet the node\n");
//     scanf("%d",&p->data);
//     p->next = temp->next;
//     temp->next = p;
// }
// void DeleteList(int n,LinkedList *list){
//     Node*temp;
//     Node*p;
//     temp=(*list);
//     for(int i = 0;i<n-1;i++){
//         temp = temp->next;
//     }
//     p = temp->next;
//     temp->next = p->next;
//     free(p);
// }
// void FreeNode(LinkedList *list)
// {
//     Node *temp;
//     temp = *list;
//     while (temp->next)
//     {
//         Node *p;
//         p = temp->next;
//         temp->next = p->next;
//         free(p);
//     }
// }
// void ReversedLit(LinkedList *list)
// {
//     Node *first = (*list)->next;
//     (*list)->next = NULL;
//     while (first)
//     {
//         Node *t = first->next;
//         first->next = (*list)->next;
//         (*list)->next = first;
//         first = t;
//     }
// }
int main()
{
    LinkedList head;
    InitList(&head);
    // // 头插法
    // for (int i = 0; i < MaxSize; i++)
    // {
    //     printf("please enter the %d node\n", i + 1);
    //     Node *temp = (Node *)malloc(sizeof(Node));
    //     temp->next = head->next;
    //     head->next = temp;
    //     scanf("%d", &temp->data);
    //     getchar();
    // }
    // Node *p;
    // p = head->next;
    // while (p)
    // {
    //     printf("%d\n", p->data);
    //     p = p->next;
    // }
    //
    Node *r, *p;
    r = head;
    for (int i = 0; i < MaxSize; i++)
    {
        printf("please enter the %d node\n", i + 1);
        p = (Node *)malloc(sizeof(Node));
        scanf("%d", &p->data);
        getchar();
        p->next = r->next;
        r->next = p;
        r = p;
    }
    // InsertList(4,&h);
    // DeleteList(4,&head);
    // FreeNode(&head);
    // ReversedLit(&head);
    Node *temp;
    temp = head->next;
    while (temp)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    return 0;
}