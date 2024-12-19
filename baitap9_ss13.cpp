#include <stdio.h>
#include <math.h>
#include <istream>

int show_menu();
void enter_Arr(int arr[][100], int *row, int *col);
void show_Arr(int arr[][100], int row, int col);
void corner_Arr(int arr[][100], int row, int col);
void record_Arr(int arr[][100], int row, int col);
void diagonal_Arr(int arr[][100], int row, int col);
int is_prime(int a);
void prime_Arr(int arr[][100], int row, int col);


int main() {
    int n = 0, m = 0;
    int arr[100][100];
    
    while (true) {
        int chose = show_menu();
        system("cls");
        switch (chose) {
            case 1:
                enter_Arr(arr, &n, &m);
                break;
            case 2:
            	if(n == 0 || m == 0)
				{
					printf("Mang chua duoc khoi tao: ");
					break;
				}
				
                show_Arr(arr, n, m);
                break;
            case 3:
            	if(n == 0 || m == 0)
				{
					printf("Mang chua duoc khoi tao: ");
					break;
				}
				
                corner_Arr(arr, n, m);
                break;
            case 4:
            	if(n == 0 || m == 0)
				{
					printf("Mang chua duoc khoi tao: ");
					break;
				}
				
                record_Arr(arr, n, m);
                break;
            case 5:
            	if(n == 0 || m == 0)
				{
					printf("Mang chua duoc khoi tao: ");
					break;
				}
				
                diagonal_Arr(arr, n, m);
                break;
            case 6:
            	if(n == 0 || m == 0)
				{
					printf("Mang chua duoc khoi tao: ");
					break;
				}
				
                prime_Arr(arr, n, m);
                break;
            case 7:
                printf("Thoat chuong trinh, bai bai ban\n");
                return 1;
            default:
                printf("Du lieu khong hop le!!!\n");
        }
        int is_continue = 1;
        printf("\nBan co muon tiep tuc khong? (1/0)\n");
        scanf("%d", &is_continue);
        system("cls");
        if (is_continue == 0) {
            printf("Chuong trinh ket thuc, hen gap lai ban\n");
            break;
        }
    }
    
    return 0;
}

int show_menu() {
    int chose;
    printf("                       MENU                     \n");
    printf("\n");
    printf("1. Nhap gia tri cac phan tu cua mang\n");
    printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
    printf("3. In ra cac phan tu o goc theo ma tran\n");
    printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
    printf("5. In ra cac phan tu tren duong cheo chinh va duong cheo phu theo ma tran\n");
    printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
    printf("7. Thoat\n");
    printf("\n");
    printf("Lua chon cua ban la: ");
    scanf("%d", &chose);
    
    return chose;
}

void enter_Arr(int arr[][100], int *row, int *col)
{
	printf("Nhap so hang: ");
	scanf("%d", row);
	printf("Nhap so cot: ");
	scanf("%d", col);
	
	for(int i = 0; i < *row; i++)
	{
		for(int j = 0; j < *col; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
}

void show_Arr(int arr[][100], int row, int col)
{
	printf("Mang hien tai:\n");
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void corner_Arr(int arr[][100], int row, int col)
{
	printf("%d ", arr[0][0]);
	printf("%d ", arr[0][col - 1]);
	printf("%d ", arr[row - 1][col - 1]);
	printf("%d ", arr[row - 1][0]);
}

void record_Arr(int arr[][100], int row, int col)
{
	for(int j = 0; j < col; j++)
	{
		printf("%d ", arr[0][j]);
	}
	
	for(int i = 1; i < col - 1; i++)
	{
		printf("%d ", arr[i][col - 1]);
	}
	
	for(int j = col - 1; j >= 0; j--)
	{
		printf("%d ", arr[col - 1][j]);
	}
	
	for(int i = row - 2; i > 0; i--)
	{
		printf("%d ", arr[i][0]);
	}
}

void diagonal_Arr(int arr[][100], int row, int col)
{
	printf("Duong cheo chinh trong mang la: ");
	for(int i = 0; i < col; i++)
	{
		printf("%d ", arr[i][i]);
	}
	
	printf("\n");
	printf("Duong cheo phu trong mang la: ");
	for(int i = 0; i < col; i++)
	{
		printf("%d ", arr[i][col - 1 - i]);
	}
}

int is_prime(int a)
{
	if(a < 2)
	{
		return 0;
	}
	for(int i = 2; i <= sqrt(a); i++)
	{
		if(a % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

void prime_Arr(int arr[][100], int row, int col)
{
	printf("Cac so nguyen to trong ma tran la: ");
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(is_prime(arr[i][j]))
			{
				printf("%d ", arr[i][j]);
			}
		}
	}
}

