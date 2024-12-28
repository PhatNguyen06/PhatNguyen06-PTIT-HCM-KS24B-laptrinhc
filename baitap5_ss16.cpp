#include<stdio.h>
#include<stdlib.h>

void update_array(int arr[], int size, int value, int location);

int main()
{	
	int n;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	
	int *arr_ptr = (int *) malloc(n*sizeof(int));
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", arr_ptr + i);
	}
	
	printf("Mang ban dau: ");
	for(int i = 0; i < n; i++)
	{
		printf("%d ", *(arr_ptr + i));
	}
	printf("\n");
	
	int value_main, location_main;
	printf("Nhap gia tri moi muon thay doi: ");
	scanf("%d", &value_main);
	printf("Nhap vao vi tri muon thay doi: ");
	scanf("%d", &location_main);
	
	update_array(arr_ptr, n, value_main, location_main);
	
	free(arr_ptr);
	
	
	return 0;
}

void update_array(int arr[], int size, int value, int location)
{
	if(location < size)
	{
		arr[location - 1] = value;
		printf("Mang sau khi thay doi: ");
		for(int i=0; i < size; i++)
		{
			printf("%d ", arr[i]);
		}
	}
	else
	{
		printf("Vi tri khong hop le!!");
	}
}
