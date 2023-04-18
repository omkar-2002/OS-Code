#include <stdio.h>
void firstFit(int blockSize[], int m, int processSize[], int n)
{
    int i, j;
    int allocation[n];
    for (i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %i\t\t\t", i + 1);
        printf("%i\t\t\t\t", processSize[i]);
        if (allocation[i] != -1)
            printf("%i", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}
// Driver code
int main()
{
    int m;
    int n;
    printf("Enter No of process");
    scanf("%d", &n);
    printf("Enter No of Blocks");
    scanf("%d", &m);
    int blockSize[m];
    int processSize[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d process ", i + 1);
        scanf("%d", &processSize[i]);
    }
    for (int i = 0; i < m; i++)
    {
        printf("Enter %d block ", i + 1);
        scanf("%d", &blockSize[i]);
    }
    firstFit(blockSize, m, processSize, n);
    return 0;
}