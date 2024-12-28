#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int number_1 = rand() % 100;
	int number_2 = rand() % 100;
	
	printf("Gia tri cua numbers1 truoc: %d\n", number_1);
	printf("Gia tri cua numbers2 truoc: %d\n", number_2);
	
	swap(&number_1, &number_2);
	
	printf("Gia tri cua numbers1 sau: %d\n", number_1);
	printf("Gia tri cua numbers2 sau: %d\n", number_2);
	
	
	return 0;
}
