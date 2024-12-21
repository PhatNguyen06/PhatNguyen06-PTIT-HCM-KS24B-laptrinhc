#include<stdio.h>
#include<string.h>

int main()
{
	char a[100];
	printf("Nhap chuoi: ");
	fgets(a, 100, stdin);
	
	a[strcspn(a, "\n")] = '\0';
	printf("Chuoi vua nhap: %s\n", a);
	printf("Do dai chuoi: %d", strlen(a));
	
	return 0;
}
