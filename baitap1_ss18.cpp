#include<stdio.h>

struct Sinh_vien
{
	char name[50];
	int age;
	char phone_Number[15];
};

int main()
{
	struct Sinh_vien sinh_vien_01 = {"Nguyen Dai Phat", 18, "034785213"};
	
	printf("Ten sinh vien: %s\nTuoi sinh vien: %d\nSo dien thoai: %s\n", sinh_vien_01.name, sinh_vien_01.age, sinh_vien_01.phone_Number);
	
	return 0;
}
