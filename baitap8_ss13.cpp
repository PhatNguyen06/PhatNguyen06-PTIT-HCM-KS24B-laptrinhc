#include<stdio.h>

int ucln(int a, int b);

int main()
{
	int n, m;
	printf("Nhap 2 so nguyen bat ky: ");
	scanf("%d %d", &n, &m);
	
	printf("Uoc chung lon nhat cua %d va %d la %d\n", n, m, ucln(n,m));
	
	return 0;
}

int ucln(int a, int b)
{
	while(a != b)
	{
		if(a > b)
		{
			a -= b;
		}
		else b -= a;
	}
	
	return a;
}
