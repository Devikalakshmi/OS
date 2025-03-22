#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int bt[n], at[n], pr[n], wt[n], tat[n], ct[n];
    bool completed[n];
    int i, total_wt = 0, total_tat = 0, completed_count = 0, current_time = 0;

    for (i = 0; i < n; i++) {
        printf("Enter arrival and burst time for process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &pr[i]);
        completed[i] = false;
    }

    while (completed_count < n) {
        int highest_priority = 9999, index = -1;
        for (i = 0; i < n; i++) {
            if (!completed[i] && at[i] <= current_time && pr[i] < highest_priority) {
                highest_priority = pr[i];
                index = i;
            }
        }
        
        if (index == -1) {
            current_time++;
        } else {
            ct[index] = current_time + bt[index];
            current_time = ct[index];
            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];
            completed[index] = true;
            completed_count++;
            total_wt += wt[index];
            total_tat += tat[index];
        }
    }

    printf("\nProcess\tPriority\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, pr[i], bt[i], at[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);
    printf("Average Waiting Time: %.2f\n", (float)total_wt / n);
    
    return 0;
}

