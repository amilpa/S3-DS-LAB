#include<stdio.h>

int main()
{
    int len1,len2,i,totl , j , k =0;
    printf("Enter the length of the first set:\n");
    scanf("%d" , &len1);
    int array1[len1];
    printf("Enter the Elements:\n");
    for(i=0 ; i<len1 ; i++)
    {
        scanf("%d" , &array1[i]);
    }
    
    printf("Enter the length of the second set:\n");
    scanf("%d" , &len2);

    totl = len1 + len2 ; 

    int array2[len2];
    int inter[totl];
    printf("Enter the Elements:\n");
    for(i=0 ; i<len2 ; i++)
    {
        scanf("%d" , &array2[i]);
    }


    for(i = 0 ; i<len1 ; i++)
    {
        for(j=0 ; j< len2 ; j++)
        {
            if(array2[j] == array1[i])
            {
                inter[k] = array1[i];
                k++; 
            }
        }
    }

    printf("The intersection of the given two arrays is :\n");


    for(i =0 ; i<k ; i++)
    {
        printf(" %d " , inter[i]);
    }
    
    return 0;

}
