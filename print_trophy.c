#include <stdio.h>

void print_rectangle(int size);

void print_triangle(int size);

void print_line(int size);

void print_arrow(int size);


int main(void)
{
    int input;

    printf("input : ");
    scanf("%d",&input);

    if(input < 0)
    {
        printf("INPUT RANGE ERROR\n");
        return 1;
    }
        

    print_arrow(input);
    print_rectangle(input);
    print_triangle(input);
    print_line(input);


    return 0;
}


void print_rectangle(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size * 2; j++)
            printf("*");
        printf("\n");
    }
}

void print_triangle(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i; j++)
            printf(" ");

        for( int k = 0; k < 2*(size - i); k++)
            printf("*");

        printf("\n");
    }
}

void print_line(int size)
{
    for (int i = 0; i < size * 2; i++)
        printf("*");
    printf("\n");
}

void print_arrow(int size)
{
    for(int i = 0; i < size ; i++)
    {
        for(int j = 0; j < size *2; j++)
        {
            if(i == j || size * 2 - i -1 == j)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}