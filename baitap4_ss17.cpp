#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<iostream>

int show_menu();
void enter_array(int **arr, int *size);
void even_number_array(int *arr, int size);
int prime(int n);
void prime_array(int *arr, int size);
void reverse_array(int *arr, int size);
int show_menu_1();
void print_array(int *arr, int size);
void sort_array_ascending(int *arr, int size);
void sort_array_descending(int *arr, int size);
void search_element_in_array(int *arr, int size);

int main()
{
    int n = 0;
    int *arr_ptr = NULL;

    while (1)
    {
        int choice = show_menu();
        system("cls");
        switch (choice)
        {
        case 1:
            enter_array(&arr_ptr, &n);
            break;
        case 2:
			if(n == 0 || arr_ptr == NULL)
            {
				printf("Mang chua duoc khoi tao. Vui long nhap mang truoc.\n");
			}
			else
			{
				even_number_array(arr_ptr, n);
			}
            break;
        case 3:
			if(n == 0 || arr_ptr == NULL)
            {
				printf("Mang chua duoc khoi tao. Vui long nhap mang truoc.\n");
			}
			else
			{
				prime_array(arr_ptr, n);
			}
            break;
		case 4:
            if(n == 0 || arr_ptr == NULL)
            {
				printf("Mang chua duoc khoi tao. Vui long nhap mang truoc.\n");
			}
			else
			{
				reverse_array(arr_ptr, n);
			}
			
            break;
        case 5:
            while(1)
            {
				int choice_1 = show_menu_1();
				switch(choice_1)
				{
					case 'a':
						sort_array_ascending(arr_ptr, n);
						break;
					case 'b':
						sort_array_descending(arr_ptr, n);
						break;
					default:
						printf("Lua chon khong hop le!\n");
				}
				
				int is_continue_1 = 1;
				printf("\nBan co muon tiep tuc khong? (1/0): ");
		        scanf("%d", &is_continue_1);
		        if (is_continue_1 == 0)
		        {
		            break;
		        }
			}
            break;
        case 6:
			if(n == 0 || arr_ptr == NULL)
            {
				printf("Mang chua duoc khoi tao. Vui long nhap mang truoc.\n");
			}
			else
			{
				search_element_in_array(arr_ptr, n);
			}
        	break;
        case 7:
            printf("Bai bai\n");
            free(arr_ptr);
            return 0;
        default:
            printf("Lua chon khong hop le!\n");
        }

        int is_continue = 1;
        printf("\nBan co muon tiep tuc khong? (1/0): ");
        scanf("%d", &is_continue);
        system("cls");
        if (is_continue == 0)
        {
            printf("Chuong trinh ket thuc, hen gap lai ban\n");
            break;
        }
    }

    free(arr_ptr);
    return 0;
}

int show_menu()
{
    int choice;
    printf("========= MENU =========\n");
    printf("1. Nhap vao so phan tu va tung phan tu\n");
    printf("2. In ra cac phan tu chan\n");
    printf("3. In ra cac phan tu la so nguyen to\n");
    printf("4. Dao nguoc mang\n");
    printf("5. Sap xep mang\n");
    printf("6. Nhap vao mot phan tu va tim kiem phan tu trong mang\n");
    printf("7. Thoat\n");
    printf("Lua chon cua ban: ");
    scanf("%d", &choice);
    system("cls");
    return choice;
}

void enter_array(int **arr, int *size)
{
	printf("Nhap vao so luong phan tu: ");
	scanf("%d", size);
	
	*arr = (int *)malloc(*size * sizeof(int));
	
	for(int i = 0; i < *size; i++)
	{
		scanf("%d", (*arr) + i);
	}
}

void even_number_array(int *arr, int size)
{
	printf("Mang gia tri chan trong mang la: ");
	for(int i = 0; i < size; i++)
	{
		if(arr[i] % 2 == 0)
		{
			printf("%d ", arr[i]);
		}
	}
}

int prime(int n)
{
	if(n < 2) return 0;
	
	for(int i = 2; i <= sqrt(n); i++)
	{
		if(n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

void prime_array(int *arr, int size)
{
	printf("Cac gia tri so nguyen to trong mang la: ");
	for(int i = 0; i < size; i++)
	{
		if(prime(arr[i]))
		{
			printf("%d ", arr[i]);
		}
	}
	printf("\n");
}

void reverse_array(int *arr, int size)
{
	for(int i = 0; i < size / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
	}
	
	printf("Mang sau khi dao nguoc: ");
	print_array(arr, size);
}

int show_menu_1()
{
	char choice;
	printf("a. Tang dan\n");
	printf("b. Giam dan\n");
	printf("\n");
	printf("Lua chon cua ban: ");
	getchar();
	scanf("%c", &choice);
	
	return choice;
}

void print_array(int *arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}

void sort_array_ascending(int *arr, int size)
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
	
	printf("Mang sau khi sap xep tang dan: ");
	print_array(arr, size);
}

void sort_array_descending(int *arr, int size)
{
	for(int i = size - 1; i > 0; i--)
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
	print_array(arr, size);
}

void search_element_in_array(int *arr, int size)
{
	int search_index, search_location = -1;
	printf("Nhap vao gia tri muon tim trong mang: ");
	scanf("%d", &search_index);
	for(int i = 0; i < size; i++)
	{
		if(arr[i] == search_index)
		{
			search_location = i;
		}
	}
	
	if(search_location == -1)
	{
		printf("Khong tim thay gia tri %d trong mang\n", search_index);
	}
	else
	{
		printf("Gia tri %d nam o vi tri %d trong mang\n", search_index, search_location);
	}
}
