#include<stdio.h>
#include<string.h>

int cnt[1000001] = {0};

int main()
{
	char a[100];
	printf("Nhap chuoi: ");
	fgets(a, 100, stdin);
	
	a[strcspn(a, "\n")] = '\0';
	
	for(int i = 0; i < strlen(a); i++)
	{
		cnt[a[i]]++;
	}
	
	
	for(int i = 0; i < strlen(a); i++)
	{
		if(cnt[a[i]] > 0)
		{
			printf("%c: %d\n", a[i], cnt[a[i]]);
			cnt[a[i]] = 0; 
		}
	}

	
	return 0;
}
