#include<stdio.h>

int max_arr(int arr[], int n);

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
	
	printf("%d ", max_arr(arr, n));
	
	
	
	return 0;
}

int max_arr(int arr[], int n)
{
	int max = arr[0];
	for(int i = 0; i < n; i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}
