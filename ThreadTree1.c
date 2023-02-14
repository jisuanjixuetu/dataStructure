#include<stdio.h>
#include<stdlib.h>
typedef enum pointerTag{
    Link,
    Thread
}PointerTag;
typedef struct BiThrNode{
    char data;
    struct BiThrNode *lchild,*rchild;
    PointerTag Ltag,Rtag;
}BiThrNode,*BiThrTree;
BiThrNode*pre = NULL;
void CreateBitree(BiThrTree *tree){
    char ch;
    scanf("%c",&ch);
    getchar();
    if(ch==' '){
        *tree=NULL;
    }
    else{
        (*tree) = (BiThrNode*)malloc(sizeof(BiThrNode));
        (*tree)->data=ch;
        CreateBitree(&((*tree)->lchild));
        CreateBitree(&((*tree)->rchild));
    }
}
void InThreading(BiThrTree tree){
    if(tree!=NULL){
        InThreading(tree->lchild);//找到最左端的树
        if(tree->lchild!=NULL){
            tree->Ltag=Thread;
            tree->lchild=pre;
        }//前驱线索
        if(pre->rchild==NULL&&pre!=NULL){
            pre->Rtag=Thread;
            pre->rchild = tree;
        }//后继线索
        pre=tree;//保持pre指向tree的前驱
        InThreading(tree->rchild);//右子树线索化
    }
}
void InorderThreading(BiThrTree *tree,BiThrTree T){
    tree=(BiThrTree)malloc(sizeof(BiThrNode));
    (*tree)->Ltag=Link;
    (*tree)->Rtag=Thread;
    (*tree)->rchild=(*tree);
    if(T!=NULL){
        (*tree)->lchild=T;
        pre=(*tree);
        InThreading(T);
        pre->rchild=(*tree);
        pre->Rtag=Thread;
        (*tree)->rchild=pre;
    }
}
void InOrderThreadingTraverse(BiThrTree tree){
    BiThrNode *p = tree->lchild;
    while(p!=tree){
        while(p->Ltag==Link){
            p=p->lchild;
        }
        printf("%c\t",p->data);
        while(p->Rtag==Thread&&p->rchild!=p){
            p=p->rchild;
            printf("%c\t",p->data);
        }
        p=p->rchild;                                                                                                                                              
    }
}