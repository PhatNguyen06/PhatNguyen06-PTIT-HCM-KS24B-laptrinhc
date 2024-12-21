#include<stdio.h>
#include<string.h>

int main()
{
	char a[1000];
	printf("Nhap chuoi: ");
	fgets(a, 1000, stdin);
	
	a[strcspn(a, "\n")] = '\0';
	
	int cnt_alphabet = 0, cnt_digit = 0, cnt_special = 0;
	
	for(int i = 0; i < strlen(a); i++)
	{
		if((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
		{
			cnt_alphabet++;
		}
		else if(a[i] >= 48 && a[i] <= 57)
		{
			cnt_digit++;
		}
		else cnt_special++;
	}
	
	printf("So ky tu chu cai %d\n", cnt_alphabet);
	printf("So ki tu chu so %d\n", cnt_digit);
	printf("So ki tu dac biet %d\n", cnt_special);
	
	return 0;
}
