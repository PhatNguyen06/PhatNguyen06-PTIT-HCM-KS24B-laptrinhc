#include<stdio.h>
#include<stdlib.h>

void show_arr(int *arr)
{
	for(int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
}


int main()
{
	int arr[5];
	
	for(int i=0; i < 5; i++)
	{
		arr[i] = rand() % 100;
	}
	
	show_arr(arr);
		
	return 0;
}
