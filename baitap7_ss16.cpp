#include<stdio.h>
#include<stdlib.h>

void sort_array(int arr[], int size);

int main()
{
	int n;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	
	int *arr_ptr = (int *)malloc(n * sizeof(int));
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", arr_ptr + i);
	}
	
	printf("Mang hien tai: ");
	for(int i = 0; i < n; i++)
	{
		printf("%d ", *(arr_ptr + i));
	}
	
	sort_array(arr_ptr, n);
	
	printf("\nMang sau khi sap xep (tang dan)");
	for(int i = 0; i < n; i++)
	{
		printf("%d ", *(arr_ptr + i));
	}
	
	
	free(arr_ptr);
	
	return 0;
}

void sort_array(int arr[], int size)
{
	for(int i = size - 1; i > 0; i--)
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
}
