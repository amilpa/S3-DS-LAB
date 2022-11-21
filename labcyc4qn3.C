#include "Linkedlist.h"

void insertat(linklist **head , int data)
{
    int flag = 0;
    linklist *ptr = *head;
    if(*head==NULL)
    {
        printf("Linked list has no values\n");
        return;
    }
    else
    {
        while(ptr!=NULL)
        {
            if(ptr->value == data)
            {
                flag = 1;
                break;
            }
            ptr = ptr->link;
        }
    }

    if (flag)
    {
        int value;
        linklist *temp = (linklist *)malloc(sizeof(linklist));
        printf("Enter the value to insert into the linked list\n");
        scanf("%d", &value);
        temp->value = value;
        temp->link = ptr;
        ptr = temp; 
    }
    else
    {
        printf("Given data is not in the linked list\n");
    }
}



int main(int argc, char const *argv[])
{
    printf("\n!Program to do linked list operations!\n");
    int cont =1;
    int choice;
    linklist *head = NULL;
    while(cont)
    {
        printf("1.Insert into linked list\n");
        printf("2.Insert into linked list before a specific node\n");
        printf("3.Display\n");
        printf("Enter the choice:\n");
        scanf("%d" , &choice);
        if(choice==1)
        {
            insert(&head);
        }
        else if(choice == 2)
        {
            int val;
            printf("Enter the value before which new node has to be inserted:\n");
            scanf("%d" , &val);
            insertat(&head , val);
        }
        else if(choice==3)
        {
            display(head);
        }
        else
        {
            printf("Invalid choice\n");
        }
        printf("Do you want to continue?(yes(1) or no(0):\n");
        scanf("%d", &cont);
    }
    return 0;
}
