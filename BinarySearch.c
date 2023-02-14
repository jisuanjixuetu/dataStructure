#include<stdio.h>
#include<stdlib.h>
typedef struct ssTable {
    int *data;
    int length;
}SSTable;
#define EQ(x,y) ((x) == (y))
#define GT(x,y) ((x) > (y))
#define LT(x,y) ((x) < (y))
void CreateSSTable(SSTable *table){
    int length;
    printf("please enter the length of the ssTable you want to create\n");
    scanf("%d",&length);
    table->length = length;
    table->data = (int *)malloc(sizeof(int)*(table->length+1));
    for(int i=0; i < table->length; i++){
        printf("please enter the %d data you want to record\n",i+1);
        scanf("%d",&table->data[i]);
        getchar();
    }
}

int Binary_Search(SSTable *table,int number){
    int middle,low,high;
    low = 0;
    high = table->length-1;
    middle = (low + high)/2;
    while(low <= high){
        if(EQ(number,table->data[middle])){
            return middle;
        }
        else if(GT(number,table->data[middle])){
            high = middle-1;
            middle = (high + low)/2;
        }
        else {
            low = middle+1;
            middle = (high + low)/2;
        }
    }
    return -1;
}

int main(){
    SSTable table;
    int number;
    int tag;
    CreateSSTable(&table);
    printf("please enter the number you want to search:\n");
    scanf("%d",&number);
    tag = Binary_Search(&table,number);
    if(tag != -1){
        printf("it is in the %d position\n",tag+1);
    }
    else {
        printf("it is not in the table\n");
    }
    return 0;
}