#include<stdio.h>
#include<iostream>

int show_menu();
void enter_Arr(int arr[], int *col);
void show_Arr(int arr[], int col);
void add_Arr(int arr[], int *col);
void repair_Arr(int arr[], int col);
void deleted_Arr(int arr[], int *col);
int show_menu2();
void descending_Arr(int arr[], int col);
void ascending_Arr(int arr[], int col);
int show_menu3();
void linear_search(int arr[], int col);
void binary_search(int arr[], int col);


int main()
{
	int n = 0;
	int arr[100];
	while(true)
	{
		int chose = show_menu();
		system("cls");
		switch(chose)
		{
			case 1:
				enter_Arr(arr, &n);
				break;
			case 2:
				if(n == 0)
				{
					printf("Mang chua duoc khoi tao: ");
					break;
				}
				show_Arr(arr, n);
				break;
			case 3:
				if(n == 0)
				{
					printf("Mang chua duoc khoi tao: ");
					break;
				}
				
				add_Arr(arr, &n);
				break;
			case 4:
				if(n == 0)
				{
					printf("Mang chua duoc khoi tao: ");
					break;
				}
				
				repair_Arr(arr, n);
				break;
			case 5:
				if(n == 0)
				{
					printf("Mang chua duoc khoi tao: ");
					break;
				}
				
				deleted_Arr(arr, &n);
				break;
			case 6:
				if(n == 0)
				{
					printf("Mang chua duoc khoi tao: ");
					break;
				}
				
				while(true)
				{
					int chose2 = show_menu2();
					
					switch(chose2)
					{
						case 'a':
							descending_Arr(arr, n);
							break;
						case 'b':
							ascending_Arr(arr, n);
							break;
						default:
							printf("Du lieu khong hop le!!!\n");		
					}
					
					int is_continue2 = 1;
					printf("\nBan co muon tiep tuc khong?(1/0)\n");
					scanf("%d", &is_continue2);
					system("cls");
					if(is_continue2 == 0)
					{
						break;
					}
				}
				
				break;
			case 7:
				if(n == 0)
				{
					printf("Mang chua duoc khoi tao: ");
					break;
				}
				
				while(true)
				{
					int chose3 = show_menu3();
					
					switch(chose3)
					{
						case 'a':
							linear_search(arr, n);
							break;
						case 'b':
							binary_search(arr, n);
							break;
						default:
							printf("Du lieu khong hop le!!!\n");		
					}
					
					int is_continue3 = 1;
					printf("\nBan co muon tiep tuc khong?(1/0)\n");
					scanf("%d", &is_continue3);
					system("cls");
					if(is_continue3 == 0)
					{
						break;
					}
				}
				
				break;
			case 8:
				printf("thoat chuong trinh, bai bai ban\n");
				return 1;
			default:
				printf("Du lieu khong hop le!!!\n");
		}
		int is_continue = 1;
		printf("\nBan co muon tiep tuc khong?(1/0)\n");
		scanf("%d", &is_continue);
		system("cls");
		if(is_continue == 0)
		{
			printf("Chuong trinh ket thuc, hen gap lai ban\n");
			break;
		}
	}
	
	return 0;
}

int show_menu()
{
	int chose;
	printf("            MENU            \n");
	printf("\n");
	printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
	printf("2. In ra gia tri cac phan tu dang quan ly\n");
	printf("3. Them mot phan tu vao vi tri chi dinh\n");
	printf("4. Sua mot phan tu o vi tri chi dinh\n");
	printf("5. Xoa mot phan tu o vi tri chi dinh\n");
	printf("6. Sap xep cac phan tu\n");
	printf("7. Tim kiem phan tu nhap vao\n");
	printf("8. Thoat\n");
	printf("\n");
	printf("Lua chon cua ban la: ");
	scanf("%d", &chose);
	
	return chose;
}

void enter_Arr(int arr[], int *col)
{
	printf("Nhap so luong phan tu: ");
	scanf("%d", col);
	
	printf("Nhap mang: ");
	for(int i = 0; i < *col; i++)
	{
		scanf("%d", &arr[i]);
	}
}

void show_Arr(int arr[], int col)
{
	for(int i = 0; i < col; i++)
	{
		printf("%d ", arr[i]);
	}
}

void add_Arr(int arr[], int *col)
{
	printf("Mang hien tai: ");
	show_Arr(arr, *col);
	printf("\n");
	
	printf("Nhap vao vi tri can them phan tu: ");
	int location, value_index;
	scanf("%d", &location);
	printf("Nhap vao gia tri muon them: ");
	scanf("%d", &value_index);
	
	for(int i = *col; i > location - 1; i--)
	{
		arr[i] = arr[i - 1];
	}
	(*col)++;
	arr[location - 1] = value_index;
	
	printf("Mang sau khi them phan tu: ");
	show_Arr(arr, *col);
}

void repair_Arr(int arr[], int col)
{
	printf("Mang hien tai: ");
	show_Arr(arr, col);
	printf("\n");
	
	int repair_index = 0, location_index = 0;
	printf("Nhap vi tri can sua: ");
	scanf("%d", &location_index);
	printf("Nhap gia tri thay doi: ");
	scanf("%d", &repair_index);
	
	for(int i = 0; i < col; i++)
	{
		if(location_index == i)
		{
			arr[i - 1] = repair_index;
			break;
		}
	}
	
	printf("Mang sau khi sua: ");
	show_Arr(arr, col);
}

void deleted_Arr(int arr[], int *col)
{
	printf("Mang hien tai: ");
	show_Arr(arr, *col);
	printf("\n");
	
	int deleted_index;
	printf("Nhap vao vi tri muon xoa: ");
	scanf("%d", &deleted_index);
	
	for(int i = deleted_index - 1; i < *col - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	(*col)--;
	
	printf("Mang sau khi xoa: ");
	show_Arr(arr, *col);
}

int show_menu2()
{
	char chose2;
	printf("a. Giam dan\n");
	printf("b. Tang dan\n");
	printf("\n");
	printf("Lua chon cua ban la: ");
	scanf(" %c", &chose2);
	
	return chose2;
}

void descending_Arr(int arr[], int col)
{
	printf("Mang truoc khi sap xep: ");
	show_Arr(arr, col);
	printf("\n");
	
	for(int i = col - 1; i > 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if(arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	
	printf("Mang sau khi sap xep giam dan: ");
	show_Arr(arr, col);
	printf("\n");
}

void ascending_Arr(int arr[], int col)
{
	printf("Mang truoc khi sap xep: ");
	show_Arr(arr, col);
	printf("\n");
	
	for(int i = col - 1; i > 0; i--)
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
	
	printf("Mang sau khi sap xep tang dan: ");
	show_Arr(arr, col);
	printf("\n");
}

int show_menu3()
{
	char chose3;
	printf("a. Tim kiem tuyen tinh\n");
	printf("b. Tim kiem nhi phan\n");
	printf("\n");
	printf("Lua chon cua ban la: ");
	scanf(" %c", &chose3);
	
	return chose3;
}

void linear_search(int arr[], int col)
{
	printf("Mang hien tai: ");
	show_Arr(arr, col);
	printf("\n");
	
	int search;
	printf("Nhap vao gia tri muon tim kiem trong mang: ");
	scanf("%d", &search);
	int flag = 0;
	
	for(int i = 0; i < col; i++)
	{
		if(arr[i] == search)
		{
			printf("Gia tri %d o vi tri %d trong mang\n", arr[i], i + 1);
			flag = 1;
			break;
		}
	}
	
	if(flag == 0)
	{
		printf("Khong tim thay gia tri nay trong mang!!\n");
	}
}

void binary_search(int arr[], int col)
{
	printf("Mang hien tai: ");
	show_Arr(arr, col);
	printf("\n");
	
	int search1;
	printf("Nhap vao gia tri muon tim kiem: ");
	scanf("%d", &search1);
	
	int star = 0;
	int end = col - 1;
	int found = 0;
	
	while(star <= end)
	{
		int mid = (star + end) / 2;
		if(arr[mid] < search1)
		{
			star = mid + 1;
		}
		else if(arr[mid] > search1)
		{
			end = mid - 1;
		}
		else
		{
			printf("Gia tri %d o vi tri %d trong mang.\n", search1, mid + 1);
			found = 1;
			break;
		}
	}
	
	if(found == 0)
	{
		printf("Khong tim thay gia tri\n");
	}
}
