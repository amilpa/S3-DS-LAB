#include<stdio.h>
#include<stdlib.h>

//Queue declaration
typedef struct node
{
    int val;
    struct node* link;
}linlist;

linlist* front = NULL ;
linlist* rear = NULL ;

void Insertatfront(int val)
{
    linlist* temp = (linlist* ) malloc(sizeof(linlist));
    temp->val = val;
    temp->link = NULL;
    if(front==NULL)
    {
        front = temp ;
        rear = temp;
    }
    else
    {
        linlist* ptr = front;
        while(ptr->link!=NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = temp;
        rear = temp;
    }
}

void Deleteatfront()
{
    if(front==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        front = front->link;
    }
}

void Insertatrear(int val)
{
    linlist* temp = (linlist*)malloc(sizeof(linlist));
    temp->val = val;
    if(front==NULL)
    {
        temp->link = NULL;
        front = temp;
    }
    else
    {
        temp->link = front;
        front = temp;
    }
}

void Deleteatrear()
{
    if(front==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        linlist* ptr = front;
        while(ptr->link!=NULL)
        {
            ptr = ptr->link ;
        }
        ptr = NULL;
    }
}

void Display()
{
    if(front==NULL)
    {
        printf("Queue is empty\n");
    }

    else
    {
        printf("The elements are\n");
        linlist* ptr = front;
        while(ptr!=NULL)
        {
            printf( "%d " , ptr->val);
        }
    }
}

int main(int argc, char const *argv[])
{
    int flag = 1;
    int choice;
    while (flag)
    {
        printf("\n1.Insert at front");
        printf("\n2.Delete at front");
        printf("\n3.Insert at rear");
        printf("\n4.Delete at rear");
        printf("\n5.Diplay");
        printf("\nEnter the choice:\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int val;
            printf("Enter the value to insert into the queue:\n");
            scanf("%d", &val);
            Insertatfront(val);
        }
        else if (choice == 2)
        {
            Deleteatfront();
        }
        else if (choice == 3)
        {
            int val;
            printf("Enter the value to insert into the queue:\n");
            scanf("%d", &val);
            Insertatrear(val);
        }
        else if (choice == 4)
        {
            Deleteatrear();
        }
        else if (choice == 5)
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
