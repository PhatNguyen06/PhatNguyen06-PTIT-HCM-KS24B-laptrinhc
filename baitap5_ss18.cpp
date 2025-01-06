#include<stdio.h>
#include<string.h>

struct Sinh_Vien
{
	int id;
	char name[50];
	int age;
	char phone_Number[15];
};

void search_edit(struct Sinh_Vien *menu);
void print_array_SV(struct Sinh_Vien *menu);

int main()
{
	struct Sinh_Vien menu_sv[50]
	{
		{1, "Nguyen Van A", 20, "0123456789"},
		{2, "Tran Thi B", 21, "0987654321"},
		{3, "Le Van C", 22, "0912345678"},
		{4, "Pham Thi D", 23, "0908765432"},
		{5, "Hoang Van E", 24, "0923456789"}
	};
	
	search_edit(menu_sv);
	
	print_array_SV(menu_sv);
	
	return 0;
}

void search_edit(struct Sinh_Vien *menu)
{
	int index, flag = -1;
	printf("Nhap vao 1 id muon tim kiem: ");
	scanf("%d", &index);
	getchar();
	for(int i = 0; i < 5; i++)
	{
		if(menu[i].id == index)
		{
			flag = 1;
			printf("Tim thay sinh vien: \n");
			printf("Id: %d\n", menu[i].id);
			printf("Ten sinh vien: %s\n", menu[i].name);
			printf("Tuoi sinh vien: %d\n", menu[i].age);
			printf("So dien thoai: %s\n", menu[i].phone_Number);
			
			printf("Nhap ten moi: ");
			fgets(menu[i].name, 50, stdin);
			menu[i].name[strcspn(menu[i].name, "\n")] = 0;
			printf("Nhap tuoi moi: ");
			scanf("%d", &menu[i].age);
			getchar();
			
			break;
		}
	}
	
	if(flag == -1)
	{
		printf("Khong tim thay sinh vien voi id %d\n", index);
		return;
	}
	
}


void print_array_SV(struct Sinh_Vien *menu)
{
	for(int i = 0; i < 5; i++)
	{
		printf("Id: %d\n", menu[i].id);
		printf("Ten sinh vien thu %d: %s\n", i + 1, menu[i].name);
		printf("Tuoi sinh vien thu %d: %d\n", i + 1, menu[i].age);
		printf("So dien thoai cua sinh vien thu %d: %s\n", i + 1, menu[i].phone_Number);
	}
}
