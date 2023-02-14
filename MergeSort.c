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

void Merge(SqList *list, SqList temp, int low, int mid, int high)
{
    int i, j, k;
    for (k = low; k <= high; k++)
    {
        temp.r[k].key = list->r[k].key;
    }
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (temp.r[i].key <= temp.r[j].key)
        {
            list->r[k].key = temp.r[i++].key;
        }
        else
        {
            list->r[k].key = temp.r[j++].key;
        }
    }
    while (i <= mid)
    {
        list->r[k++].key = temp.r[i++].key;
    }
    while (j <= high)
    {
        list->r[k++].key = temp.r[j++].key;
    }
}

void MergeSort(SqList *list, SqList temp, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(list, temp, low, mid);
        MergeSort(list, temp, mid + 1, high);
        Merge(list, temp, low, mid, high);
    }
}

int main()
{
    SqList *list, temp;
    CreateSqList(list);
    MergeSort(list, temp, 1, MAXSIZE);
    for (int i = 1; i <= MAXSIZE; i++)
    {
        printf("%d\t", list->r[i].key);
    }
}