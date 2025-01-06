#include<stdio.h>
#include<string.h>

struct Dish
{
	int id;
	char name[50];
	int price;
};

int show_menu();
int show_menu1();
int show_menu2();

int main()
{
	int n = 5;
	struct Dish menu[100] =
	{
		{1, "Tiet canh vit suoi", 15},
		{2, "Nom vit suoi", 125},
		{3, "Canh mang tiet", 35},
		{4, "Canh suong khoai so / mang", 65},
		{5, "Bun dia", 15},
	};
	
	while(1)
	{
		int choice = show_menu();
		switch (choice) 
		{
			case 1:
				printf("%-4s %-30s %10s\n", "ID", "Name", "Price");
				for(int i = 0; i < n; i++)
				{
				    printf("%-4d %-30s %10d\n", menu[i].id, menu[i].name, menu[i].price);
				}
				break;
			case 2:
				int index_location;
				printf("Nhap vao vi tri muon them vao: ");
				scanf("%d", &index_location);
				getchar();
				if(index_location <= 0 || index_location > n + 1)
				{
					printf("Nhap sai vi tri\n");
					break;
				}
				
				for(int i = n; i >= index_location; i--)
				{
					menu[i] = menu[i - 1];
				}
				n++;
				
				printf("Nhap vao ten mon moi: ");
				fgets(menu[index_location - 1].name, 50, stdin);
				menu[index_location - 1].name[strcspn(menu[index_location - 1].name, "\n")] = 0;
				printf("Nhap vao gia mon: ");
				scanf("%d", &menu[index_location - 1].price);
				getchar();
				
				for(int i = 0; i < n; i++)
				{
					menu[i].id = i + 1;
				}
				
				break;
			case 3:
				int edit_index;
				printf("Nhap vao vi tri muon sua: ");
				scanf("%d", &edit_index);
				getchar();
				if(edit_index <= 0 || edit_index > n + 1)
				{
					printf("Nhap sai vi tri\n");
					break;
				}
				
				printf("Nhap vao ten mon muon sua: ");
				fgets(menu[edit_index - 1].name, 50, stdin);
				menu[edit_index - 1].name[strcspn(menu[edit_index - 1].name, "\n")] = 0;
				printf("Nhap vao gia mon muon sua: ");
				scanf("%d", &menu[edit_index - 1].price);
				getchar();
				
				break;
			case 4:
				int delete_index;
				printf("Nhap vao vi tri muon xoa mon: ");
				scanf("%d", &delete_index);
				getchar();
				if(delete_index <= 0 || delete_index > n + 1)
				{
					printf("Nhap sai vi tri\n");
					break;
				}
				
				for(int i = delete_index - 1; i < n - 1; i++)
				{
					menu[i] = menu[i + 1];
				}
				n--;
				
				for(int i = 0; i < n; i++)
				{
					menu[i].id = i + 1;
				}
				
				break;
			case 5:
				while(1)
				{
					int chose2 = show_menu1();
					switch(chose2)
					{
						case 'a':
						    for (int i = n - 1; i >= 0; i--)
						    {
						        for (int j = 0; j < i; j++)
						        {
						            if (menu[j].price < menu[j + 1].price)
						            {
						                struct Dish temp = menu[j];
						                menu[j] = menu[j + 1];
						                menu[j + 1] = temp;
						            }
						        }
						    }
						
						    printf("Menu sau khi sap xep giam dan theo price:\n");
						    printf("%-4s %-30s %10s\n", "ID", "Name", "Price");
						    for (int i = 0; i < n; i++)
						    {
						        printf("%-4d %-30s %10d\n", menu[i].id, menu[i].name, menu[i].price);
						    }
						    break;
						
						case 'b':
							for (int i = n - 1; i >= 0; i--)
						    {
						        for (int j = 0; j < i; j++)
						        {
						            if (menu[j].price > menu[j + 1].price)
						            {
						                struct Dish temp = menu[j];
						                menu[j] = menu[j + 1];
						                menu[j + 1] = temp;
						            }
						        }
						    }
						
						    printf("Menu sau khi sap xep tang dan theo price:\n");
						    printf("%-4s %-30s %10s\n", "ID", "Name", "Price");
						    for (int i = 0; i < n; i++)
						    {
						        printf("%-4d %-30s %10d\n", menu[i].id, menu[i].name, menu[i].price);
						    }
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
			case 6:
				while(1)
				{
					int chose3 = show_menu2();
					int flag_2;
					switch(chose3)
					{
						case 'a':
							flag_2 = 0;
							char search_index[50];
							printf("Nhap vao ten muon tim kiem: ");
							fgets(search_index, 50, stdin);
							search_index[strcspn(search_index, "\n")] = '\0';
							
						    for(int i = 0; i < n; i++)
							{
								if(strstr(menu[i].name, search_index) != NULL)
								{
									printf("Tim thay mon an:\n");
									printf("%-4s %-30s %10s\n", "ID", "Name", "Price");
									printf("%-4d %-30s %10d\n", menu[i].id, menu[i].name, menu[i].price);
									flag_2 = 1;
								}
							}
							
							if (!flag_2)
					        {
					            printf("Khong tim thay mon an voi ten '%s'\n", search_index);
					        }
					        
						    break;
						case 'b':
						    {
						        for (int i = 0; i < n - 1; i++)
						        {
						            for (int j = i + 1; j < n; j++)
						            {
						                if (strcmp(menu[i].name, menu[j].name) > 0)
						                {
						                    struct Dish temp = menu[i];
						                    menu[i] = menu[j];
						                    menu[j] = temp;
						                }
						            }
						        }
						
						        char search_index[50];
						        printf("Nhap vao ten muon tim kiem: ");
						        fgets(search_index, 50, stdin);
						        search_index[strcspn(search_index, "\n")] = 0;
						        
						        int left = 0, right = n - 1, found = 0;
						        while (left <= right)
						        {
						            int mid = left + (right - left) / 2;
						            int cmp = strcmp(search_index, menu[mid].name);
						
						            if (cmp == 0)
						            {
						                printf("Tim thay mon an:\n");
						                printf("%-4s %-30s %10s\n", "ID", "Name", "Price");
						                printf("%-4d %-30s %10d\n", menu[mid].id, menu[mid].name, menu[mid].price);
						                found = 1;
						                break;
						            }
						            else if (cmp < 0)
						            {
						                right = mid - 1;
						            }
						            else
						            {
						                left = mid + 1;
						            }
						        }
						
						        if (!found)
						        {
						            printf("Khong tim thay mon an voi ten '%s'\n", search_index);
						        }
						    }
						    break;
						
						default:
							printf("Du lieu khong hop le!!!\n");		
					}
					
					int is_continue3 = 1;
					printf("\nBan co muon tiep tuc khong?(1/0):\n");
					scanf("%d", &is_continue3);
					if(is_continue3 == 0)
					{
						break;
					}
				}
				
				break;
			case 7:
				printf("Bai Bai\n");
				return 1;
			default:
				printf("Du lieu khong hop le!!\n");
				break;
		}
		
		int is_continue = 1;
		printf("Ban co muon tiep tuc khong(1/0): ");
		scanf("%d", &is_continue);
		getchar();
		if(is_continue == 0)
		{
			break;
		}		
	}
	
	return 0;
}

int show_menu()
{
	int choice;
	printf("=================MENU===============\n");
	printf("1. In ra gia tri cac phan tu co trong menu\n");
	printf("2. Them mot phan tu vao vi tri chi dinh\n");
	printf("3. Sua mot phan tu o vi tri chi dinh\n");
	printf("4. Xoa mot phan tu o vi tri chi dinh\n");
	printf("5. Sap xep cac phan tu\n");
	printf("6. Tim kiem phan tu theo name nhap vao\n");
	printf("7. Thoat\n");
	printf("\n");
	printf("Lua chon cua ban la: ");
	scanf("%d", &choice);
	getchar();
	
	return choice;
}

int show_menu1()
{
	char choice;
	printf("\n");
	printf("a. Giam dan theo price\n");
	printf("b. Tang dan thep price\n");
	printf("\n");
	printf("Lua chon cua ban la: ");
	scanf(" %c", &choice);
	getchar();
	
	return choice;
}

int show_menu2()
{
	char choice;
	printf("\n");
	printf("a. Tim kiem tuyen tinh\n");
	printf("b. Tim kiem nhi phan\n");
	printf("\n");
	printf("Lua chon cua ban la: ");
	scanf(" %c", &choice);
	getchar();
	
	return choice;
}
