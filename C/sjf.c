#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter total no. of processes? ");
    scanf("%d", &n);

    int arr[n][5];

    for (i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &arr[i][0]);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arr[i][1]);
        arr[i][2] = 0;
        arr[i][3] = i + 1;
    }

    int time = 0, count = 0;

    while (count < n) {
        int min = 1000, index = -1;
        
        for (i = 0; i < n; i++) {
            if (arr[i][1] <= time && arr[i][2] == 0 && arr[i][0] < min) {
                min = arr[i][0];
                index = i;
            }
        }

        if (index != -1) {
            time += arr[index][0];
            arr[index][2] = time;
            arr[index][4] = count;
            count++;
        } else {
            time++;
        }
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j][1] > arr[j + 1][1]) {
                for (int k = 0; k < 5; k++) {
                    int temp = arr[j][k];
                    arr[j][k] = arr[j + 1][k];
                    arr[j + 1][k] = temp;
                }
            }
        }
    }

    printf("Process\tBT\tAT\tCT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", arr[i][3], arr[i][0], arr[i][1], arr[i][2]);
    }
return 0;
    
}
