#include <stdio.h>
#include <stdlib.h>
#define MaxSize 255
typedef unsigned char SString[MaxSize + 1];
int lengthen(SString s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}
void StrAssign(SString *destiantion, SString origin)
{
    int length = lengthen(origin);
    for (int i = 0; i < length; i++)
    {
        (*destiantion)[i] = origin[i];
    }
    (*destiantion)[length] = '\0';
}
int StrCom(SString first, SString last)
{
    for (int i = 0; i < lengthen(first) && i < lengthen(last); i++)
    {
        if (first[i] != last[i])
        {
            return first[i] - last[i];
        }
    }
    return lengthen(first) - lengthen(last);
}
void SubString(SString *SubString, SString s, int pos, int len)
{
    for (int i = 0; i < len; i++)
    {
        (*SubString)[i] = s[i + pos - 1];
    }
    (*SubString)[len] = '\0';
}
void ConCat(SString *t, SString s1, SString s2)
{
    int lenght1 = lengthen(s1);
    int lenght2 = lengthen(s2);
    for (int i = 0; i < lenght1; i++)
    {
        (*t)[i] = s1[i];
    }
    for (int i = 0; i < lenght2; i++)
    {
        (*t)[i + lenght1] = s2[i];
    }
    (*t)[lenght1 + lenght2] = '\0';
}
int Index(SString momString, SString subString)
{
    int i, j;
    i = j = 1;
    while (i <= lengthen(momString) && j <= lengthen(subString))
    {
        if (momString[i - 1] == subString[j - 1])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > lengthen(subString))
    {
        return i - lengthen(subString);
    }
    else
    {
        return 0;
    }
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
        if(j == 0 || t[i-1] == t[j]){
            i++;
            j++;
            (*next)[i] = j;
        }
        else {
            j = (*next)[j];
        }
    }
}
int main()
{
    SString s;
    printf("please enter a string\n");
    scanf("%s", s);
    SString des;
    StrAssign(&des, s);
    printf("%s\n", des);
    SString first;
    SString last;
    printf("please enter the first string\n");
    scanf("%s", first);
    printf("please enter the last string\n");
    scanf("%s", last);
    printf("%d\n", StrCom(first, last));
    printf("please enter the main string\n");
    SString momStirng;
    scanf("%s", momStirng);
    SString subString;
    SubString(&subString, momStirng, 2, 4);
    printf("%s\n", subString);
    printf("please enter the s1\n");
    SString s1, s2;
    scanf("%s", s1);
    printf("please enter the s2\n");
    scanf("%s", s2);
    SString t;
    ConCat(&t, s1, s2);
    printf("%s\n", t);
    SString a1, a2;
    printf("please entet the a1\n");
    scanf("%s", a1);
    scanf("%s", a2);
    printf("%d\n", Index(a1, a2));
    int *next;
    next = (int*)malloc((lengthen(a2)+1)*sizeof(int));
    get_next(a2,&next);
    for (int i = 0; i < (lengthen(a2)+1);i++){
        printf("%d\t",next[i]);
    }
    printf("%d\n",KMP(a1,a2,next));
    return 0;
}
