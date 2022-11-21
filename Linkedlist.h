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
    while(head!=NULL)
    {
        printf("%d ", head->value);
        head = head->link;
    }
    printf("\n");
}

