#include<stdio.h>

int main()
{
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	
	int arr[n];
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	for(int i = n - 1; i > 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	
	printf("Mang da duoc sap xep lai\n");
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	
	printf("\n");
	int star = 0;
	int end = n;
	int x;
	printf("Nhap x can tim kiem: ");
	scanf("%d", &x);
	
	int mid;
	while(star <= end)
	{
		mid = (star + end) / 2;
		
		if(arr[mid] == x)
		{
			printf("Vi tri %d ", mid);
			return 0;
		}
		else if(x > arr[mid])
		{
			star = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	
	printf("Khong co phan tu nay trong mang");
	
	return 0;
}
