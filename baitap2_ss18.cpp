#include<stdio.h>

struct Sinh_Vien
{
	char name[50];
	int age;
	char phone_Number[15];
};

int main()
{
	struct Sinh_Vien sinh_vien_01;
	
	printf("Nhap vao ten sinh vien: ");
	fgets(sinh_vien_01.name, 50, stdin);
	printf("Nhap vao tuoi sinh vien: ");
	scanf("%d", &sinh_vien_01.age);
	getchar();
	printf("Nhap vao so dien thoai: ");
	fgets(sinh_vien_01.phone_Number, 15, stdin);
	printf("================\n");
	printf("Ten sinh vien: %s\nTuoi sinh vien: %d\nSo dien thoai: %s", sinh_vien_01.name, sinh_vien_01.age, sinh_vien_01.phone_Number);
	
	return 0;
}
