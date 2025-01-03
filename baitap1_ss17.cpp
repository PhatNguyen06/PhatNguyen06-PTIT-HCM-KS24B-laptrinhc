#include <stdio.h>
#include <stdlib.h>

int show_menu();
void enter_array(int **arr, int *size);
void show_array(int *arr, int size);
int sum_array(int *arr, int size);
int find_max_array(int *arr, int size);


int main()
{
    int n = 0;
    int *arr_ptr = NULL;

    while (1)
    {
        int choice = show_menu();
        switch (choice)
        {
        case 1:
            enter_array(&arr_ptr, &n);
            break;
        case 2:
            show_array(arr_ptr, n);
            break;
        case 3:
            printf("Do dai mang: %d\n", n);
            break;
        case 4:
            printf("Tong la: %d", sum_array(arr_ptr, n));
            break;
        case 5:
            printf("Max trong mang la: %d", find_max_array(arr_ptr, n));
            break;
        case 6:
            printf("Bai bai\n");
            free(arr_ptr);
            return 0;
        default:
            printf("Lua chon khong hop le!\n");
        }

        int is_continue = 1;
        printf("\nBan co muon tiep tuc khong? (1/0): ");
        scanf("%d", &is_continue);
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
    printf("1. Nhap vao so phan tu va cac phan tu trong mang\n");
    printf("2. Hien thi cac phan tu trong mang\n");
    printf("3. Tinh do dai mang\n");
    printf("4. Tinh tong cac phan tu trong mang\n");
    printf("5. Hien thi phan tu lon nhat\n");
    printf("6. Thoat\n");
    printf("Lua chon cua ban: ");
    scanf("%d", &choice);
    return choice;
}

void enter_array(int **arr, int *size)
{
    printf("Nhap so phan tu: ");
    scanf("%d", size);

    if (*size <= 0)
    {
        printf("So phan tu phai lon hon 0!\n");
        return;
    }

    *arr = (int *)realloc(*arr, (*size) * sizeof(int));
    if (*arr == NULL)
    {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < *size; i++)
    {
        scanf("%d", &((*arr)[i]));
    }
}

void show_array(int *arr, int size)
{
    if (arr == NULL || size <= 0)
    {
        printf("Mang chua duoc khoi tao!\n");
        return;
    }

    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sum_array(int *arr, int size)
{
	int sum = 0;
	for(int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	
	return sum;
}

int find_max_array(int *arr, int size)
{
	int max = arr[0];
	for(int i = 0; i < size; i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
		}
	}
	
	return max;
}
