#include<stdio.h>

void main(){

	int n, min, max, i, ct=0, j;
	printf("Enter total no. of processes: ");
	scanf("%d", &n);

	int arr[n][3];

	for(i=0;i<n;i++){
		
		

		printf("Enter burst time for process %d: ", i+1);
		scanf("%d", &arr[i][0]);
		printf("Enter arrival time for process %d: ", i+1);
		scanf("%d", &arr[i][1]);

	}
	
	min = arr[0][1];
	max = arr[0][1];


	printf("The table is:\n");
	printf("Proces	BT	AT \n");
	
	for(i=0;i<n;i++){
	
		arr[i][2] = i+1;
	
		printf("P%d	", i+1);
		printf("%d	", arr[i][0]);
		printf("%d	", arr[i][1]);
		printf("\n");

	
	}




	for(i=0;i<n;i++){
		
		if(arr[i][1]< min){
		
			min = arr[i][1];
		
		}
	}

	for(i=0;i<n;i++){

		if(arr[i][1]>max){
		
			max = arr[i][1];
		
		}

	}

	printf("The max arrival time is: %d\n", max);
	printf("The min arrival time is: %d\n", min);


	int arr2[n][6], k;



j=0;

for(k=0;k<=max;k++){
for(i=0;i<n;i++){

	if(arr[i][1]==min && min<=max){
		
		arr2[j][5] = arr[i][2];
		arr2[j][1] = arr[i][1];
	       	arr2[j][0] = arr[i][0];
		j++;	
	
	}

}
min++;
}

//sorted array for storing values of processes according to ascending order of arrival time

	


	
	arr2[0][2] = arr2[0][0];
	for(i=1;i<n;i++){
	
	arr2[i][2] = arr2[i][0] + arr2[i-1][2];

	} //calculates the completion time in a separate column

	
	
	for(i=0;i<n;i++){
	
		arr2[i][3] = arr2[i][2] - arr2[i][1];
	
	} // calculates the turn around time
	

	for(i=0;i<n;i++){
	
		arr2[i][4] = arr2[i][3] - arr2[i][0];
	
	}// waiting time
	
	
	
printf("The final table (2) is:\n");
	printf("Proces	BT	AT	CT	TAT	WT\n");
	
	for(i=0;i<n;i++){
	
		printf("P%d	", arr2[i][5]);
		printf("%d	", arr2[i][0]);
		printf("%d	", arr2[i][1]);
		printf("%d	", arr2[i][2]);
		printf("%d	", arr2[i][3]);
		printf("%d	", arr2[i][4]);
		printf("\n");

	
	}
	
}