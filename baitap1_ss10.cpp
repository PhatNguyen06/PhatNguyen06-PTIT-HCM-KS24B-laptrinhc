#include<stdio.h>

int main()
{
	int n, x;
	printf("Nhap n: ");
	scanf("%d", &n);
	
	int arr[n];
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	
	while(true)
	{	
		printf("Nhap vao gia tri muon tim kiem trong mang: "); 
		scanf("%d", &x); 
		int found = 0; 
		
		for(int i = 0; i < n; i++)
		if(x == arr[i])
		{
			printf("Gia tri %d o vi tri %d\n", x, i);
			found = 1;
			break;
		}
		
		if(!found)
		{
			printf("Khong co gia tri nay trong mang\n");
		}
		
		int is_continue = 1;
		printf("Ban co muon tiep tuc ktra khong(1/0): ");
		scanf("%d", &is_continue);
		if(is_continue == 0)
		{
			printf("Ket thuc\n");
			break;
		}
	}
	
	return 0;
}
