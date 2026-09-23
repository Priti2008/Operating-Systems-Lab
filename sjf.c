// #include <stdio.h>
// #include <stdbool.h>

// struct Process {
//     int pid;
//     int at; 
//     int bt; 
//     int ct; 
//     int tat; 
//     int wt; 
//     bool completed;
// };

// int main() {
//     int n = 5;
//     struct Process p[] = {
//         {1, 3, 4, 0, 0, 0, false},
//         {2, 5, 3, 0, 0, 0, false},
//         {3, 0, 2, 0, 0, 0, false},
//         {4, 5, 1, 0, 0, 0, false},
//         {5, 4, 3, 0, 0, 0, false}
//     };

//     int current_time = 0;
//     int completed_count = 0;
//     float total_tat = 0, total_wt = 0;

//     while (completed_count < n) {
//         int idx = -1;
//         int min_bt = 1e9;

       
//         for (int i = 0; i < n; i++) {
//             if (p[i].at <= current_time && !p[i].completed) {
//                 if (p[i].bt < min_bt) {
//                     min_bt = p[i].bt;
//                     idx = i;
//                 } else if (p[i].bt == min_bt) {
                    
//                     if (p[i].at < p[idx].at) {
//                         idx = i;
//                     }
//                 }
//             }
//         }

//         if (idx != -1) {
//             p[idx].ct = current_time + p[idx].bt;
//             p[idx].tat = p[idx].ct - p[idx].at;
//             p[idx].wt = p[idx].tat - p[idx].bt;
//             p[idx].completed = true;

//             total_tat += p[idx].tat;
//             total_wt += p[idx].wt;

//             current_time = p[idx].ct;
//             completed_count++;
//         } else {

//             current_time++;
//         }
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
#include <stdbool.h>

struct Process {
    int pid;
    int at; 
    int bt; 
    int ct; 
    int tat; 
    int wt; 
    bool completed;
};

int main() {
    int n = 5;
    struct Process p[] = {
        {1, 3, 4, 0, 0, 0, false},
        {2, 5, 3, 0, 0, 0, false},
        {3, 0, 2, 0, 0, 0, false},
        {4, 5, 1, 0, 0, 0, false},
        {5, 4, 3, 0, 0, 0, false}
    };

    int current_time = 0;
    int completed_count = 0;
    float total_tat = 0, total_wt = 0;

    while (completed_count < n) {
        int idx = -1;
        int min_bt = 1e9;

       
        for (int i = 0; i < n; i++) {
            if (p[i].at <= current_time && !p[i].completed) {
                if (p[i].bt < min_bt) {
                    min_bt = p[i].bt;
                    idx = i;
                } else if (p[i].bt == min_bt) {
                    
                    if (p[i].at < p[idx].at) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            p[idx].ct = current_time + p[idx].bt;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].completed = true;

            total_tat += p[idx].tat;
            total_wt += p[idx].wt;

            current_time = p[idx].ct;
            completed_count++;
        } else {

            current_time++;
        }
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