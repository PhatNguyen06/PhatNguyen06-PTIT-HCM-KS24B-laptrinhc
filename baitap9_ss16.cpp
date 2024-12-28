#include<stdio.h>
#include<stdlib.h>

void add_array(int **arr, int *size, int value, int location);

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
	
	int index_value, add_location;
	printf("Nhap vao 1 gia tri muon them vao: ");
	scanf("%d", &index_value);
		
	printf("Nhap vao vi tri muon them vao: ");
	scanf("%d", &add_location);
	
	if (add_location < 0 || add_location > n)
    {
        printf("Vi tri khong hop le!\n");
        free(arr_ptr);
        return 1;
    }
	
	add_array(&arr_ptr, &n, index_value, add_location);

	printf("Mang sau khi them: ");
	for(int i = 0; i < n; i++)
	{
		printf("%d ", *(arr_ptr + i));
	}
	
	free(arr_ptr);
	
	return 0;
}

void add_array(int **arr, int *size, int value, int location)
{	
	*arr = (int *)realloc(*arr, (*size + 1) * sizeof(int));
	for(int i = *size; i > location; i--)
	{
		(*arr)[i] = (*arr)[i - 1];
	}
	
	(*arr)[location] = value;
	
	(*size)++;
}
