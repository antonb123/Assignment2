#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
char name[5];
int value;
} Currency;

void printValues(Currency values[], int size)
{
    for(int i=0; i<size; i++)
    {
        printf("Currency-> %s | Value-> %d\n", values[i].name, values[i].value);
    }
}

int main()
{
    FILE *file = fopen("C:\\code\\c\\kyh\\embedded programming\\embedded_programming\\assignment2\\valutor_2.txt", "r");
    if(!file)
    {
        printf("Error occured");
        return 0;
    }

    Currency values[20];
    int valuesLength = sizeof values / sizeof values[0];


    int i = 0;
    char *field[5];
    char *field_int[4];

    while(fscanf(file, "%s\t%s", field, field_int) != EOF)
    {
        strcpy(values[i].name, field);
        values[i].value = atoi(field_int);
        //printf("%s\t%d\n", values[i].name, values[i].values);

        i++;
    }
    fclose(file);

    printValues(values, valuesLength);

    return 0;
}


