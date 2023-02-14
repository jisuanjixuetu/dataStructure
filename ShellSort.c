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

void ShellSort(SqList *list, int dk)
{
    for (int i = dk; i >= 1; i = i / 2)
    {
        for (int j = i + 1; j <= MAXSIZE; j++)
        {
            if (LT(list->r[j].key, list->r[j - i].key))
            {
                list->r[0].key = list->r[j].key;
                int k;
                for (k = j - i; k > 0 && LT(list->r[0].key, list->r[k].key); k -= i)
                {
                    list->r[k + i].key = list->r[k].key;
                }
                list->r[k + i].key = list->r[0].key;
            }
        }
    }
}

int main()
{
    SqList list;
    CreateSqList(&list);
    ShellSort(&list, 4);
    for (int i = 1; i <= MAXSIZE; i++)
    {
        printf("%d\t", list.r[i].key);
    }
    return 0;
}