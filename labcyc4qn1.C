#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node* link;
}linklist;

void insert(linklist **head)
{
    int value;
    linklist *ptr = *head;
    linklist *temp = (linklist *)malloc(sizeof(linklist));
    printf("Enter the value to insert into the linked list\n");
    scanf("%d", &value);
    temp->value = value;
    temp->link = NULL;
    if(*head==NULL)
    {
        *head = temp;
    }
    else
    {
        while(ptr->link!=NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = temp;
    }

}


void display(linklist* head)
{
    printf("\nThe elements of the linked list are:\n");
    // printf("%d " , head->value);
    // printf("%d " , head->link->value);
    do
    {
        printf("%d " , head->value);
        head = head->link;
    }
    while(head->link!=NULL);
    printf("\n");
}

int main()
{
    printf("\n!Program to do linked list operations!\n");
    linklist* head = NULL;
    int flag = 1;
    while(flag)
    {
        insert(&head);
        insert(&head);
        display(head);
        printf("Do you want to continue?(Yes(1) or no(0))\n");
    }

}
