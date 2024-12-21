#include <stdio.h>
#include <string.h>

int main() {
    char a[100] = "Phat Nguyen Phat";
    char x;
    printf("Nhap vao 1 ki tu tim kiem: ");
    scanf(" %c", &x);
    
    int cnt = 0;
    for (int i = 0; i < strlen(a); i++) 
	{
        if(a[i] == x)
        {
			cnt++;
		}
    }
    
    if(cnt != 0)
    {
		printf("So lan xuat hien cua ki tu %c la: %d", x ,cnt);
	}
	else
	{
		printf("Ki tu %c co 0 lan xuat hien", x);
	}
    
    return 0;
}
