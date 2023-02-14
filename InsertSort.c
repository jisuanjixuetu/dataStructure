#include <stdio.h>
#define MAXSIZE 10
#define EQ(x, y) ((x) == (y))
#define GT(x, y) ((x) > (y))
#define LT(x, y) ((x) < (y))
typedef int KeyType;
typedef int InfoType;
typedef struct
{
    KeyType key;
    InfoType info;
} RedType;

typedef struct
{
    RedType r[MAXSIZE + 1];
    int length;
} SqList;
void CreateSqList(SqList *list)
{
    for (int i = 1; i <= MAXSIZE; i++)
    {
        printf("please enter the %d data of the list:\n", i);
        scanf("%d", &list->r[i].key);
        getchar();
    }
}
void InsertSort(SqList *list)
{
    for (int i = 2; i <= MAXSIZE; i++)
    {
        if (LT(list->r[i].key, list->r[i - 1].key))
        {
            list->r[0].key = list->r[i].key;
            list->r[i].key = list->r[i - 1].key;
            int j;
            for (j = i - 2; LT(list->r[0].key, list->r[j].key); j--)
            {
                list->r[j + 1].key = list->r[j].key;
            }
            list->r[j + 1].key = list->r[0].key;
        }
    }
}

int main(){
    SqList list;
    CreateSqList(&list);
    InsertSort(&list);
    for(int i = 1;i <= MAXSIZE;i++){
        printf("%d\t",list.r[i].key);
    }
    return 0;
}