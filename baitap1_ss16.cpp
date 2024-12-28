#include<stdio.h>

int main()
{
	int n = 7;
	int *n_ptr = &n;
	
	printf("Dia chi cua n: %d\n", &n);
	printf("Dia chi cua con tro: %d\n", n_ptr);
	
	printf("Gia tri cua n: %d\n", n);
	printf("Gia tri cua con tro: %d\n", *n_ptr);;
	
	return 0;
}
