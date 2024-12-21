#include <stdio.h>
#include <string.h>

void str_erase(char *str, char erase_index)
{
	int j = 0;
	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] != erase_index)
		{
			str[j++] = str[i];
		}
	}
	str[j] = '\0';
}

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
    
    int x;
    printf("Nhap 1 ki tu can xoa: ");
    scanf(" %c", &x);
    
    str_erase(a, x);
    
    printf("%s", a);

    return 0;
}
