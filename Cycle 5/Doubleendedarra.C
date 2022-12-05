#include<stdio.h>

//Queue declaration
const int MAX_SIZE = 10;

int dqueue[MAX_SIZE];
int front1 = -1;
int rear1 = -1;
int front2 = MAX_SIZE-1;
int rear2 = MAX_SIZE-1;

void insertatfront(int val)
{
    if((rear1+1)==rear2)
    {
        printf("Queue is full\n");
    }
    else if(front1==rear1==-1)
    {
        front1 = rear1 = 0;
        dqueue[front1] = val ; 
    }
    else
    {
        rear1++;
        dqueue[rear1] = val;
    }
}

void insertatend(int val)
{
    if((rear2-1)==rear1)
    {
        printf("Queue is full\n");
    }
    else if(front2==rear2==MAX_SIZE-1)
    {
        front2 = rear2 = MAX_SIZE-2;
        dqueue[front2] = val ; 
    }
    else
    {
        rear2--;
        dqueue[rear2] = val;
    }
}

void deleteatfront()
{
    if(front)
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
