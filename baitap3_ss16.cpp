#include<stdio.h>
#include<stdlib.h>

int sum(int *a, int *b)
{
	
	return *a + *b;
}

int main()
{
	int number_1 = rand() % 100;
	int number_2 = rand() % 100;
	
	printf("Gia tri cua numbers1 truoc: %d\n", number_1);
	printf("Gia tri cua numbers2 truoc: %d\n", number_2);
	
	printf("Goi ham tinh tong 2 so: ");
	printf("%d ", sum(&number_1, &number_2));
	
	
	return 0;
}
