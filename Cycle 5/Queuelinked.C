#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node* link;
}linlist;

linlist* front = NULL;

void Enqueue(int val)
{
    if(front==NULL)
    {
        linlist* temp = (linlist* )malloc(sizeof(linlist));
        temp->val = val;
        temp->link = NULL;
        front = temp;
    }
    else
    {
        linlist* temp = front ;
        while (temp->link!=NULL)
        {
            temp = temp->link;
        }
        linlist* temp1 = (linlist* )malloc(sizeof(linlist));
        temp1->val  = val;
        temp1->link = NULL ; 
        temp->link = temp1;
    }
}

void Dequeue()
{
    if(front==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("%d is deleted\n" , front->val);
        front = front->link ;
    }
}

void Display()
{
    if(front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("The Queue elements are:\n");
        linlist* temp = front;
        while (temp!=NULL)
        {
            printf("%d " , temp->val);
            temp = temp->link;
        }
        printf("\n");
    }
}

int main()
{
    int flag = 1;
    int choice;
    while (flag)
    {
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display");
        printf("\nEnter the choice:\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int val;
            printf("Enter the value to insert into the queue:\n");
            scanf("%d", &val);
            Enqueue(val);
        }
        else if (choice == 2)
        {
            Dequeue();
        }
        else if (choice == 3)
        {
            Display();
        }
        else
        {
            printf("Invalid choice\n");
        }

        printf("\nDo you want to continue(yes(1) or no(0))?");
        scanf("%d", &flag);
    }
    return 0;
}
