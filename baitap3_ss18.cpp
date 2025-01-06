#include<stdio.h>

struct Sinh_Vien
{
	char name[50];
	int age;
	char phone_Number[15];
};

int main()
{
	struct Sinh_Vien menu_sv[5];
	
	for(int i = 0; i < 5; i++)
	{
		printf("Nhap vao ten sinh vien %d: ", i);
		fgets(menu_sv[i].name, 50, stdin);
		printf("Nhap vao tuoi sinh vien %d: ", i);
		scanf("%d", &menu_sv[i].age);
		getchar();
		printf("Nhap vao so dien thoai cua sv thu %d: ", i);
		fgets(menu_sv[i].phone_Number, 15, stdin);
	}
	
	for(int i = 0; i < 5; i++)
	{
		printf("Ten sinh vien thu %d: %s", i, menu_sv[i].name);
		printf("Tuoi sinh vien thu %d: %d\n", i, menu_sv[i].age);
		printf("So dien thoai cua sinh vien thu %d: %s\n", i, menu_sv[i].phone_Number);
	}
	
	
	return 0;
}
