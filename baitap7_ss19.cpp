#include<stdio.h>
#include<string.h>

struct Student 
{
	int id;
	char name[50];
	int age;
	char phoneNumber[15];
	
};

void delete_student(struct Student std[], int id, int *size);
void print_std_list(struct Student std[], int size);

int main()
{
	struct Student student_list[5] = 
	{
		{1, "Nguyen Dai Phat", 18, "0987654321"},
		{2, "Nguyen Van Tai", 19, "0978123456"},
		{3, "Nguyen Tien Dung", 20, "0901234567"},
		{4, "Trinh Xuan Thien", 21, "0912345678"},
		{5, "Nguyen Ngoc Thien", 22, "0923456789"},
	};
	
	 int currentLength = 5;
	 
	 print_std_list(student_list, currentLength);
	 
	 int index_id;
	 printf("Nhap vao id muon xoa: ");
	 scanf("%d", &index_id);
	 
	
	delete_student(student_list, index_id, &currentLength);
	
	print_std_list(student_list, currentLength);
	
	
	return 0;
}

void delete_student(struct Student std[], int id, int *size)
{
	int index = -1;
    for (int i = 0; i < *size; i++)
	{
        if (std[i].id == id) 
		{
            index = i;
            break;
        }
    }
    
	if (index == -1) {
        printf("Sinh vien id %d khong ton tai.\n", id);
        return;
    }
    
	for (int i = index; i < *size - 1; i++) {
        std[i] = std[i + 1];
    }
	(*size)--;
    printf("Xoa thanh cong\n");
    
    for(int i = 0; i < *size; i++)
	{
		std[i].id = i + 1;
	}
}


void print_std_list(struct Student std[], int size)
{
	printf("%-4s %-30s %-15s %10s\n", "ID", "Name", "Age", "Phone_Number");
	for(int i = 0; i < size; i++)
	{
		printf("%-4d %-30s %-15d %10s\n", std[i].id, std[i].name, std[i].age, std[i].phoneNumber);
	}
}
