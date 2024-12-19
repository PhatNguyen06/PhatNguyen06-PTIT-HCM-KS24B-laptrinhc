#include<stdio.h>
#include<math.h>

int is_perfect(int a);

int main()
{
	int n, m;
	printf("Nhap 2 so de kiem tra: ");
	scanf("%d %d", &n, &m);
	
	if(is_perfect(n) == n)
	{
		printf("true\n");
	}
	else printf("false\n");
	if(is_perfect(m) == m)
	{
		printf("true\n");
	}
	else printf("false\n");
	
	return 0;
}

int is_perfect(int a)
{
	int sum = 0;
	for(int i = 1; i < a; i++)
	{
		if(a % i == 0)
		{
			sum += i;
		}
	}
	return sum;
}
