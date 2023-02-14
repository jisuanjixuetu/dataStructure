#include<stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef int *ElemType;
typedef struct{
    ElemType data;
    int length;
}SqList;
// void IncreaseSize(SqList *list,int len){
//     list->data = (ElemType)realloc(list->data,sizeof(int)*(MaxSize+len));
// }
void InitList(SqList *list){
    list->data = (ElemType)malloc(sizeof(int)*MaxSize);
    // for (int i = 0; i <MaxSize; i++){
    //     list->data[i] = 0;
    // }
    // list->length=0;
    list->length = 5;
    printf("please enter some numbers\n");
    for(int i = 0;i<list->length; i++){
        scanf("%d",&list->data[i]);
        getchar();
    }
}
void ListInsert(SqList *list,int i,int e){
    for(int j = list->length;j>=i; j--)
        list->data[j] = list->data[j-1];
    list->data[i-1] = e;
    list->length++;
}
int main(){
    SqList list;
    InitList(&list);
    // IncreaseSize(&list,5);
    // for (int i = 0; i < MaxSize+5; i++) {
    //     printf("%d\n",list.data[i]);
    // }
    ListInsert(&list,3,3);
    for (int i = list.length; i >= 0; i--){
        printf("%d\n",list.data[i]);
    }
    return 0;
}