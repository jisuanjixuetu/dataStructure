#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct binode
{
    char data;
    struct binode *lchild, *rchild;
} BiTNode, *BinaryTree;
// typedef struct sNode{
//     struct binode *data;
//     struct SNode *next;
// }SNode,*Stack;
// typedef struct linkStack{
//     Stack front;
//     Stack rear;
// } LinkStack;
// typedef struct qNode
// {
//     struct binode *data;
//     struct qnode *next;
// } QNode, *Queueptr;
// typedef struct linkqueue
// {
//     Queueptr front;
//     Queueptr rear;
// } Linkqueue;
// void InitStack(LinkStack *stack){
//     stack->front = stack->rear = (Stack) malloc(sizeof(SNode));
//     if(!stack->front){
//         exit(1);
//     }
//     stack->front = stack->rear = NULL;
// }
// void Push(LinkStack *stack,BiTNode*node){
//     SNode *snode = (SNode*)malloc(sizeof(SNode));
//     snode->data=node;
//     snode->next=stack->front->next;
//     stack->front->next=snode;
// }
// BiTNode* Pop(LinkStack *stack){
//     SNode *node;
//     node = stack->front->next;
//     stack->front->next=node->next;
//     if(stack->front->next==NULL){
//         stack->front= stack->rear;
//     }
//     return node->data;
// }
// void InitQueue(Linkqueue *queue)
// {
//     queue->front = queue->rear = (Queueptr)malloc(sizeof(QNode));
//     if (!queue->front)
//     {
//         exit(1);
//     }
//     queue->front->next = NULL;
// }
// bool IsQueueEmpty(Linkqueue *queue)
// {
//     return queue->front == queue->rear;
// }
// bool IsStackEmpty(LinkStack *stack)
// {
//     return stack->front == stack->rear;
// }
// void EnQueue(Linkqueue *queue, BiTNode *tree)
// {
//     Queueptr p = (Queueptr)malloc(sizeof(QNode));
//     if (!p)
//     {
//         exit(1);
//     }
//     p->data = tree;
//     p->next = NULL;
//     queue->rear->next = p;
//     queue->rear = p;
// }
// BiTNode* getTop(LinkStack*stack){
//     SNode *node;
//     node = stack->front->next;
//     return node->data;
// }
// BiTNode *DeQueue(Linkqueue *queue)
// {
//     if (IsQueueEmpty(queue))
//     {
//         printf("error\n");
//     }
//     Queueptr p;
//     p = queue->front->next;
//     queue->front->next = p->next;
//     if (queue->rear == p)
//     {
//         queue->rear = queue->front;
//     }
//     return p->data;
// }
// 先序遍历
// void PreTraverse(BinaryTree tree)
// {
//     if (tree)
//     {
//         printf("%d\t", tree->data);
//         PreTraverse(tree->lchild);
//         PreTraverse(tree->rchild);
//     }
// }
// 中序遍历
void InOrder(BinaryTree tree)
{
    if (tree)
    {
        InOrder(tree->lchild);
        printf("%c\t", tree->data);
        InOrder(tree->rchild);
    }
}
// 后序遍历
void PostTraverse(BinaryTree tree)
{
    if (tree)
    {
        PostTraverse(tree->lchild);
        PostTraverse(tree->rchild);
        printf("%c\t", tree->data);
    }
}
// 层序遍历
// void LevelTraverse(BinaryTree tree)
// {
//     Linkqueue queue;
//     InitQueue(&queue); // 初始化辅助队列
//     BinaryTree p;
//     EnQueue(&queue, tree); // 将根结点入队
//     while (!IsQueueEmpty(&queue))
//     {
//         p = DeQueue(&queue); // 队头结点出队
//         printf("%d\t", p->data);
//         if (p->lchild)
//         {
//             EnQueue(&queue, p->lchild);
//         }
//         if (p->rchild)
//         {
//             EndQueue(&queue, p->rchild);
//         }
//     }
// }
// 求深度
int treeDepth(BinaryTree tree)
{
    if (!tree)
    {
        return 0;
    }
    else
    {
        int l = treeDepth(tree->lchild);//左子树深度
        int r = treeDepth(tree->rchild);//右子树深度
        return l > r ? l + 1 : r + 1;//返回树的深度
    }
}
//中序遍历非递归
// void InorderTraverseF(BinaryTree tree){
//     LinkStack stack;
//     InitStack(&stack);
//     Push(&stack, tree);
//     SNode *p;
//     while (p=getTop(&stack)){
//         Push(&stack, p);
//     }
//     p=Pop(&stack);
//     if(!IsStackEmpty(&stack)){
//         p=Pop(&stack);
//         printf("%d\n",p->data->data);
//         Push(&stack,p->data->rchild);
//     }
// }
void CreateBitree(BinaryTree tree){
    char ch;
    printf("please enter a data\n");
    scanf("%c",&ch);
    getchar();
    if(ch==' '){
        tree=NULL;
    }
    else{
        BiTNode *t = (BiTNode*)malloc(sizeof(BiTNode));
        t->data=ch;
        CreateBitree(t->lchild);
        CreateBitree(t->rchild);
    }
}
int main(){
    BinaryTree tree;
    CreateBitree(tree);
    InOrder(tree);
    return 0;
}