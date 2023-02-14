#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct binode
{
    char data;
    struct binode *lchild, *rchild;
} BiTNode, *BinaryTree;
void InOrder(BinaryTree tree)
{
    if (tree!=NULL)
    {
        InOrder(tree->lchild);
        printf("%c\t", tree->data);
        InOrder(tree->rchild);
    }
}
void PreOrder(BinaryTree tree){
    if (tree!=NULL){
        printf("%c\t", tree->data);
        PreOrder(tree->lchild);
        PreOrder(tree->rchild);
    }
}
void PostOrder(BinaryTree tree){
    if (tree != NULL){
        PostOrder(tree->lchild);
        PostOrder(tree->rchild);
        printf("%c\t", tree->data);
    }
}
void CreateBitree(BinaryTree *tree){
    char ch;
    scanf("%c",&ch);
    getchar();
    if(ch==' '){
        *tree=NULL;
    }
    else{
        (*tree) = (BiTNode*)malloc(sizeof(BiTNode));
        (*tree)->data=ch;
        CreateBitree(&((*tree)->lchild));
        CreateBitree(&((*tree)->rchild));
    }
}
int main(){
    BinaryTree tree;
    CreateBitree(&tree);
    printf("the inorder tree is\n");
    InOrder(tree);
    printf("\n");
    printf("the preorder tree is\n");
    PreOrder(tree);
    printf("\n");
    printf("the PostOrder tree is\n");
    PostOrder(tree);
    return 0;
}