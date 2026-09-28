#include <stdio.h>

int main() {
    int n, m, i, j, k;

    // n = Number of processes, m = Number of resource types
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int allocation[n][m], max[n][m], avail[m];
    int need[n][m], finish[n], safeSeq[n];

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix (%d x %d):\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Input Maximum Matrix
    printf("\nEnter Maximum Matrix (%d x %d):\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input Available Resources
    printf("\nEnter Available Resources (%d values):\n", m);
    for (i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    // Calculate Need Matrix (Need = Max - Allocation)
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Initialize Work vector and Finish array
    int work[m];
    for (i = 0; i < m; i++) {
        work[i] = avail[i];
    }

    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int count = 0;
    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int j;
                // Check if Need for process i <= Work
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j])
                        break;
                }

                // If all resources can be allocated
                if (j == m) {
                    for (k = 0; k < m; k++) {
                        work[k] += allocation[i][k];
                    }
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        // If no process could be allocated in this cycle, system is unsafe
        if (found == 0) {
            printf("\nSystem is NOT in a safe state (Deadlock risk).\n");
            return 0;
        }
    }

    // If all processes are finished, print the safe sequence
    printf("\nSystem is in a SAFE state.\n");
    printf("Safe Sequence: ");
    for (i = 0; i < n; i++) {
        printf("P%d", safeSeq[i]);
        if (i != n - 1)
            printf(" -> ");
    }
    printf("\n");

    return 0;
}