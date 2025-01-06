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
	
	menu_sv[n].id = n + 1;
	printf("Nhap ten: ");
	fgets(menu_sv[n].name, 50, stdin);
	menu_sv[n].name[strcspn(menu_sv[n].name, "\n")] = 0;
	printf("Nhap tuoi: ");
	scanf("%d", &menu_sv[n].age);
	getchar();
	printf("Nhap so dien thoai: ");
	fgets(menu_sv[n].phone_Number, 15, stdin);
	menu_sv[n].phone_Number[strcspn(menu_sv[n].phone_Number, "\n")] = 0;
	n++;
	
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
