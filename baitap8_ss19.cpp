#include<stdio.h>
#include<string.h>

struct Student 
{
	int id;
	char name[50];
	int age;
	char phoneNumber[15];
	
};

void sort_by_name(struct Student std[], int size);
void print_std_list(struct Student std[], int size);

int main()
{
	struct Student student_list[5] = 
	{
		{1, "BNguyen Dai Phat", 18, "0987654321"},
		{2, "DNguyen Van Tai", 19, "0978123456"},
		{3, "CNguyen Tien Dung", 20, "0901234567"},
		{4, "ATrinh Xuan Thien", 21, "0912345678"},
		{5, "HNguyen Ngoc Thien", 22, "0923456789"},
	};
	
	int currentLength = 5;
	 
	print_std_list(student_list, currentLength);
	
	sort_by_name(student_list, currentLength);
	
	print_std_list(student_list, currentLength);
	
	
	return 0;
}

void sort_by_name(struct Student std[], int size)
{
	for(int i = size - 1; i >= 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if(strcmp(std[j].name, std[j + 1].name) > 0)
			{
				struct Student temp = std[j];
				std[j] = std[j + 1];
				std[j + 1] = temp;
			}
		}
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
