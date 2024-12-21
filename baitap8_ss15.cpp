#include<stdio.h>
#include<string.h>

int main()
{
	char a[1000];
		printf("Nhap chuoi: ");
		fgets(a, 1000, stdin);
		
		a[strcspn(a, "\n")] = '\0';
		
		a[0] -= 32;
		for(int i = 0; i < strlen(a); i++)
		{
			if(a[i] == ' ' && a[i + 1] != ' ')
			{
				a[i + 1] -= 32;
			}
		}
		
		printf("%s", a);
		
		
	return 0;
}
