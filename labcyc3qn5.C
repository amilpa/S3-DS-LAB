#include<stdio.h>
#include<stdlib.h>

int stack[100];
int top = -1;

void converttobin(int deci)
{
    while(deci!=0)
    {
        stack[++top] = deci%2;
        deci = deci/2;
    }

    printf("\nThe binary number is:\n");

    while(top!=-1)
    {
        printf("%d" , stack[top]);
        top--;
    }
    printf("\n");
    
}

void converttohex(int deci)
{
    while(deci!=0)
    {
        stack[++top] = deci%16;
        deci = deci/16;
    }

    printf("\nThe hexadecimal number is:\n");

    while (top != -1)
    {
        switch (stack[top])
        {
            case 10:
                printf("A");
                break;

            case 11:
                printf("B");
                break;

            case 12:
                printf("C");
                break;

            case 13:
                printf("D");
                break;

            case 14:
                printf("E");
                break;

            case 15:
                printf("F");
                break;

            default:
                printf("%d", stack[top]);
                break;
        }
        top--;
    }
    printf("\n");
    
}


int main()
{
    printf("\n!Program to convert decimal to binary and hexa!\n");
    int flag=1;
    int deci;
    while(flag)
    {
        printf("Enter the decimal value to convert:\n");
        scanf("%d" , &deci);
        converttobin(deci);
        converttohex(deci);
        printf("\nDo you want to continue?(Yes(1) or No(0))\n");
        scanf("%d" , &flag);
    }
    return 0;
}
