#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>

struct Library
{
	char book_id[30];
	char name_title[50];
	char book_author[50];
	float book_money;
	char book_genre[30];
};

int show_menu();
char show_menu1();
void enter_book_information(struct Library ** lbr, int *size);
void show_book_information(struct Library *lbr, int size);
void add_book_to_location(struct Library ** lbr, int *size);
void delete_book(struct Library **lbr, int *size);
void update_book_information(struct Library **lbr, int size);
void sort_by_book_price(struct Library *lbr, int size);
void sort_descending_by_book_price(struct Library *lbr, int size);
void search_book_name(struct Library *lbr, int size);


int main()
{
	struct Library *library_list = NULL;
	int n = 0;
	
	while(1)
	{
		int choice = show_menu();
		system("cls");
		switch (choice) 
		{
			case 1:
				enter_book_information(&library_list, &n);
				break;
			case 2:
				show_book_information(library_list, n);
				break;
			case 3:
				add_book_to_location(&library_list, &n);
				break;
			case 4:
				delete_book(&library_list, &n);
				break;
			case 5:
				update_book_information(&library_list, n);
				break;
			case 6:
				if(n == 0)
				{
					printf("Danh sach trong!\n");
					return 1;
				}
				
				while(1)
				{
					int chose2 = show_menu1();
					switch(chose2)
					{
						case 'a':
						    sort_by_book_price(library_list, n);
						    break;
						case 'b':
							sort_descending_by_book_price(library_list, n);
							break;
						default:
							printf("Du lieu khong hop le!!!\n");		
					}
					
					int is_continue2 = 1;
					printf("\nBan co muon tiep tuc khong?(1/0)\n");
					scanf("%d", &is_continue2);
					if(is_continue2 == 0)
					{
						break;
					}
				}
				break;
			case 7:
				search_book_name(library_list, n);
				break;
			case 8:
				printf("Bai bai\n");
				free(library_list);
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
			printf("Xin chao ban\n");
			free(library_list);
			break;
		}		
	}
	
	return 0;
}

int show_menu()
{
	int choice;
	printf("===================MENU=================\n");
	printf("1. Nhap so luong va thong tin sach.\n");
	printf("2. Hien thi thong tin sach.\n");
	printf("3. Them sach vao vi tri.\n");
	printf("4. Xoa sach theo ma sach.\n");
	printf("5. Cap nhat thong tin sach theo ma sach.\n");
	printf("6. Sap xep sach theo gia(tang/ giam).\n");
	printf("7. Tim kiem sach theo ten sach.\n");
	printf("8. Thoat\n");
	printf("===================================\n");
	printf(">> Lua chon cua ban la: ");
	scanf("%d", &choice);
	system("cls");
	getchar();
	
	return choice;
}

void enter_book_information(struct Library **lbr, int *size)
{
	int quantity;
	printf("Nhap vao so luong sach: ");
	scanf("%d", &quantity);
	getchar();
	
	struct Library new_libraly[quantity];
	
	*lbr = (struct Library*)realloc(*lbr, (*size + quantity) * sizeof(struct Library));
	
	if(*lbr == NULL)
	{
		printf("Cap phat bo nho that bai\n");
		exit(1);
	}
	
	for(int i = 0; i < quantity; i++)
	{
		printf("Nhap thong tin ma sach thu [%d] (978-3-16-148410-0): ", i + 1);
		fgets(new_libraly[i].book_id, 30, stdin);
		new_libraly[i].book_id[strcspn(new_libraly[i].book_id, "\n")] = '\0';
		printf("Nhap ten sach thu [%d]: ", i + 1);
		fgets(new_libraly[i].name_title, 50, stdin);
		new_libraly[i].name_title[strcspn(new_libraly[i].name_title, "\n")] = '\0';
		printf("Nhap ten tac gia cua sach thu [%d]: ", i + 1);
		fgets(new_libraly[i].book_author, 50, stdin);
		new_libraly[i].book_author[strcspn(new_libraly[i].book_author, "\n")] = '\0';
		printf("Nhap gia tien cua sach thu [%d]: ", i + 1);
		scanf("%f", &new_libraly[i].book_money);
		getchar();
		printf("Nhap the loai cua sach thu [%d]: ", i + 1);
		fgets(new_libraly[i].book_genre, 30, stdin);
		new_libraly[i].book_genre[strcspn(new_libraly[i].book_genre, "\n")] = '\0';
		
		(*lbr)[*size] = new_libraly[i];
		(*size)++;
	}
	
	printf("Them thanh cong thong tin sach\n");
}

void show_book_information(struct Library *lbr, int size)
{
	if(size == 0)
	{
		printf("Danh sach trong!\n");
		return;
	}
	
	printf("%-15s %-18s %-18s %-5s %15s\n", "Ma sach", "Ten sach", "Tac gia", "Gia tien", "The loai");
	for(int i = 0; i < size; i++)
	{
		printf("%-15s %-18s %-18s %-5f %15s\n", lbr[i].book_id, lbr[i].name_title, lbr[i].book_author, lbr[i].book_money, lbr[i].book_genre);
	}
}

void add_book_to_location(struct Library **lbr, int *size)
{
	if(size == 0)
	{
		printf("Danh sach trong!\n");
		return;
	}
	
	int location_index;
	printf("Nhap vao vi tri muon them trong thu vien: ");
	scanf("%d", &location_index);
	getchar();
	
	if(location_index <= 0 || location_index > (*size) + 1)
	{
		printf("Nhap sai vi tri!!!");
		return;
	}
	
	*lbr = (struct Library*)realloc(*lbr, (*size + 1) * sizeof(struct Library));
	
	if(*lbr == NULL)
	{
		printf("Cap phat bo nho that bai!!\n");
		exit(1);
	}
	
	for(int i = *size; i >= location_index; i--)
	{
		(*lbr)[i] = (*lbr)[i - 1];
	}
	(*size)++;
	
	
	printf("Nhap thong tin ma sach thu [%d] (978-3-16-148410-0): ", location_index);
	fgets((*lbr)[location_index - 1].book_id, 30, stdin);
	(*lbr)[location_index - 1].book_id[strcspn((*lbr)[location_index - 1].book_id, "\n")] = '\0';
	printf("Nhap ten sach thu [%d]: ", location_index);
	fgets((*lbr)[location_index - 1].name_title, 50, stdin);
	(*lbr)[location_index - 1].name_title[strcspn((*lbr)[location_index - 1].name_title, "\n")] = '\0';
	printf("Nhap ten tac gia cua sach thu [%d]: ", location_index);
	fgets((*lbr)[location_index - 1].book_author, 50, stdin);
	(*lbr)[location_index - 1].book_author[strcspn((*lbr)[location_index - 1].book_author, "\n")] = '\0';
	printf("Nhap gia tien cua sach thu [%d]: ", location_index);
	scanf("%f", &(*lbr)[location_index - 1].book_money);
	getchar();
	printf("Nhap the loai cua sach thu [%d]: ", location_index);
	fgets((*lbr)[location_index - 1].book_genre, 30, stdin);
	(*lbr)[location_index - 1].book_genre[strcspn((*lbr)[location_index - 1].book_genre, "\n")] = '\0';
	
	printf("Them thanh cong thong tin sinh vien vao vi tri %d\n", location_index);
}

void delete_book(struct Library **lbr, int *size)
{
	if(size == 0)
	{
		printf("Danh sach trong!\n");
		return;
	}
	
	char delete_id[30];
	printf("Nhap vao ma sach muon xoa: ");
	fgets(delete_id, 30, stdin);
	delete_id[strcspn(delete_id, "\n")] = '\0';
	
	int location_to_delete = -1;
	for(int i = 0; i < *size; i++)
	{
		if(strcmp((*lbr)[i].book_id, delete_id) == 0)
		{
			location_to_delete = i;
			break;
		}
	}
	
	if(location_to_delete == -1)
	{
		printf("Khong tim thay thong tin ma sach nay\n");
		return;
	}
	else
	{
		for(int i = location_to_delete; i < *size - 1; i++)
		{
			(*lbr)[i] = (*lbr)[i + 1];
		}
		(*size)--;
		
		(*lbr) = (struct Library*)realloc((*lbr), (*size) * sizeof(struct Library));
		if (*lbr == NULL && *size > 0) 
		{
		    printf("Cap phat bo nho that bai\n");
		    exit(1);
		}
		
		printf("Xoa thanh cong thong tin sach thu [%d]\n", location_to_delete + 1);
	}
}

void update_book_information(struct Library **lbr, int size)
{
	if(size == 0)
	{
		printf("Danh sach trong!\n");
		return;
	}
	
	char check_id_book[30];
	printf("Nhap vao ma sach muon cap nhat thong tin: ");
	fgets(check_id_book, 30, stdin);
	check_id_book[strcspn(check_id_book, "\n")] = '\0';
	
	int location_book = -1;
	for(int i = 0; i < size; i++)
	{
		if(strcmp((*lbr)[i].book_id, check_id_book) == 0)
		{
			location_book = i;
			break;
		}
	}
	
	if(location_book == -1)
	{
		printf("Khong tim thay ma sach %s\n", check_id_book);
		return;
	}
	
	printf("Nhap thong tin ma sach thu [%d] (978-3-16-148410-0): ", location_book + 1);
	fgets((*lbr)[location_book].book_id, 30, stdin);
	(*lbr)[location_book].book_id[strcspn((*lbr)[location_book].book_id, "\n")] = '\0';
	printf("Nhap ten sach thu [%d]: ", location_book + 1);
	fgets((*lbr)[location_book].name_title, 50, stdin);
	(*lbr)[location_book].name_title[strcspn((*lbr)[location_book].name_title, "\n")] = '\0';
	printf("Nhap ten tac gia cua sach thu [%d]: ", location_book + 1);
	fgets((*lbr)[location_book].book_author, 50, stdin);
	(*lbr)[location_book].book_author[strcspn((*lbr)[location_book].book_author, "\n")] = '\0';
	printf("Nhap gia tien cua sach thu [%d]: ", location_book + 1);
	scanf("%f", &(*lbr)[location_book].book_money);
	getchar();
	printf("Nhap the loai cua sach thu [%d]: ", location_book + 1);
	fgets((*lbr)[location_book].book_genre, 30, stdin);
	(*lbr)[location_book].book_genre[strcspn((*lbr)[location_book].book_genre, "\n")] = '\0';
}

char show_menu1()
{
	char choice;
	printf("\n");
	printf("a. Tang dan theo price\n");
	printf("b. Giam dan thep price\n");
	printf("\n");
	printf("Lua chon cua ban la: ");
	scanf(" %c", &choice);
	getchar();
	
	return choice;
}

void sort_by_book_price(struct Library *lbr, int size)
{
	printf("Library duoc cap nhat theo gia tang dan\n");
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = 0; j < size - i - 1; j++)
		{
			if(lbr[j].book_money > lbr[j + 1].book_money)
			{
				struct Library temp = lbr[j];
				lbr[j] = lbr[j + 1];
				lbr[j + 1] = temp;
			}
		}
	}
	
	show_book_information(lbr, size);
}

void sort_descending_by_book_price(struct Library *lbr, int size)
{
	printf("Library duoc cap nhat theo gia giam dan\n");
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = 0; j < size - i - 1; j++)
		{
			if(lbr[j].book_money < lbr[j + 1].book_money)
			{
				struct Library temp_1 = lbr[j];
				lbr[j] = lbr[j + 1];
				lbr[j + 1] = temp_1;
			}
		}
	}
	
	show_book_information(lbr, size);
}


void search_book_name(struct Library *lbr, int size)
{
	if(size == 0)
	{
		printf("Danh sach trong!\n");
		return;
	}
	
	char search_name[50];
	printf("Nhap vao ten sach muon tim kiem: ");
	fgets(search_name, 50, stdin);
	search_name[strcspn(search_name, "\n")] = '\0';
	
	int flag = -1;
	for(int i = 0; i < size; i++)
	{
		if(strstr(lbr[i].name_title, search_name) != NULL)
		{
			flag = 0;
		}
	}
	
	if(flag == -1)
	{
		printf("Khong tim thay ten sach!!\n");
		return;
	}
	else
	{
		printf("%-15s %-18s %-18s %-5s %15s\n", "Ma sach", "Ten sach", "Tac gia", "Gia tien", "The loai");
		for(int i = 0; i < size; i++)
		{
			if(strstr(lbr[i].name_title, search_name) != NULL)
			{
				printf("%-15s %-18s %-18s %-5f %15s\n", lbr[i].book_id, lbr[i].name_title, lbr[i].book_author, lbr[i].book_money, lbr[i].book_genre);
			}
		}
	}
	
}
