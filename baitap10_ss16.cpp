#include<stdio.h>
#include<stdlib.h>

void delete_array(int **arr, int *size, int location);

int main()
{
	int n;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	
	int *arr_ptr = (int *)malloc(n * sizeof(int));
	
	printf("Nhap mang: ");
	for(int i = 0; i < n; i++)
	{
		scanf("%d", arr_ptr + i);
	}
	
	int delete_location;
	printf("Nhap vao vi tri can xoa: ");
	scanf("%d", &delete_location);
	
	delete_array(&arr_ptr, &n, delete_location);
	
	printf("Mang sau khi xoa: ");
	for(int i = 0; i < n; i++)
	{
		printf("%d ", *(arr_ptr + i));
	}
	
	
	free(arr_ptr);
	
	return 0;
}

void delete_array(int **arr, int *size, int location)
{
	for(int i = location; i < *size - 1; i++)
	{
		(*arr)[i] = (*arr)[i + 1];
	}
	
	*arr = (int *)realloc(*arr, (*size - 1) * sizeof(int));
	
	(*size)--;
}
