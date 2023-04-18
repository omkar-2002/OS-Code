#include <stdio.h>

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int bestIndex = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIndex == -1 || blockSize[j] < blockSize[bestIndex]) {
                    bestIndex = j;
                }
            }
        }
        if (bestIndex != -1) {
            allocation[i] = bestIndex;
            blockSize[bestIndex] -= processSize[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf(" %i\t\t\t", i + 1);
        printf("%i\t\t\t\t", processSize[i]);
        if (allocation[i] != -1) {
            printf("%i", allocation[i] + 1);
        } else {
            printf("Not Allocated");
        }
        printf("\n");
    }
}

// Driver code
int main() {
    int m;
    int n;
    printf("Enter No of process");
    scanf("%d", &n);
    printf("Enter No of Blocks");
    scanf("%d", &m);
    int blockSize[m];
    int processSize[n];
    for (int i = 0; i < n; i++) {
        printf("Enter %d process ", i + 1);
        scanf("%d", &processSize[i]);
    }
    for (int i = 0; i < m; i++) {
        printf("Enter %d block ", i + 1);
        scanf("%d", &blockSize[i]);
    }
    bestFit(blockSize, m, processSize, n);
    return 0;
}
