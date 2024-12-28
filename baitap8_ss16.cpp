#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char *inputString = (char *)malloc(100*sizeof(char));
	char *reverseString = (char *)malloc(100*sizeof(char));
	
	char *index_String = (char *)malloc(100*sizeof(char));
	printf("Nhap chuoi: ");
	fgets(index_String, 100, stdin);
	index_String[strcspn(index_String, "\n")] = '\0';
	
	strcpy(inputString, index_String);
	
	printf("Chuoi da nhap: %s\n", inputString);
	
	for (int i = 0; i < strlen(inputString); i++)
	{
        reverseString[i] = inputString[strlen(inputString) - i - 1];
    }
    reverseString[strlen(inputString)] = '\0';

    printf("Chuoi dao nguoc: %s\n", reverseString);

    free(inputString);
    free(reverseString);
    free(index_String);
	
	
	return 0;
}
