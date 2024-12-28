#include<stdio.h>
#include<stdlib.h>

int search_value(int arr[], int size,int value)
{
	for(int i = 0; i < size; i++)
	{
		if(arr[i] == value)
		{
			return i;
			
		}
	}
	
	return -1;
}

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
	
	int search_index;
	printf("\nNhap vao gia tri muon tim kiem trong mang: ");
	scanf("%d", &search_index);
	
	int index = search_value(arr_ptr, n, search_index);
	    if (index != -1)
		{
	        printf("Tim thay gia tri %d tai vi tri %d\n", search_index, index);
	    } else 
	        printf("Khong tim thay gia tri %d trong mang.\n", search_index);
	
	free(arr_ptr);
	
	return 0;
}
