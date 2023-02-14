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
    list->length = MAXSIZE;
}
void HeapAdjust(SqList *list,int s,int m){
    int rc = list->r[s].key;
    for(int j = 2*s;j<=m; j*=2){
        if(j<m&&LT(list->r[j].key,list->r[j+1].key)){
            j++;
        }
        if(!LT(rc,list->r[j].key)){
            break;
        }
        list->r[s].key = list->r[j].key;
        s = j;
    }
    list->r[s].key = rc;
}
void Swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void HeapSort(SqList*list){
    for(int i = list->length/2;i>0; i--){
        HeapAdjust(list,i,list->length);
    }
    for(int i = list->length;i>1; i--){
        Swap(&(list->r[i].key),&(list->r[1].key));
        HeapAdjust(list,1,i-1);
    }
}

int main(){
    SqList list;
    CreateSqList(&list);
    HeapSort(&list);
    for(int i = 1;i<list.length;i++){
        printf("%d\t",list.r[i].key);
    }
}