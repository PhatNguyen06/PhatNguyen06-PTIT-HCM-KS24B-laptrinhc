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
	
	
	for(int i = 0; i < n; i++)
	{
		int min = arr[i];
		for(int j = i + 1; j < n; j++)
		{
			if(arr[j] < min)
			{
				min = arr[j];
				arr[j] = arr[i];
				arr[i] = min;
			}
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}
