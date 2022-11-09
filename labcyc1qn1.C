#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int arrayrotate(int *array,int len,char chose , int cou);

int main()
{
    int len;char chose;int cou;
    printf("Enter the length of the array:\n");
    scanf("%i" , &len);
    int array[len];
    printf("Enter the elements:\n");
    for(int i=0; i<len ; i++)
    {
        scanf("%i" , &array[i]);
    }
    printf("how many times do you want to rotate the array? and in which direction do you want to rotate the array?\n");
    scanf("%i %c" , &cou , &chose);
    arrayrotate(array,len,chose ,cou );
    printf("!Array has been rotated!\n");
    for(int i=0; i<len ; i++)
    {
        printf("%i" , array[i]);
    }
    printf("\n");
    return 0;

}


int arrayrotate(int *array,int len,char chose , int cou)
{
    int temp,i,j;
    if(chose == 'r' || chose =='R')
    {   for(int h=0;h<cou ; h++)
        {
            temp = array[0];
            for(j=0;j<len-1;j++)
            {
                array[j] = array[j+1];
            }
            array[len-1] = temp ;                
        }
    }
    else if (chose == 'l' || chose =='L')
    {      
        for(int h=0;h<cou ; h++)
        {
                
            temp = array[len-1];  
            for(j=len-1;j>=0;j--)
            {
                array[j] = array[j-1];
            }
            array[0] = temp ;     
                
        }      
    }
    else
    {
        printf("Invalid response\n");
        exit(1);
    }
    return 0;
       
}
