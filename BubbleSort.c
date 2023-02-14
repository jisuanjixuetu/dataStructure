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
void Swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void BubbleSort(SqList *list)
{
    for (int i = MAXSIZE - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (GT(list->r[j].key, list->r[j + 1].key))
            {
                Swap(&(list->r[j + 1].key), &(list->r[j].key));
            }
        }
    }
}
void BubbleSort1(SqList *list)
{
    for (int i = 2; i <= MAXSIZE; i++)
    {
        for (int j = MAXSIZE; j >= i; j--)
        {
            if (LT(list->r[j].key, list->r[j - 1].key))
            {
                Swap(&(list->r[j].key), &(list->r[j - 1].key));
            }
        }
    }
}
int main(void)
{
    SqList list;
    CreateSqList(&list);
    //BubbleSort(&list);
    BubbleSort1(&list);
    for (int i = 1; i <= MAXSIZE; i++)
    {
        printf("%d\t", list.r[i].key);
    }
    return 0;
}