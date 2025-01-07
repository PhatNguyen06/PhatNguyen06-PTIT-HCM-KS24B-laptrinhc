#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>

struct Student 
{
	int id;
	char name[50];
	int age;
	char phoneNumber[15];
	
};

int show_menu();
void print_std_list(struct Student *std, int size);
void add_student(struct Student **std, int *size);
void edit_student(struct Student **std, int size);
void delete_student(struct Student **std, int *size);
void search_student(struct Student *std, int size);
void sort_by_name(struct Student *std, int size);

int main()
{
	struct Student *student_list = NULL;
	int n = 0;
	
	while(1)
		{
			int choice = show_menu();
			system("cls");
			switch (choice) 
			{
				case 1:
					print_std_list(student_list, n);
					break;
				case 2:
					add_student(&student_list, &n);
					break;
				case 3:
					edit_student(&student_list, n);
					break;
				case 4:
					delete_student(&student_list, &n);
					break;
				case 5:
					search_student(student_list, n);
					break;
				case 6:
					sort_by_name(student_list, n);
					break;
				case 7:
					printf("Bai Bai\n");
					free(student_list);
					return 1;
				default:
					printf("Du lieu khong hop le!!\n");
					break;
			}
			
			int is_continue = 1;
			printf("===================================\n");
			printf("Ban co muon tiep tuc khong(1/0): ");
			scanf("%d", &is_continue);
			system("cls");
			getchar();
			if(is_continue == 0)
			{
				free(student_list);
				break;
			}		
		}
	return 0;
}

int show_menu()
{
	int choice;
	printf("=================MENU===============\n");
	printf("1. Hien thi danh sach sinh vien\n");
	printf("2. Them sinh vien\n");
	printf("3. Sua thong tin sinh vien\n");
	printf("4. Xoa sinh vien\n");
	printf("5. Tim kiem sinh vien\n");
	printf("6. Sap xep danh sach sinh vien\n");
	printf("7. Thoat\n");
	printf("===================================\n");
	printf(">> Lua chon cua ban la: ");
	scanf("%d", &choice);
	system("cls");
	getchar();
	
	return choice;
}

void print_std_list(struct Student *std, int size)
{
	if(size == 0)
	{
		printf("Hien khong co sinh vien nao ton tai\n");
		return;
	}
	
	printf("%-4s %-30s %-10s %-15s\n", "ID", "Name", "Age", "Phone_Number");
	for(int i = 0; i < size; i++)
	{
		printf("%-4d %-30s %-10d %-15s\n", std[i].id, std[i].name, std[i].age, std[i].phoneNumber);
	}
}

void add_student(struct Student **std, int *size)
{
	struct Student new_student;
	
	new_student.id = *size + 1;
	printf("Nhap vao ten hoc sinh new: ");
	fgets(new_student.name, 50, stdin);
	new_student.name[strcspn(new_student.name, "\n")] = '\0';
	printf("Nhap vao tuoi hoc sinh new: ");
	scanf("%d", &new_student.age);
	getchar();
	printf("Nhap vao so dien thoai new: ");
	fgets(new_student.phoneNumber, 15, stdin);
	new_student.phoneNumber[strcspn(new_student.phoneNumber, "\n")] = '\0';
	
	(*std) = (struct Student*)realloc(*std, (*size + 1) * sizeof(struct Student));
	
	if(*std == NULL)
	{
		printf("Cap phat bo nho that bai!\n");
		exit(1);
	}
	
	(*std)[*size] = new_student;
	(*size)++;
	printf("Them sinh vien moi thanh cong\n");
}

void edit_student(struct Student **std, int size)
{
	if(size == 0)
	{
		printf("Hien khong co sinh vien nao ton tai\n");
		return;
	}
	
	int location_index;
	printf("Nhap vao vi tri ID muon sua sinh vien: ");
	scanf("%d", &location_index);
	getchar();
	if(location_index <= 0 || location_index >= size + 1)
	{
		printf("Khong co vi tri nay!!!\n");
		return;
	}
	
	printf("Nhap vao ten muon sua: ");
	fgets((*std)[location_index - 1].name, 50, stdin);
	(*std)[location_index - 1].name[strcspn((*std)[location_index - 1].name, "\n")] = '\0';
	printf("Nhap vao tuoi muon sua: ");
	scanf("%d", &(*std)[location_index - 1].age);
	getchar();
	printf("Nhap vao so dien thoai muon sua: ");
	fgets((*std)[location_index - 1].phoneNumber, 15, stdin);
	(*std)[location_index - 1].phoneNumber[strcspn((*std)[location_index - 1].phoneNumber, "\n")] = '\0';
	
	printf("Sua thanh cong thong tin sinh vien\n");
}

void delete_student(struct Student **std, int *size)
{
	if(*size == 0)
	{
		printf("Hien khong co sinh vien nao ton tai\n");
		return;
	}
	
	int delete_index;
	printf("Nhap vao id muon xoa: ");
	scanf("%d", &delete_index);
	getchar();
	
	if(delete_index <= 0 || delete_index >= (*size) + 1)
	{
		printf("Khong co vi tri nay!!!\n");
		return;
	}
	
	for(int i = delete_index - 1; i < *size - 1; i++)
	{
		(*std)[i] = (*std)[i + 1];
	}
	(*size)--;
	
	if (*size == 0) 
	{
	    free(*std);
	    *std = NULL;
	} 
	else
	{
		*std = (struct Student*)realloc(*std, (*size - 1) * sizeof(struct Student));
		if(*std == NULL)
		{
			printf("Cap phat bo nho that bai!\n");
			exit(1);
		}
	}
	
	for(int i = 0; i < *size; i++)
	{
		(*std)[i].id = i + 1;
	}
	
	printf("Xoa sinh vien thanh cong\n");
	
}

void search_student(struct Student *std, int size)
{
	if(size == 0)
	{
		printf("Hien khong co sinh vien nao ton tai\n");
		return;
	}
	
	int check = 0;
	char search_name[50];
	printf("Nhap vao ten sinh vien can tim kiem: ");
	fgets(search_name, 50, stdin);
	search_name[strcspn(search_name, "\n")] = '\0';
	
	for(int i = 0; i < size; i++)
	{
		if(strstr(std[i].name, search_name) != NULL)
		{
			check = 1;
		}
	}
	
	if(check == 1)
	{
		printf("Tim thay sinh vien\n");
		printf("%-4s %-30s %-10s %-15s\n", "ID", "Name", "Age", "Phone_Number");
		for(int i = 0; i < size; i++)
		{
			if(strstr(std[i].name, search_name) != NULL)
			{
				printf("%-4d %-30s %-10d %-15s\n", std[i].id, std[i].name, std[i].age, std[i].phoneNumber);
			}
		}
	}
	
	if(check == 0)
	{
		printf("Khong tim thay sinh vien co ten '%s'\n", search_name);
		
	}
}

void sort_by_name(struct Student *std, int size)
{
	if(size == 0)
	{
		printf("Hien khong co sinh vien nao ton tai\n");
		return;
	}
	
	printf("Mang sau khi sap xep theo ten\n");
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = 0; j < size - i - 1; j++)
		{
			if(strcmp(std[i].name, std[i + 1].name) > 0)
			{
				struct Student temp = std[i];
				std[i] = std[i + 1];
				std[i + 1] = temp;
			}
		}
	}
	
	for(int i = 0; i < size; i++)
	{
		std[i].id = i + 1;
	}
	
	print_std_list(std, size);
}
