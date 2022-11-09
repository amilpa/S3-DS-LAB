#include<stdio.h>


int main()
{
    int len,i,j,sum ,maxcount = 0 , mode , temp;
    float mean,median;
    printf("Enter the length of the array:\n");
    scanf("%i" , &len);
    int array[len];
    printf("Enter the elements(integers only):\n");
    for(i=0; i<len ; i++)
    {
        scanf("%i" , &array[i]);
    }
    printf("!Array created!\n");
    for(i=0; i<len ; i++)
    {
        sum+= array[i];
    }
    mean = (float)sum / len;
    printf("Mean of the given array (integer part) is:  %.2f \n" , mean);

    for(i=0 ; i<len ; i++)
    {
        for(j = 0 ; j<len-i-1 ; j++)
        {
            if(array[j]> array[j+1] )
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    if(len%2==0)
    {
        median = array[len/2]+ (float)array[len/2-1] / 2.00;
    }
    else
    {
        median = array [ (len + 1 ) /2 - 1 ];
    }
    printf("Median of the given array is: %.2f \n" , median);
    for(i=0; i<len ; i++)
    {
        int count = 0;
        for(j=0 ; j<len ; j++)
        {
                if(array[j] == array [i])
                {
                    count++;
                }
        }
        if(count> maxcount)
        {
            maxcount =  count;
            mode = array[i];
        }
        
    }
    
    if(maxcount ==1)
    {
        printf("No element repeats in this array\n");
    }
    
    
    else
    {
        printf("Mode of the given array is: %i \n" , mode);
    }
    
    
    return 0;
    
}
