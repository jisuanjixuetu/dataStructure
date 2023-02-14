#include<stdio.h>
#define MaxSize 10
typedef struct component{
    int data;
    int cur;
}Component,StaticList[MaxSize];
void InitList(StaticList *list){
    for (int i = 0; i < MaxSize-1; i++) {
        (*list)[i].cur=i+1;
    }
    (*list)[MaxSize - 1].cur=0;
}
void CreatList(StaticList *list){
    int k = 1;
    for(int i = 0;i<5;i++){
        printf("please enter the %d data\n",i+1);
        scanf("%d",&((*list)[k].data));
        k=(*list)[k].cur;
    }
    (*list)[k-1].cur=0;
    (*list)[0].cur=k;
    (*list)[MaxSize - 1].cur=1;
}
void print(StaticList *list){
    int i = 1;
    while ((*list)[i].cur != 0) {
        printf("%d\n",(*list)[i].data);
        i = (*list)[i].cur;
    }
    printf("%d\n",(*list)[i].data);
}
int ListLength(StaticList *list){
    int i = (*list)[MaxSize-1].cur;
    int count = 0;
    while ((*list)[i].cur != 0){
        count++;
        i = (*list)[i].cur;
    }
    count++;
    return count;
}

// int Malloc_SLL(StaticList *list){
//     int i = (*list)[0].cur;
//     if((*list)[0].cur!=0){
//         (*list)[0].cur=(*list)[i].cur;
//     }
// }
// void InsertList(StaticList *list,int i,int e){
//     int j,k,l;
//     k = MaxSize-1;
//     if(i<1||i>ListLength(list)+1){
//         printf("error\n");
//     }
//     j = Malloc_SLL(list);
//     if(j != 0){
//         (*list)[j].data = e;
//         for(l = 1;l <= i-1;i++){
//             k = (*list)[k].cur;  
//         }
//         (*list)[j].cur = (*list)[k].cur;
//         (*list)[k].cur = j;
//     }
// }
void Free_SLL(StaticList*list,int k){
    (*list)[k].cur=(*list)[0].cur;
    (*list)[0].cur=k;
}
void DeleteList(StaticList *list,int i){
    int j,k;
    if(i<1 || i>ListLength(list)){
        printf("reeoe\n");
    }
    k = MaxSize-1;
    for(j = 1;j<=i-1;j++){
        k = (*list)[k].cur;
    }
    j = (*list)[k].cur;
    (*list)[k].cur = (*list)[j].cur;
}
int main(){
    StaticList list;
    InitList(&list);
    CreatList(&list);
    // InsertList(&list,3,9);
    DeleteList(&list,3);
    print(&list);
    return 0;
}