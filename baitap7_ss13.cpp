#include<stdio.h>

void show_arr(int row, int col, int arr[row][col]);
void enter_arr(int row, int col, int arr[row][col]);

int main()
{
	int n, m;
	printf("Nhap so hang: ");
	scanf("%d", &n);
	printf("Nhap so cot: ");
	scanf("%d", &m);
	
	int arr[n][m];
	
	printf("Nhap mang: ");
	enter_arr(n, m, arr);
	show_arr(n, m, arr);
	
	
	return 0;
}

void enter_arr(int row, int col, int arr[row][col])
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
}

void show_arr(int row, int col, int arr[row][col])
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
