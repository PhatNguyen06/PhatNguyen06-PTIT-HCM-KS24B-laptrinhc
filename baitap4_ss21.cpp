#include <stdio.h>
int main() {
    FILE *fptr;
    fptr = fopen("./bt01.txt", "r");
    if (fptr == NULL) 
	{
        printf("Mo file that bai!");
        return 1;
    }
    char str[100];
    fgets(str, 100, fptr);
    printf("%s", str);
    fclose(fptr);
    return 0;
}
