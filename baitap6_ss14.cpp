#include<stdio.h>
#include<string.h>

int main()
{
	char a[100];
	printf("Nhap chuoi: ");
	fgets(a, 100, stdin);
	
	a[strcspn(a, "\n")] = '\0';
	
	int cnt = 0;
	for(int i = 0; i < strlen(a); i++)
	{
		if((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
		{
			cnt++;
			printf("%c ", a[i]);
		}
	}
	
	printf("\nSo luong ki tu chu cai la: %d", cnt);
	
	
	return 0;
}
