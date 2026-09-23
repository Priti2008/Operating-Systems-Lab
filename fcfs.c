// #include <stdio.h>

// struct Process {
//     int pid;
//     int at;  
//     int bt; 
//     int ct; 
//     int tat; 
//     int wt;  
// };

// void sortByArrivalTime(struct Process p[], int n) {
//     struct Process temp;
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - i - 1; j++) {
//             if (p[j].at > p[j + 1].at) {
//                 temp = p[j];
//                 p[j] = p[j + 1];
//                 p[j + 1] = temp;
//             }
//         }
//     }
// }

// int main() {
//     int n;

//     printf("Enter number of processes: ");
//     scanf("%d", &n);

//     struct Process p[n];

//     printf("\nEnter Arrival Time and Burst Time for each process:\n");
//     for (int i = 0; i < n; i++) {
//         p[i].pid = i + 1;
//         printf("Process P%d - Arrival Time: ", p[i].pid);
//         scanf("%d", &p[i].at);
//         printf("Process P%d - Burst Time: ", p[i].pid);
//         scanf("%d", &p[i].bt);
//     }

//     sortByArrivalTime(p, n);

//     int current_time = 0;
//     float total_tat = 0, total_wt = 0;

//     for (int i = 0; i < n; i++) {
//         if (current_time < p[i].at) {
//             current_time = p[i].at; 
//         }

//         p[i].ct = current_time + p[i].bt;
//         p[i].tat = p[i].ct - p[i].at;
//         p[i].wt = p[i].tat - p[i].bt;

//         total_tat += p[i].tat;
//         total_wt += p[i].wt;

//         current_time = p[i].ct;
//     }

//     printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
//     for (int i = 0; i < n; i++) {
//         printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
//                p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
//     }

//     printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
//     printf("Average Waiting Time = %.2f\n", total_wt / n);

//     return 0;
// }
#include <stdio.h>

struct Process {
    int pid;
    int at;  
    int bt; 
    int ct; 
    int tat; 
    int wt;  
};

void sortByArrivalTime(struct Process p[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    printf("\nEnter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Process P%d - Arrival Time: ", p[i].pid);
        scanf("%d", &p[i].at);
        printf("Process P%d - Burst Time: ", p[i].pid);
        scanf("%d", &p[i].bt);
    }

    sortByArrivalTime(p, n);

    int current_time = 0;
    float total_tat = 0, total_wt = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < p[i].at) {
            current_time = p[i].at; 
        }

        p[i].ct = current_time + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        total_tat += p[i].tat;
        total_wt += p[i].wt;

        current_time = p[i].ct;
    }

    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
    printf("Average Waiting Time = %.2f\n", total_wt / n);

    return 0;
}