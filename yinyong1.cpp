#include<stdio.h>
void change(int &x){
    x = 1024;
}
int main(){
    int x = 1;
    printf("%d",x);
    change(x);
    printf("%d",x);
    return 0;
}