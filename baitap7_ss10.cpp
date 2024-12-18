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
	
	for(int i = 0; i < n; i++)
	{
		for(int j = m - 1; j > 0; j--)
		{
			for(int k = 0; k < j; k++)
			{
				if(arr[i][k] > arr[i][k + 1])
				{
					int temp = arr[i][k];
					arr[i][k] = arr[i][k + 1];
					arr[i][k + 1] = temp;
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

