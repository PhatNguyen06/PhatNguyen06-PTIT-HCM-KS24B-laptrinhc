#include <stdio.h>

int main() {
    int row, col;
    printf("Nhap so dong: ");
    scanf("%d", &row);
    printf("Nhap so cot: ");
    scanf("%d", &col);

	int arr[row][col];
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	int n = row < col ? row : col;
	int arrange[n];

	for(int i = 0; i < row; i++)
	{
		arrange[i] = arr[i][i];
	}
	
	for(int i = row - 1; i > 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if(arrange[j] > arrange[j + 1])
			{
				int temp = arrange[j];
				arrange[j] = arrange[j + 1];
				arrange[j + 1] = temp;
			}
		}
	}
	
	for(int i = 0; i < row; i++)
	{
		arr[i][i] = arrange[i];
	}
	
    printf("Ma tran sau khi sap xep duong cheo chinh:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

