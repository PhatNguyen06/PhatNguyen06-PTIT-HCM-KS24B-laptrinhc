#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int show_menu();
void enter_string(char **str);
void reverse_string(char *str);
int count_quantity(char *str);
void compare_string_length(char *str1, char *str2);
void capital_letters(char *str);
void string_combination(char **str1, char *str2);

int main()
{
	char *str = NULL;
	char *str_2 = NULL;
    while(true)
    {
        int choice = show_menu();
        switch (choice)
        {
        case 1:
            enter_string(&str);
            break;
        case 2:
            reverse_string(str);
            break;
        case 3:
            count_quantity(str);
            break;
        case 4:
        	printf("Chuan bi nhap chuoi khac\n");
        	enter_string(&str_2);
            compare_string_length(str, str_2);
            free(str_2);
            break;
        case 5:
            capital_letters(str);
            break;
        case 6:
			printf("Chuan bi nhap chuoi khac\n");
        	enter_string(&str_2);
			string_combination(&str, str_2);
            free(str_2);
        	break;
        case 7:
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
    printf("2. In ra chuoi dao nguoc\n");
    printf("3. Dem so luong tu trong chuoi\n");
    printf("4. Nhap vao mot chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
    printf("5. In hoa tat ca chu cai trong chuoi\n");
    printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
    printf("7. Thoat\n");
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
		printf("Cap phat bo nho that bai!");
		exit(1);
	}
	
	printf("Nhap chuoi: ");
	fgets(*str, 100, stdin);
	
	(*str)[strcspn(*str, "\n")] = '\0';
}

void reverse_string(char *str)
{
	if(str == NULL)
	{
		printf("Cap phat bo nho that bai!");
		exit(1);
	}
	
	printf("Chuoi dao nguoc: ");
	for(int i = strlen(str) - 1; i >= 0; i--)
	{
		printf("%c", str[i]);
	}
}

int count_quantity(char *str)
{
	int cnt = 0;
    int inWord = 0; 

    for (int i = 0; i < strlen(str); i++) 
	{
        if (str[i] != ' ') 
		{
            if (inWord == 0) 
			{
                cnt++;
                inWord = 1;
            }
        } 
		else
		{
            inWord = 0;
        }
    }

    printf("So tu trong chuoi la: %d\n", cnt);
}

void compare_string_length(char *str1, char *str2)
{
	int length1 = strlen(str1);
	int length2 = strlen(str2);
	
	if(length1 > length2)
	{
		printf("Chuoi thu 2 ngan hon chuoi ban dau\n");
	}
	else if(length1 < length2)
	{
		printf("Chuoi thu 2 dai hon chuoi ban dau\n");
	}
	else printf("Hai chuoi bang nhau\n");
}

void capital_letters(char *str)
{
	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
	}
	
	printf("Da in hoa tat ca chu cai thanh cong\n");
	printf("Chuoi sau khi duoc in hoa: ");
	printf("%s", str);
}

void string_combination(char **str1, char *str2)
{
	int length1 = strlen(*str1);
	int length2 = strlen(str2);
	
	*str1 = (char *)realloc(*str1, (length1 + length2 + 1) * sizeof(char));
	strcat(*str1, str2);
	printf("Them chuoi thanh cong\n");
	printf("%s", *str1);
}
