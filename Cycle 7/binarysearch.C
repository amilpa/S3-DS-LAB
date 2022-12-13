#include <stdio.h>


int binarysearch(int low , int high , int* arra , int val)
{
	int mid;
	while (low<=high) {
		mid = ( low + high ) / 2;
		if(arra[mid]==val)
		{
			return mid;
		}
		else if (arra[mid]>val) {
			high = mid-1;
		}
		else {
		    low = mid+1;
		}
	}
	return -1;
}

int main ()
{
	int len,val,pos;
	printf("Enter the number of elements for the array:\n");
	scanf("%d" , &len);
	int array[len];
	printf("Enter the elements:\n");
	for (int i=0 ; i<len ; i++) {
		scanf("%d" , &array[i]);
	}
	printf("Enter the value to find in the array:\n");
	scanf("%d" , &val);
	pos = binarysearch(0, len-1, array, val);
	if (pos==-1) {
		printf("Item not found\n");
	}
	else {
		printf("Element found at position %d\n" , pos+1);
	}
	return 0;
}
