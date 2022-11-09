#include <stdio.h>
#include <stdlib.h>

int stack[10]={0};
int top = -1;


void sortedinsert(int x)
{
    if(top==-1 || x>stack[top])
    {
        top++;
        stack[top] = x;
        return;
    }

    int temp = stack[top];
    top--;
    sortedinsert(x);
    top++;
    stack[top] = temp;

}

void sortstack()
{
    if(top!=-1)
    {
        int x = stack[top];
        top--;
        sortstack();

        sortedinsert(x);

    }
}

void push()
{
  if(top==9){
    printf("Stack overflow\n");
  }

  else
  {

    int val;
    printf("Enter the value to push into the stack:\n");
    scanf("%d", &val);
    top = top + 1;
    stack[top] = val;
  }
}


void pop(){
  if(top ==-1)
  {
    printf("Stack is empty\n");
  }

  else{
    printf("%d is deleted\n" , stack[top]);
    top--;
  }
}

void display()
{

  if(top ==-1)
  {
    printf("Stack is empty\n");
  }

  else{
    printf("\nThe stack elements are:\n");
    for(int i=0 ; i<=top ; i++)
    {
      printf("%d " , stack[i]);
    }
  }
  printf("\n");
}


int main(int argc, char *argv[]) {
  int flag = 1;
  int choice;



  printf("!Program for stack operations!\n");
  while (flag) {
    printf("1.Push into stack\n");
    printf("2.Pop from stack\n");
    printf("3.Display the stack\n");
    printf("Enter the choice:\n");
    scanf("%d", &choice);
    if(choice==1){
      push();
      sortstack();
    }
    else if(choice == 2){

      pop();
    }

    else if(choice == 3){
      display();

    }

    else{
      printf("Invalid choice\n");
    }


    printf("Do you want to continue(Yes(1) or no(0))?\n");
    scanf("%d" , &flag);
  }

  return 0;
}
