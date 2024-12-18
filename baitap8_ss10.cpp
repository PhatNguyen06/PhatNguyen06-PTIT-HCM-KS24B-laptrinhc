#include <stdio.h>

int main()
{
    int n, m;
    printf("Nhap so hang: ");
    scanf("%d", &n);
    printf("Nhap so cot: ");
    scanf("%d", &m);
	
	int arr[n][m];
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	
	for(int i = n - 1; i > 0; i--) 
	{
		for(int j = 0; j < m; j++)
		{
			for(int k = 0; k < i; k++)
			{
				if(arr[k][j] > arr[k + 1][j])
				{
					int temp = arr[k][j];
					arr[k][j] = arr[k + 1][j];
					arr[k + 1][j] = temp;
				}
			}
		}
	}
	
	printf("\n");
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
    

    return 0;
}

