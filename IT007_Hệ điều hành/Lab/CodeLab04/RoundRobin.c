#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

struct Process{
    int AT, BT, WT, FT, TAT, pos;
    int ST[20];
};

int quantum;

int main(){
    int n, i, j;
    //Take input
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];

    printf("\nEnter the quantum time: ");
    scanf("%d", &quantum);

    printf("\nEnter the processes ID: \n");
    for (int i = 0; i < n; i++ ){
        scanf("%d", &(p[i].pos));
    }

    printf("\nEnter the arrival time of processes: ");
    for (int i = 0; i < n; i++ ){
        scanf("%d", &(p[i].AT));
    }

    printf("\nEnter the burst time of processes: ");
    for (int i = 0; i < n; i++ ){
        scanf("%d", &(p[i].BT));
    }

    // init variables 
    int c = n;
    int index = -1;
    int s[n][20];
    float time = 0;
    float min = INT_MAX;
    float burst[n], arrival[n];

    //create BT, AT arrays
    for(i = 0; i < n; i++){
        burst[i] = p[i].BT;
        arrival[i] = p[i].AT;
        for (j = 0; j < 20; j++)
            s[i][j] = -1;
    }

    int totalWT = 0, totalTAT = 0;
    bool flag = 0;

    // execute round robin

    while (c != 0){
        min = INT_MAX;
        flag = 0;
        
        for (i = 0; i < n; i++){
            float p = time + 0.1;
            if (arrival[i] <= p && min > arrival[i] && burst[i] > 0){
                index = i;
                min = arrival[i];
                flag = 1;
            }

        }

        // if arrival time = 1 -> stop loop -> flag = 0
        if (flag == 0){
            time++;
            continue;
        }

        // calculate start time
        j = 0;
        while (s[index][j] != -1){
            j++;
        }

        if (s[index][j] == -1){
            s[index][j] = time;
            p[index].ST[j] = time;
        }

        if (burst[index] <= quantum){
            time += burst[index];
            burst[index] = 0;
        }
        else
        {
            time += quantum;
            burst[index] -= quantum;
        }

        if (burst[index] > 0)
        {
            arrival[index] = time + 0.1;
        }

        // calculate arrival, burst, final time:
        if(burst[index] == 0){
            c--;
            p[index].FT = time;
            p[index].WT = p[index].FT - p[index].AT  - p[index].BT;
            totalWT += p[index].WT;

            p[index].TAT = p[index].BT + p[index].WT;
            totalTAT += p[index].TAT;
        }

    }

    // print result
    printf("Process ID | ");
    printf("Arrival time | ");
    printf("Burst time | ");
    printf("\tStart time | ");

    j = 0;
    while (j != 10){
        j+= 1;
        printf(" ");
    }
    printf("\t\tFinal time | ");
    printf("\tWait time | ");
    printf("\tTurn around time |\n");

    for (i = 0; i < n; i++){
        printf("%d\t\t", p[i].pos);
        printf("%d\t\t", p[i].AT);
        printf("%d\t\t", p[i].BT);

        j = 0;
        int v = 0;
        while (s[i][j] != -1){
            printf("%d ", p[i].ST[j]);
            j++;
            v+=3;
        }

        while (v!= 40){
            printf(" ");
            v += 1;
        }

        printf("%d\t\t", p[i].FT);
        printf("%d\t\t", p[i].WT);
        printf("%d\n", p[i].TAT);
    }

    // calculate average wait time and turn around time
    double avgWT, avgTAT;
    avgWT = totalWT/(n*1.0);
    avgTAT = totalTAT/(n*1.0);

    // print 
    printf("Average wait time (WT) = %lf\n", avgWT);
    printf("Average turn around time (TAT) = %lf\n", avgTAT);

    return 0;

}