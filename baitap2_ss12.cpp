#include<stdio.h>


void show_arr(int arr[], int n);
void enter_arr(int arr[], int n);

int main()
{
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	int arr[n];
	
	enter_arr(arr, n);
	show_arr(arr, n);
	
	return 0;
}

void show_arr(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	
}

void enter_arr(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
}
