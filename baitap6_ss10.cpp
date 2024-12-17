#include<stdio.h>

int main()
{
	int n, x;
	printf("Nhap n: ");
	scanf("%d", &n);
	int arr[n];
	
	printf("Nhap mang: ");
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	int arr1[n];
	printf("Nhap x: ");
	scanf("%d", &x);
	
	int dem = 0;
	for(int i = 0; i < n; i++)
	{
		if(arr[i] == x)
		{
			arr1[dem] = i;
			dem++;
		}
	}
	
	if(dem > 0)
	{
		for(int i = 0; i < dem; i++)
		{
			printf("%d ", arr1[i]);
		}
	}
	else
	{
		printf("Khong co gia tri nay trong mang!\n");
	}
	
	return 0;
}
