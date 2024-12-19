#include<stdio.h>

int factorial(int n);

int main()
{
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	
	printf("%d ", factorial(n));
	
	return 0;
}

int factorial(int n)
{
	int tich = 1;
	for(int i = 1; i <= n; i++)
	{
		tich *= i;
	}
	return tich;
}
