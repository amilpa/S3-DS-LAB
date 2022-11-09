#include <stdio.h>
#include <stdlib.h>

int stack[20] = {0};
int top1 = -1;
int top2 = 20;

void push(int sta)
{
    if (sta == 1)
    {
        if (top1 == 9)
        {
            printf("Stack overflow\n");
        }
        else
        {

            int val;
            printf("Enter the value to push into the stack:\n");
            scanf("%d", &val);
            top1 = top1 + 1;
            stack[top1] = val;
        }
    }

    else if (sta == 2)
    {

        if (top2 == 10)
        {
            printf("Stack overflow\n");
        }
        else
        {

            int val;
            printf("Enter the value to push into the stack:\n");
            scanf("%d", &val);
            top2 = top2 - 1;
            stack[top2] = val;
        }
    }

    else
    {
        printf("Invalid choice\n");
    }
}

void pop(int sta)
{
    if (sta == 1)
    {
        if (top1 == -1)
        {
            printf("Stack is empty\n");
        }

        else
        {
            printf("%d is deleted\n" , stack[top1]);
            top1--;
        }
    }
    else if(sta==2)
    {

        if (top2 == 20)
        {
            printf("Stack is empty\n");
        }

        else
        {
            printf("%d is deleted\n" , stack[top2]);
            top2++;
        }
    }
    else
    {
        printf("Invalid choice\n");
    }
}

void display()
{

    printf("\nStack 1\n");
    if (top1 == -1)
    {
        printf("Stack is empty\n");
    }

    else
    {
        printf("The stack elements are:\n");
        for (int i = 0; i <= top1; i++)
        {
            printf("%d ", stack[i]);
        }
    }
    printf("\n\nStack 2\n");

    if (top2 == 20)
    {
        printf("Stack is empty\n");
    }

    else
    {
        printf("\nThe stack elements are:\n");
        for (int i = 19; i >= top2; i--)
        {
            printf("%d ", stack[i]);
        }
    }
    printf("\n");
}



int main(int argc, char *argv[])
{
    int flag = 1;
    int choice;
    int sta;

    printf("!Program for stack operations!\n");
    while (flag)
    {
        printf("1.Push into stack\n");
        printf("2.Pop from stack\n");
        printf("3.Display the stack\n");
        printf("Enter the choice:\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Push into stack 1 or 2\n");
            scanf("%d", &sta);
            push(sta);
        }
        else if (choice == 2)
        {

            printf("Pop from stack 1 or 2\n");
            scanf("%d", &sta);
            pop(sta);
        }

        else if (choice == 3)
        {
            display();
        }

        else
        {
            printf("Invalid choice\n");
        }

        printf("Do you want to continue(Yes(1) or no(0))?\n");
        scanf("%d", &flag);
    }

    return 0;
}
