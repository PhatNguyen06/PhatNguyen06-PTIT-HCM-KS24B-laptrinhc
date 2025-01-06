#include<stdio.h>
#include<string.h>

struct Sinh_Vien
{
	int id;
	char name[50];
	int age;
	char phone_Number[15];
};

void print_array_SV(struct Sinh_Vien *menu, int size);

int main()
{
	int n = 5;
	struct Sinh_Vien menu_sv[50]
	{
		{1, "Nguyen Van A", 20, "0123456789"},
		{2, "Tran Thi B", 21, "0987654321"},
		{3, "Le Van C", 22, "0912345678"},
		{4, "Pham Thi D", 23, "0908765432"},
		{5, "Hoang Van E", 24, "0923456789"}
	};
	
	char search_name[50];
	printf("Nhap ten sinh vien muon xoa: ");
	fgets(search_name, 50, stdin);
	search_name[strcspn(search_name, "\n")] = 0;
	
	int location = -1;
	for(int i = 0; i < n; i++)
	{
		if(strcspn(menu_sv[i].name, search_name) == 0)
		{
			location = i;
			break;
		}
	}
	
	if (location == -1) 
	{
	    printf("Khong tim thay sinh vien co ten: %s\n", search_name);
	}
	else
	{
		for(int i = location; i < n - 1; i++)
		{
			menu_sv[i] = menu_sv[i + 1];
		}
		n--;
		
		for(int i = 0; i < n; i++)
		{
			menu_sv[i].id = i + 1;
		}
		printf("Da xoa sinh vien co ten: %s\n", search_name);
	}
	
	print_array_SV(menu_sv, n);
	
	return 0;
}

void print_array_SV(struct Sinh_Vien *menu, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("Id: %d\n", menu[i].id);
		printf("Ten sinh vien thu %d: %s\n", i + 1, menu[i].name);
		printf("Tuoi sinh vien thu %d: %d\n", i + 1, menu[i].age);
		printf("So dien thoai cua sinh vien thu %d: %s\n", i + 1, menu[i].phone_Number);
		printf("--------------------\n");
	}
}
