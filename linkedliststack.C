#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int val;
    struct node* link;
}linlist;

linlist *head = NULL;
int ind =  0;

void push(int val)
{
    linlist* temp = (linlist*)malloc(sizeof(linlist));
    temp->val = val ; 
    if(head == NULL)
    {
        temp->link = NULL;
        head = temp;
    }
    else
    {
        temp->link = head;
        head = temp;
    }
    ind++;
}

void pop()
{
    if(head==NULL)
    {
        printf("\nStack underflow\n");
    }
    else
    {
        printf("\n%d is deleted\n" , head->val);
        head = head->link;
        ind--;
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\nStack underflow\n");
    }
    else
    {
        int i = 0;
        int array[ind];
        linlist* temp = head;
        printf("\nThe stack elements are:\n");
        while(temp!=NULL)
        {
            array[i] = temp->val;
            temp = temp->link;
            i++;
        }
        for(i = ind-1 ; i>=0 ; i--)
        {
            printf("%d " , array[i]);
        }
    }
}



int main()
{
    printf("\n!Stack using linked list!\n");
    int flag = 1;
    int choice;
    int val;
    while (flag)
    {
        printf("1.Push into the stack\n");
        printf("2.Pop from the stack\n");
        printf("3.Display the stack\n");
        printf("Enter the choice:\n");
        scanf("%d" , &choice);
        if (choice ==1)
        {
            printf("Enter the value to push into the stack:\n");
            scanf("%d" , &val);
            push(val);
        }

        else if(choice==2)
        {
            pop();
        }

        else if (choice==3)
        {
            display();
        }

        else
        {
            printf("\nInvalid choice\n");
        }
        
        printf("\nDo you want to continue(yes(1) or no(0))?\n");
        scanf("%d" , &flag);
    }
    return 0;
}