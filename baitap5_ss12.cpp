#include<stdio.h>
#include<math.h>

int so_nguyen_to(int a);

int main()
{
	int n, m;
	printf("Nhap 2 so de kiem tra: ");
	scanf("%d %d", &n, &m);
	
	if(so_nguyen_to(n) == 1)
	{
		printf("true\n");
	}
	else printf("false\n");
	if(so_nguyen_to(m) == 1)
	{
		printf("true\n");
	}
	else printf("false\n");
	
	return 0;
}

int so_nguyen_to(int a)
{
	if (a < 2)
	{
		return 0;
	}
	
	for(int i = 2; i <= sqrt(a); i++)
	{
		if(a % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
