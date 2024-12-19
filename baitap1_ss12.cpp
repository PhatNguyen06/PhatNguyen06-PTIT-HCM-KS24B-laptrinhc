#include<stdio.h>

int sum_index(int a, int b)
{
	int sum = 0;
	sum = a + b;
	return sum;
}


int main()
{
	int a, b;
	printf("Nhap a: ");
	scanf("%d", &a);
	printf("Nhap b: ");
	scanf("%d", &b);
	
	printf("%d ", sum_index(a, b));
	
	return 0;
}
