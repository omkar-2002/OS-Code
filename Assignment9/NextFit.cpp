#include <stdio.h>

void nextFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < m)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
            j = (j + 1) % m;
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d\t\t\t", i + 1);
        printf("%d\t\t\t\t", processSize[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}

int main()
{
    int m, n;
    printf("Enter No of process:");
    scanf("%d", &n);
    printf("Enter No of Blocks:");
    scanf("%d", &m);
    int blockSize[m];
    int processSize[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d process size: ", i + 1);
        scanf("%d", &processSize[i]);
    }
    for (int i = 0; i < m; i++)
    {
        printf("Enter %d block size: ", i + 1);
        scanf("%d", &blockSize[i]);
    }
    nextFit(blockSize, m, processSize, n);
    return 0;
}
