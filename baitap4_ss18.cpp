#include<stdio.h>

struct Sinh_Vien
{
	int id;
	char name[50];
	int age;
	char phone_Number[15];
};

int main()
{
	struct Sinh_Vien menu_sv[50];
	
	for(int i = 0; i < 5; i++)
	{
		menu_sv[i].id = i + 1;
		printf("Nhap vao ten sinh vien %d: ", i + 1);
		fgets(menu_sv[i].name, 50, stdin);
		printf("Nhap vao tuoi sinh vien %d: ", i + 1);
		scanf("%d", &menu_sv[i].age);
		getchar();
		printf("Nhap vao so dien thoai cua sv thu %d: ", i + 1);
		fgets(menu_sv[i].phone_Number, 15, stdin);
	}
	
	for(int i = 0; i < 5; i++)
	{
		printf("Id: %d\n", menu_sv[i].id);
		printf("Ten sinh vien thu %d: %s", i + 1, menu_sv[i].name);
		printf("Tuoi sinh vien thu %d: %d\n", i + 1, menu_sv[i].age);
		printf("So dien thoai cua sinh vien thu %d: %s\n", i + 1, menu_sv[i].phone_Number);
	}
	
	
	return 0;
}
