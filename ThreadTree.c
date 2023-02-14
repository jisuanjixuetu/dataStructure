#include<stdio.h>
#include<stdint.h>
typedef struct ThreadNode{
    int data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;
}ThreadNode,*ThreadTree;
ThreadNode *pre = NULL;
//中序线索化
void InorderThreading(ThreadTree tree){
    if(tree){
        InorderThreading(tree->lchild);
        findPre(tree);
        InorderThreading(tree->rchild);
    }
}
void findPre(ThreadNode *q) {
    if(q->lchild==NULL){
        q->lchild = pre;
        q->ltag = 1;
    }
    if(pre!=NULL&&pre->lchild==NULL){
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}
void CreateThread(ThreadTree tree){
    pre = NULL;
    if(tree){
        InorderThreading(tree);
        if(pre->rchild == NULL){
            pre->rtag = 1;
        }
    }
}