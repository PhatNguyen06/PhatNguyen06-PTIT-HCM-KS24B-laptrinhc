#include <stdio.h>
#include <string.h>

int main() 
{
    char a[100];
    printf("Nhap chuoi: ");
    fgets(a, 100, stdin);

    a[strcspn(a, "\n")] = '\0';

    int cnt = 0;
    int inWord = 0; 

    for (int i = 0; i < strlen(a); i++) 
	{
        if (a[i] != ' ') 
		{
            if (inWord == 0) 
			{
                cnt++;
                inWord = 1;
            }
        } 
		else
		{
            inWord = 0;
        }
    }

    printf("So tu trong chuoi la: %d\n", cnt);
    
    return 0;
}
