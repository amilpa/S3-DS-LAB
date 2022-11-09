#include<stdio.h>
#include<string.h>

int main()
{
	int len;int freq[256] ={0};
	printf("Enter the length of the string:\n");
	scanf("%i" , &len);
	char s[len];
	scanf("%s" , s);
	len = strlen(s);

	for(int i =0; s[i] != '\0' ; i++)
	{
		freq[s[i]]++;
	}

	printf("The frequency of each charecter is:\n");

	for(int i =0 ; i<256 ; i++)
	{
		if(freq[i] != 0)
		{
			printf("%c - %i\n" , i , freq[i]);
		}
	}
	return 0;


}
