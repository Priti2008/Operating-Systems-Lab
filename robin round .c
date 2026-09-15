
#include <stdio.h>

struct Process {
    int id;
    int at;   
    int bt;   
    int rem_bt; 
    int ct;   
    int tat;  
    int wt;   
};

int main() {
    int n = 4;
    int tq = 3; 

   
    struct Process p[4] = {
        {0, 0, 5, 5, 0, 0, 0},
        {1, 0, 5, 5, 0, 0, 0},
        {2, 2, 1, 1, 0, 0, 0},
        {3, 4, 3, 3, 0, 0, 0}
    };

   
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(p[i].at > p[j].at) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int time = 0, completed = 0;
    int queue[100], front = 0, rear = 0;
    int in_queue[4] = {0};

    
    for(int i = 0; i < n; i++) {
        if(p[i].at <= time) {
            queue[rear++] = i;
            in_queue[i] = 1;
        }
    }

    while(completed < n) {
        if(front == rear) {
            time++;
            for(int i = 0; i < n; i++) {
                if(p[i].at <= time && !in_queue[i] && p[i].rem_bt > 0) {
                    queue[rear++] = i;
                    in_queue[i] = 1;
                }
            }
            continue;
        }

        int idx = queue[front++];

        if(p[idx].rem_bt > tq) {
            time += tq;
            p[idx].rem_bt -= tq;
        } else {
            time += p[idx].rem_bt;
            p[idx].rem_bt = 0;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            completed++;
        }

        // Check for newly arrived processes during this execution window
        for(int i = 0; i < n; i++) {
            if(p[i].at <= time && !in_queue[i] && p[i].rem_bt > 0) {
                queue[rear++] = i;
                in_queue[i] = 1;
            }
        }

        // If process is not finished, push it back to the queue
        if(p[idx].rem_bt > 0) {
            queue[rear++] = idx;
        }
    }

    // Displaying Results matching the sample output format
    float total_wt = 0, total_tat = 0;
    
    printf("\n--- Round Robin Scheduling Results (TQ = %d) ---\n", tq);
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    
    for(int i = 0; i < n; i++) {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
    printf("Average Waiting Time = %.2f\n", total_wt / n);

    return 0;
}