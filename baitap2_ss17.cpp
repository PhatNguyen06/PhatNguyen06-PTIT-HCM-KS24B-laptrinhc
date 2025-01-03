#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int show_menu();
void enter_string(char **str);
void printf_string(char *str);
int count_letters(char *str);
int count_digits(char *str);
int count_special_chars(char *str);


int main()
{
	char *str = NULL;
    while(true)
    {
        int choice = show_menu();
        switch (choice)
        {
        case 1:
            enter_string(&str);
            break;
        case 2:
            printf_string(str);
            break;
        case 3:
            count_letters(str);
            break;
        case 4:
            count_digits(str);
            break;
        case 5:
            count_special_chars(str);
            break;
        case 6:
            printf("Bai bai\n");
            free(str);
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
            free(str);
            break;
        }
    }

    free(str);
    return 0;
}

int show_menu()
{
    int choice;
    printf("================== MENU ==================\n");
    printf("1. Nhap vao chuoi\n");
    printf("2. In ra chuoi\n");
    printf("3. Dem so luong chu cai trong chuoi va in ra\n");
    printf("4. Dem so luong chu so trong chuoi in ra\n");
    printf("5. Dem so luong ki tu dac biet trong chuoi in ra\n");
    printf("6. Thoat\n");
    printf("Lua chon cua ban: ");
    scanf("%d", &choice);
    getchar();
    return choice;
}

void enter_string(char **str)
{
	*str = (char *)malloc(100 * sizeof(char));
	if(*str == NULL)
	{
		printf("Cap phat bo nho that bai!\n");
	    exit(1);
	}
	
	printf("Nhap chuoi: ");
	fgets(*str, 100, stdin);
	(*str)[strcspn(*str, "\n")] = '\0';
}

void printf_string(char *str)
{
	if(str == NULL)
	{
		printf("Cap phat bo nho that bai!\n");
		exit(1);
	}
	else
	{
		printf("%s\n", str);
	}
}

int count_letters(char *str)
{
	if(str == NULL)
	{
		printf("Cap phat bo nho that bai!\n");
		exit(1);
	}
	
	int count = 0;
	for(int i = 0; i < strlen(str); i++)
	{
		if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			count++;
		}
	}
	
	printf("So luong chu cai trong chuoi la: %d\n", count);
}

int count_digits(char *str)
{
	if(str == NULL)
	{
		printf("Cap phat bo nho that bai!\n");
		exit(1);
	}
	
	int count_So = 0;
	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			count_So++;
		}
	}
	
	printf("So luong chu so trong chuoi la: %d\n", count_So);
}

int count_special_chars(char *str)
{
	if(str == NULL)
	{
		printf("Cap phat bo nho that bai!\n");
		exit(1);
	}
	
	int count = 0;
	for(int i = 0; i < strlen(str); i++)
	{
		if(!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')))
		{
			count++;
		}
	}
	
	printf("So luong ki tu dac biet trong chuoi la: %d\n", count);
}
