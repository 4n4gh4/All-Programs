#include <stdio.h>

void FCFS();
void SJF();
void RR();
void Pri();

int main() {
    int choice;

    printf("Select Scheduling Algorithm:\n");
    printf("1. First-Come, First-Served (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Round Robin (RR)\n");
    printf("4. Priority Scheduling\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            FCFS();
            break;
        case 2:
            SJF();
            break;
        case 3:
            RR();
            break;
        case 4:
            Pri();
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

void FCFS() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int arrival[n], burst[n], process[n];
    int turn_around[n], waiting_time[n], comp_time[n];
    
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time of P[%d]: ", i + 1);
        scanf("%d", &arrival[i]);
    }
    
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("Enter the burst time of P[%d]: ", i + 1);
        scanf("%d", &burst[i]);
    }

    // Sort by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arrival[i] > arrival[j]) {
                int temp = arrival[i];
                arrival[i] = arrival[j];
                arrival[j] = temp;

                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;

                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    comp_time[0] = burst[0];
    for (int i = 1; i < n; i++) {
        comp_time[i] = burst[i] + comp_time[i - 1];
    }

    for (int i = 0; i < n; i++) {
        turn_around[i] = comp_time[i] - arrival[i];
        waiting_time[i] = turn_around[i] - burst[i];
    }

    printf("\nNew order of processes and their burst times:\n");
    for (int i = 0; i < n; i++) {
        printf("P[%d]: Burst Time = %d\n", process[i], burst[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("Completion time of P[%d]: %d\n", process[i], comp_time[i]);
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("Turnaround time of P[%d]: %d\n", process[i], turn_around[i]);
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("Waiting time of P[%d]: %d\n", process[i], waiting_time[i]);
    }
}

void SJF() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrival[n], burst[n], process[n];
    int turn_around[n], waiting_time[n], comp_time[n];
    
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time of P[%d]: ", i + 1);
        scanf("%d", &arrival[i]);
    }
    
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("Enter the burst time of P[%d]: ", i + 1);
        scanf("%d", &burst[i]);
    }

    // Sort by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arrival[i] > arrival[j]) {
                int temp = arrival[i];
                arrival[i] = arrival[j];
                arrival[j] = temp;

                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;

                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    // Sort by burst time if arrival times are the same
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arrival[i] == arrival[j] && burst[i] > burst[j]) {
                int temp = arrival[i];
                arrival[i] = arrival[j];
                arrival[j] = temp;

                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;

                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    comp_time[0] = burst[0];
    for (int i = 1; i < n; i++) {
        comp_time[i] = burst[i] + comp_time[i - 1];
    }

    for (int i = 0; i < n; i++) {
        turn_around[i] = comp_time[i] - arrival[i];
        waiting_time[i] = turn_around[i] - burst[i];
    }

    for (int i = 0; i < n; i++) {
        printf("Completion time of P[%d]: %d\n", process[i], comp_time[i]);
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("Turnaround time of P[%d]: %d\n", process[i], turn_around[i]);
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("Waiting time of P[%d]: %d\n", process[i], waiting_time[i]);
    }
}

void RR() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrival[n], burst[n], process[n];
    int rem_time[n], waiting_time[n], turn_around[n], comp_time[n];
    
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time of P[%d]: ", i + 1);
        scanf("%d", &arrival[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time of P[%d]: ", i + 1);
        scanf("%d", &burst[i]);
        rem_time[i] = burst[i];
    }

    int current_time = 0;
    int completed = 0;
    int i = 0;
    const int quantum = 4; // Time quantum for Round Robin

    while (completed < n) {
        if (rem_time[i] > 0) {
            if (arrival[i] <= current_time) {
                if (rem_time[i] <= quantum) {
                    current_time += rem_time[i];
                    comp_time[i] = current_time;
                    rem_time[i] = 0;
                    completed++;
                } else {
                    current_time += quantum;
                    rem_time[i] -= quantum;
                }
            } else {
                current_time++;
            }
        }
        i = (i + 1) % n;
    }

    for (int i = 0; i < n; i++) {
        turn_around[i] = comp_time[i] - arrival[i];
        waiting_time[i] = turn_around[i] - burst[i];
    }

    printf("\nCompletion time of processes:\n");
    for (int i = 0; i < n; i++) {
        printf("P[%d]: %d\n", process[i], comp_time[i]);
    }
    
    printf("\nTurnaround time of processes:\n");
    for (int i = 0; i < n; i++) {
        printf("P[%d]: %d\n", process[i], turn_around[i]);
    }
    
    printf("\nWaiting time of processes:\n");
    for (int i = 0; i < n; i++) {
        printf("P[%d]: %d\n", process[i], waiting_time[i]);
    }
}

void Pri
() {
    
    int n, i, j, temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrival[n], burst[n], priority[n], p[n];

    

    for (int i=0; i<n; i++){
        p[i] = i+1;
        printf("Enter the arrival time of P[%d]: ", i+1);
        scanf("%d", &arrival[i]);
    }
    printf("\n");
    for(int i=0; i<n; i++){
        printf("Enter the burst time of P[%d]: ", i+1);
        scanf("%d", &burst[i]);
    }

    printf("\n");
    for(int i=0; i<n; i++){
        printf("Enter the priority of P[%d]: ", i+1);
        scanf("%d", &priority[i]);
    }



    // Sort by arrival time
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (arrival[i] > arrival[j]) {
                temp = arrival[i];
                arrival[i] = arrival[j];
                arrival[j] = temp;

                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;

                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int sum = arrival[0];
    for (i = 1; i < n; i++) {
        sum += arrival[i];
        if (sum > arrival[i]) {
            // Sort by priority
            for (j = i; j < n-1; j++) {
                if (priority[j] > priority[j+1]) {
                    temp = priority[j];
                    priority[j] = priority[j+1];
                    priority[j+1] = temp;

                    temp = burst[j];
                    burst[j] = burst[j+1];
                    burst[j+1] = temp;

                    temp = arrival[j];
                    arrival[j] = arrival[j+1];
                    arrival[j+1] = temp;

                    temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                }
            }
        }
    }

    printf("Sorted processes by arrival time and priority:\n");
    for (i = 0; i < n; i++) {
        printf("Process P%d: Arrival time = %d, Burst time = %d, Priority = %d\n", p[i], arrival[i], burst[i], priority[i]);
    }
    
    
    int turn_around[n];
    int waiting_time[n];

    int comp_time[n];
    comp_time[0]=burst[0]+arrival[0];
    for(int i=1; i<n; i++){

        comp_time[i]=burst[i]+comp_time[i-1];
    }

    for(int i=0; i<n; i++){
        turn_around[i]=comp_time[i]-arrival[i];
        waiting_time[i]=turn_around[i]-burst[i];
    }

    for(int i=0; i<n; i++){
        printf("Completion time of P[%d]: %d\n", p[i], comp_time[i]);
    }

    printf("\n");

    for(int i=0; i<n; i++){
        printf("Turn around tim of P[%d]: %d\n", p[i], turn_around[i]);
    }
    printf("\n");

    for(int i=0; i<n; i++){
        printf("Waiting time of P[%d]: %d\n", p[i], waiting_time[i]);
    }





}

