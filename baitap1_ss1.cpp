#include<stdio.h>

int main()
{
	int a;
	printf("Nhap a: ");
	scanf("%d", &a);
	int b;
	printf("Nhap b: ");
	scanf("%d", &b);
	
	if(a < b)
	{
		printf("%d", a);
	}
	else
	{
		printf("%d", b);
	}
	
	return 0;
}
