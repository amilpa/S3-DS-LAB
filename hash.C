#include<stdio.h>
#include<stdlib.h>

// item in hash table
typedef struct node{
    int key;
    int value;
}item;

// hash table structure
typedef struct dat
{
    int flag;
    item* data;
}hash_item;

int size = 0;
const int max = 3;

hash_item array[max];

//initialize array
void init_array(){
    for (int i = 0; i < max; i++)
    {
        array[i].flag = 0;
        array[i].data = NULL;
    }
}

//find size of hash table
int size_of_hash(){
    return size;
}

int hashcode(int key)
{
    return key%max;
}


//insert into hash table
void insert(int key,int value)
{
    int index = hashcode(key);
    int i = index;

    item* new_item = (item*)malloc(sizeof(item));
    new_item->key = key;
    new_item->value = value;

    //traversing until we find a non-empty slot
    while (array[i].flag==1)
    {
        if (array[i].data->key == key)
        {
            printf("Key already exists , so updating its value\n");
            array[i].data->value = value;
            return;
        }
        i = (i+1)%max;
        //i is at index after starting from index and going around the array
        if (i==index)
        {
            printf("hash table is full no slot is left\n");
            return;
        }
    }
    array[i].flag=1;
    array[i].data = new_item;
    size++;
    printf("Key (%d) has been inserted\n",key);
    return;
}

void remove_element(int key)
{
    int index = hashcode(key);
    int i = index;

    // continuously traversing until you reach an empty space where not even one element has been present 
    while(array[i].flag!=0)
    {
        if(array[i].flag==1 && array[i].data->key==key)
        {
            //deleting after getting a match
            array[i].flag = 2;
            array[i].data = NULL;
            size--;;
            printf("\n(%d) has been removed\n" , key);
            return;
        }
        i = (i+1) % max ;
        if (i == index)
        {
            break;
        }
    }
    printf("The key does not exist\n");
}

//displaying the hash table 
void display()
{
    int i;
    for (int i = 0; i < max; i++)
    {
        item* current = array[i].data;

        if (current==NULL)
        {
            printf("%d -: No elements exist\n" , i);
        }
        else{
            printf("%d -: Key: %d and Value: %d\n" ,i, current->key , current->value);
        }
        
    }
    
}

//main function
int main()
{
    int choice,value,key;
    int flag = 1;

    init_array();

    while(flag)
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display the size\n");
        printf("4.Display\n");
        printf("Enter the choice\n");
        scanf("%d" ,  &choice);

        switch (choice)
        {
            case 1:
            {
                printf("Enter the key and value:\n");
                scanf("%d %d", &key , &value);
                insert(key,value);
                break;
            }
            case 2:
            {
                printf("Enter the key to delete:\n");
                scanf("%d" , &key);
                remove_element(key);
                break;
            }
            case 3:
            {
                printf("Size is: %d\n",size_of_hash());
                break;
            }
            case 4:
            {
                display();
                break;
            }
            default:
            {
                printf("Invalid choice\n");
            }
        }
        printf("Do you want to continue(yes(1) or no(0))?");
        scanf("%d" , &flag);
    }
}