#include<stdio.h>
#include<stdlib.h>

const int MAX_SIZE = 10;

typedef struct node{
    int val;
    struct node* link;
}linlist;

linlist* head = NULL;
int queue[MAX_SIZE];
int front = -1;
int rear = -1;


void EnqueueArray(int val)
{
    if (rear == front)
    {
        printf("Queue is full\n")
    }
    
}

int main(int argc, char const *argv[])
{
    printf("\n!Circular queue operations using linked list and arrays!\n");
    int choice1 , choice2;
    printf("1.Linked list\n");
    printf("2.Array\n");
    printf("Enter the choice:\n");
    scanf("%d" , &choice1);
    if (choice1 == 1)
    {
        int flag=1; 
        while (flag)
        {
            printf("\n1.Enqueue");
            printf("\n2.Dequeue");
            printf("\n3.Display");
            printf("\nEnter the choice:\n");
            scanf("%d" , &choice2);
            if (choice2==1)
            {
                int val;
                printf("Enter the value to insert into the queue:\n");
                scanf("%d" , &val);
                Enqueuelinkedlist(val);
            }
            else if(choice2==2)
            {
                Dequeuelinkedlist();
            }
            else if (choice2==3)
            {
                DisplayLinkedlist();
            }
            else
            {
                printf("Invalid choice\n");
            }
            
            printf("\nDo you want to continue(yes(1) or no(0))?");
            scanf("%d", &flag);
        }
    }
    else if(choice1 ==2)
    {
        int flag=1; 
        while (flag)
        {

            printf("\n1.Enqueue");
            printf("\n2.Dequeue");
            printf("\n3.Display");
            printf("\nEnter the choice:\n");
            scanf("%d", &choice2);
            if (choice2 == 1)
            {
                int val;
                printf("Enter the value to insert into the queue:\n");
                scanf("%d", &val);
                EnqueueArray(val);
            }
            else if (choice2 == 2)
            {
                DequeueArray();
            }
            else if (choice2 == 3)
            {
                DisplayArray();
            }
            else
            {
                printf("Invalid choice\n");
            }
            printf("\nDo you want to continue(yes(1) or no(0))?");
            scanf("%d", &flag);
        }
    }

    else
    {
        printf("\nInvalid choice\n");
    }

    return 0;
}