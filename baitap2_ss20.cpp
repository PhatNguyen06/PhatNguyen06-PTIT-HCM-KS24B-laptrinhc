#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Product
{
	char id[20];
	char name[50];
	float purchase_price;
	float selling_price;
	int quantity;
};

struct Product *products = NULL;
int product_count = 0;
float revenue = 0.0;

void show_menu();
void input_product();
void show_products();
void update_products();
void sort_products();
void search_products();
void sell_products();
void show_revenue();



int main()
{
	show_menu();
	
	return 0;
}

void show_menu() 
{
    int choice;
    do 
	{
        printf("\nMENU:\n");
        printf("1. Nhap san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Cap nhat thong tin san pham\n");
        printf("4. Sap xep san pham theo gia\n");
        printf("5. Tim kiem san pham\n");
        printf("6. Ban san pham\n");
        printf("7. Doanh thu hien tai\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) 
		{
            case 1: 
				input_product();
				break;
            case 2: 
				show_products();
				break;
            case 3: 
				update_products();
				break;
            case 4: 
                sort_products();
                break;
            case 5: 
				search_products();
				break;
            case 6: 
				sell_products();
				break;
            case 7: 
				show_revenue();
				break;
            case 8:
            	free(products);
				printf("Thoat chuong trinh.\n"); 
				break;
            default: 
				printf("Lua chon khong hop le.\n"); 
				break;
        }
    }
	while(choice != 8);
}

void input_product()
{
    int num_to_add;
    printf("Nhap so luong san pham can them: ");
    scanf("%d", &num_to_add);
    getchar();
	
	if (num_to_add <= 0)
    {
        printf("So luong san pham khong hop le.\n");
        return;
    }
	
    products = (struct Product*)realloc(products, (product_count + num_to_add) * sizeof(struct Product));
    if (products == NULL)
    {
        printf("Cap phat bo nho that bai.\n");
        exit(1);
    }

    for(int i = 0; i < num_to_add; i++)
    {
        struct Product new_product;
        
        printf("\nNhap ma san pham: ");
        fgets(new_product.id, 20, stdin);
        new_product.id[strcspn(new_product.id, "\n")] = '\0';

        int found = -1;
        for (int j = 0; j < product_count; j++)
        {
            if (strcmp(products[j].id, new_product.id) == 0)
            {
                found = j;
                break;
            }
        }

        if (found != -1)
        {
            printf("San pham da ton tai. Cap nhat so luong.\n");
            printf("Nhap vao so luong: ");
            int add_quantity;
            scanf("%d", &add_quantity);
            getchar();
	
			if (add_quantity <= 0) 
			{
	        printf("So luong nhap vao phai lon hon 0.\n");
	        return;
	    	}

            products[found].quantity += add_quantity;
            revenue -= (add_quantity * products[found].purchase_price);
            printf("Cap nhat thanh cong. So luong san pham hien tai: %d\n", products[found].quantity);
        }
        else
        {
            printf("Nhap ten san pham: ");
            fgets(new_product.name, 50, stdin);
            new_product.name[strcspn(new_product.name, "\n")] = '\0';

            printf("Nhap gia nhap: ");
            scanf("%f", &new_product.purchase_price);
            getchar();

            printf("Nhap gia ban: ");
            scanf("%f", &new_product.selling_price);
            getchar();

            printf("Nhap so luong san pham: ");
            scanf("%d", &new_product.quantity);
            getchar();

            revenue -= (new_product.quantity * new_product.purchase_price);

            products[product_count] = new_product;
            product_count++;
        }
    }

    printf("Nhap san pham thanh cong.\n");
}


void show_products()
{
	if(product_count == 0)
	{
		printf("Danh sach san pham rong\n");
		return;
	}
	
	printf("Danh sach san pham:\n");
	printf("%-10s %-25s %-15s %-15s %-10s\n", "ID", "Ten", "Gia nhap", "Gia ban", "So luong");
	for(int i = 0; i < product_count; i++)
	{
		printf("%-10s %-25s %-15.2f %-15.2f %-10d\n", products[i].id, products[i].name, products[i].purchase_price, products[i].selling_price, products[i].quantity);
	}
}

void update_products()
{
	if(product_count == 0)
	{
		printf("Danh sach san pham rong\n");
		return;
	}
	
	char index_id[20];
	printf("Nhap vao ma san pham can cap nhat thong tin: ");
	fgets(index_id, 20, stdin);
	index_id[strcspn(index_id, "\n")] = '\0';
	
	int location_id = -1;
	for(int i = 0; i < product_count; i++)
	{
		if(strcmp(products[i].id, index_id) == 0)
		{
			location_id = i;
			break;
		}
	}
	
	if(location_id == -1)
	{
		printf("Khong co ma san pham nay ton tai\n");
	}
	else
	{
		printf("Nhap ten san pham moi: ");
	    fgets(products[location_id].name, 50, stdin);
	    products[location_id].name[strcspn(products[location_id].name, "\n")] = '\0';
	
	    printf("Nhap gia nhap moi: ");
	    scanf("%f", &products[location_id].purchase_price);
	    getchar();
	
	    printf("Nhap gia ban moi: ");
	    scanf("%f", &products[location_id].selling_price);
	    getchar();
	
	    printf("Nhap so luong san pham moi: ");
	    scanf("%d", &products[location_id].quantity);
	    getchar();
		
		printf("Da cap nhat thong tin san pham thanh cong\n");	
	}
}

void sort_products()
{
	if(products == 0)
	{
		printf("Khong ton tai san pham nao\n");
		return;
	}
	
	int choice;
	printf("1. Sap xep san pham theo gia Tang dan\n");
	printf("2. Sap xep san pham theo gia Giam dan\n");
	printf("\n");
	printf(">> Lua chon cua ban la: ");
	
	scanf("%d", &choice);
	
	if (choice != 1 && choice != 2) 
	{
	    printf("Lua chon khong hop le.\n");
	    return;
	}
	
	for(int i = 0; i < product_count - 1; i++)
	{
		for(int j = 0; j < product_count - i - 1; j++)
		{
			if((choice == 1 && (products[j].selling_price > products[j + 1].selling_price)) || (choice == 2 && (products[j].selling_price < products[j + 1].selling_price)))
			{
				struct Product temp = products[j];
				products[j] = products[j + 1];
				products[j + 1] = temp;
			}
		}
	}
	
	printf("Sap xep thanh cong\n");
}

void search_products()
{
	if(product_count == 0)
	{
		printf("Danh sach san pham rong\n");
		return;
	}
	
	char index_id[20];
	printf("Nhap vao ma san pham can tim kiem: ");
	fgets(index_id, 20, stdin);
	index_id[strcspn(index_id, "\n")] = '\0';
	
	int location_id = -1;
	for(int i = 0; i < product_count; i++)
	{
		if(strcmp(products[i].id, index_id) == 0)
		{
			location_id = i;
			break;
		}
	}
	
	if(location_id == -1)
	{
		printf("Khong co ma san pham nay ton tai!!!\n");
		return;
	}
	else
	{
		printf("%-10s %-25s %-15s %-15s %-10s\n", "ID", "Ten", "Gia nhap", "Gia ban", "So luong");
		for(int i = 0; i < product_count; i++)
		{
			if(strcmp(products[i].id, index_id) == 0)
			{
				printf("%-10s %-25s %-15.2f %-15.2f %-10d\n", products[i].id, products[i].name, products[i].purchase_price, products[i].selling_price, products[i].quantity);
			}
		}
	}
}

void sell_products()
{
	if(product_count == 0)
	{
		printf("Danh sach san pham rong\n");
		return;
	}
	
	char index_id[20];
	printf("Nhap vao ma san pham can ban: ");
	fgets(index_id, 20, stdin);
	index_id[strcspn(index_id, "\n")] = '\0';
	
	int location_id = -1;
	for(int i = 0; i < product_count; i++)
	{
		if(strcmp(products[i].id, index_id) == 0)
		{
			location_id = i;
			break;
		}
	}
	
	if(location_id == -1)
	{
		printf("Khong co ma san pham nay ton tai!!!\n");
		return;
	}
	else
	{
		if(products[location_id].quantity == 0)
		{
			printf("San pham nay hien het hang!!!\n");
			return;
		}
		else
		{
			int quantity_to_sell;
			printf("Nhap vao so luong hang can ban: ");
			scanf("%d", &quantity_to_sell);
			getchar();
			
			if(quantity_to_sell <= 0)
			{
				printf("So luong san pham khong hop le.\n");
				return;
			}
		
			if(quantity_to_sell > products[location_id].quantity)
			{
				printf("Khong con du hang!\n");
				printf("So luong hang hien tai chi con: %d\n", products[location_id].quantity);
				return;
			}
			else
			{
				products[location_id].quantity -= quantity_to_sell;
				revenue += quantity_to_sell * products[location_id].selling_price;
				printf("Ban thanh cong %d san pham\n", quantity_to_sell);
			}
		}
	}
}

void show_revenue()
{
	printf("Danh thu hien tai: %.2f", revenue);
}
