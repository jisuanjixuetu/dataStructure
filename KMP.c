#include <stdio.h>
#include <stdlib.h>
#define MaxSize 255
typedef unsigned char SString[MaxSize+1];
int lengthen(SString s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}
int KMP(SString momString,SString subString,int *next){
    int i = 1;
    int j = 1;
    while(i <= lengthen(momString)&& j<= lengthen(subString)){
        if(j == 0 || momString[i] == subString[j]){
            i++;
            j++;
        }
        else{
            j = next[j];
        }
        if(j > lengthen(subString)){
            return i - lengthen(subString);
        }
        else {
            return 0 ;
        }
    }
}
void get_next(SString t,int **next){
    int i = 1;
    (*next)[0] = -1;
    (*next)[1] = 0;
    int j = 0;
    while(i < lengthen(t)){
        if(j == 0 || t[i] == t[j]){
            i++;
            j++;
            (*next)[i] = j;
        }
        else {
            j = (*next)[j];
        }
    }
}
int main(){
    SString a1,a2;
    printf("please enter the first string\n");
    scanf("%s",a1);
    printf("please enter the second string\n");
    scanf("%s",a2);
    int *next;
    next = (int *)malloc(sizeof(int)*(lengthen(a2)+1));
    get_next(a2,&next);
    for (int i = 0; i < (lengthen(a2)+1);i++){
        printf("%d\t",next[i]);
    }
}