// #include <stdio.h>
// #include <limits.h>
// struct Process {
//     int id;
//     int at;   
//     int bt;   
//     int rt;   
//     int ct;   
//     int tat;  
//     int wt;   
// };
// int main() {
//     int n;
//     printf("Enter the number of processes: ");
//     scanf("%d", &n);
//      struct Process p[n];
//     for(int i = 0; i < n; i++) {
//         p[i].id = i + 1;
//         printf("Enter Arrival Time and Burst Time for Process %d: ", p[i].id);
//         scanf("%d %d", &p[i].at, &p[i].bt);
//         p[i].rt = p[i].bt; // Initialize remaining time with burst time
//     }
//     int completed = 0, current_time = 0, min_rt = INT_MAX;
//     int shortest = 0, check = 0;
//     float total_wt = 0, total_tat = 0;
//     while (completed != n) {
//         for (int i = 0; i < n; i++) {
//             if ((p[i].at <= current_time) && (p[i].rt < min_rt) && (p[i].rt > 0)) {
//                 min_rt = p[i].rt;
//                 shortest = i;
//                 check = 1;
//             }
//         }
//         if (check == 0) {
//             current_time++;
//             continue;
//         }
//          p[shortest].rt--;
//         min_rt = p[shortest].rt;

//         if (min_rt == 0) {
//             min_rt = INT_MAX;
//         }
//         if (p[shortest].rt == 0) {
//             completed++;
//             check = 0;
            
//             p[shortest].ct = current_time + 1;
//             p[shortest].tat = p[shortest].ct - p[shortest].at;
//             p[shortest].wt = p[shortest].tat - p[shortest].bt;

//             if (p[shortest].wt < 0)
//                 p[shortest].wt = 0;

//             total_wt += p[shortest].wt;
//             total_tat += p[shortest].tat;
//         }
//         current_time++;
//     }
//      printf("\n--- SRTF Scheduling Results ---\n");
//     printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
//     for(int i = 0; i < n; i++) {
//         printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
//     }
//     printf("\nAverage Waiting Time = %.2f", total_wt / n);
//     printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
//     return 0;
// }
#include <stdio.h>
#include <limits.h>
struct Process {
    int id;
    int at;   
    int bt;   
    int rt;   
    int ct;   
    int tat;  
    int wt;   
};
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
     struct Process p[n];
    for(int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", p[i].id);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt; // Initialize remaining time with burst time
    }
    int completed = 0, current_time = 0, min_rt = INT_MAX;
    int shortest = 0, check = 0;
    float total_wt = 0, total_tat = 0;
    while (completed != n) {
        for (int i = 0; i < n; i++) {
            if ((p[i].at <= current_time) && (p[i].rt < min_rt) && (p[i].rt > 0)) {
                min_rt = p[i].rt;
                shortest = i;
                check = 1;
            }
        }
        if (check == 0) {
            current_time++;
            continue;
        }
         p[shortest].rt--;
        min_rt = p[shortest].rt;

        if (min_rt == 0) {
            min_rt = INT_MAX;
        }
        if (p[shortest].rt == 0) {
            completed++;
            check = 0;
            
            p[shortest].ct = current_time + 1;
            p[shortest].tat = p[shortest].ct - p[shortest].at;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;

            if (p[shortest].wt < 0)
                p[shortest].wt = 0;

            total_wt += p[shortest].wt;
            total_tat += p[shortest].tat;
        }
        current_time++;
    }
     printf("\n--- SRTF Scheduling Results ---\n");
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
    return 0;
}