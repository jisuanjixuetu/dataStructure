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

int Partition(SqList *list, int low, int high)
{
    list->r[0].key = list->r[low].key;
    int pivotkey = list->r[low].key;
    while (low < high)
    {
        while (low < high && list->r[high].key >= pivotkey)
        {
            high--;
        }
        list->r[low].key = list->r[high].key;
        while (low < high && list->r[low].key <= pivotkey)
        {
            low++;
        }
        list->r[high].key = list->r[low].key;
    }
    list->r[low].key = list->r[0].key;
    return low;
}

void QSort(SqList *list, int low, int high)
{
    if (low < high)
    {
        int pivotloc = Partition(list, low, high);
        QSort(list, low, pivotloc - 1);
        QSort(list, pivotloc + 1, high);
    }
}

int main()
{
    SqList list;
    CreateSqList(&list);
    QSort(&list, 1, 10);
    for (int i = 1; i <= MAXSIZE; i++)
    {
        printf("%d\t", list.r[i]);
    }
    return 0;
}