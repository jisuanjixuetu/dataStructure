#include <stdio.h>
#include <stdlib.h>
typedef struct ssTable
{
    int *data;
    int length;
} SSTable;

void createSSTable(SSTable *table)
{
    printf("please enter tbe number of data you want to create\n");
    int n;
    scanf("%d", &n);
    table->length = n;
    table->data = (int *)malloc(sizeof(int) * (table->length) + 1);
    for (int i = 0; i < n; i++)
    {
        printf("please enter the %d data you want to create\n", i + 1);
        scanf("%d", &table->data[i + 1]);
        getchar();
    }
}

int SearchSSTable(SSTable *table, int number)
{
    table->data[0] = number;
    for (int i = table->length; i >= 0; i--)
    {
        if (number == table->data[i])
        {
            return i;
        }
    }
}

int main()
{
    SSTable ssTable;
    createSSTable(&ssTable);
    int number;
    printf("please enter the number you want to search\n");
    scanf("%d", &number);
    int tag;
    tag = SearchSSTable(&ssTable, number);
    if (tag != 0)
    {
        printf("it is in the %d position\n", tag);
    }
    else
    {
        printf("it is not in the table\n");
    }
    return 0;
}