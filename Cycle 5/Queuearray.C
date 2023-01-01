#include<stdio.h>


const int MAX_SIZE = 3;

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void Enqueue(int val)
{
    if(rear+1==MAX_SIZE)
    {
        printf("Queue is full\n");
    }
    
    else if(front==-1)
    {
        front++;
        queue[++rear] = val ;
    }
    else
    {
        queue[++rear] = val;
    }
    
}
void Dequeue()
{
    if (front==-1)
    {
        printf("Queue is empty\n");
    }
    
    else if (front == rear)
    {
        printf("%d is deleted" , queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("%d is deleted" , queue[front]);
        front++;
    }
}

void Display()
{
    if (front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("The queue elements are:\n");
        for(int i = front ; i <=rear ; i++)
        {
            printf("%d " , queue[i]);
        }
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
        scanf("%d" , &choice);
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
