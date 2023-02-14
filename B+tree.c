#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EQ(x, y) ((x) == (y))
#define GT(x, y) ((x) > (y))
#define LT(x, y) ((x) < (y))

typedef struct node
{
    int key;
    struct node *lchild, *rchild;
} BSTNode, *BSTree;

void InsertBST(BSTree *bst, int key)
{
    BSTree s;
    if (bst == NULL)
    {
        s = (BSTree)malloc(sizeof(BSTNode));
        s->key = key;
        s->rchild = NULL;
        s->lchild = NULL;
        *bst = s;
    }
    else if (LT(key, (*bst)->key))
    {
        InsertBST(&((*bst)->lchild), key);
    }
    else if (GT(key, (*bst)->key)))
        {
            InsertBST(&((*bst)->rchild), key);
        }
}

void CreateBST(BSTree *bst)
{
    int key;
    *bst = NULL;
    printf("please enter the number you want to store:\n");
    int number;
    scanf("%d", &number);
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &key);
        getchar();
        InsertBST(bst, key);
    }
}

void InorderBST(BSTree bst)
{
    if (bst != NULL)
    {
        InsertBST(bst->lchild);
        printf("%d->", bst->key);
        InsertBST(bst->rchild);
    }
}

BSTree SearchBST(BSTree bst, int key)
{
    if (bst == NULL)
    {
        return NULL;
    }
    else if (EQ(bst->key, key))
    {
        return bst;
    }
    else if (GT(bst->key, key))
    {
        return SearchBST(bst->lchild, key);
    }
    else
    {
        return SearchBST(bst->rchild, key);
    }
}

bool DeleteBST(BSTree bst, int key)
{
    BSTNode *p, *f, *s, *q;
    p = bst;
    f = NULL;
    while (p)
    {
        if (p->key == key)
        {
            break;
        }
        f = p;
        if (p->key > key)
        {
            p = p->lchild;
        }
        else
        {
            p = p->rchild;
        }
    }
    if (p == NULL)
    {
        return false;
    }
    if (p->lchild == NULL)
    {
        if (f == NULL)
        {
            bst = p->lchild;
        }
        else
        {
            if (f->lchild == p)
            {
                f->lchild = p->rchild;
            }
            else
            {
                f->rchild = p->rchild;
            }
            free(p);
        }
    }
    else
    {
        q = p;
          s = p->lchild;
          while (s->rchild)
        {
               q = s;
               s = s -> rchild;
              
        }
          if (q == p)
   q-> lchild = p -> lchild;
          else    q->rchild = s->lchild;
          p->key = s->key;
          free(s);
         
    }
     return true;
}
int main() 
{
     BSTree T, p;
     int key;
     boolean temp;
     T = NULL;
     CreateBST(&T);
     InorderBST(T);
     printf("请输入你要查找的数据：\n");
     scanf("%d", &key);
     p = SearchBST(T, key);
     if (!p)
    {
        printf("%d 没有找到\n", key);
    }
     else   
    {
        printf("%d 查找成功\n", key);
    }
     printf("请输入你想要删除的数据：\n");
     scanf("%d", &key);
     temp = DeleteBST(T, key);
     if (temp)
    {
          printf("删除成功\n");
          InorderBST(T);
         
    }
     else   
    {
        printf("%d 数据不存在\n");
    }
     return 0;
}