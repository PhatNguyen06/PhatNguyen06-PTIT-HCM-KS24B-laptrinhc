#include <stdio.h>

int main() {
    FILE *fptr;
    char str[100];
    fptr = fopen("./bt01.txt", "a");
    if (fptr == NULL) 
	{
        printf("Mo file that bai!");
        return 1;
    }
    printf("Nhap chuoi cua ban: ");
    fgets(str, sizeof(str), stdin);
    fputs(str, fptr);
    printf("Nhap thanh cong");
    fclose(fptr);
}
