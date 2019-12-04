//2016117116_LeeJunGi_Assignment1_08 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// n is number of integers
#define n 100

int main(void){
	int i, *arr;
	int min=n, max=1, sum=0;
	double mean, var=0;
	
	srand(time(NULL));
	arr = (int*) malloc(sizeof(int)*n);
	
	// assignment and get sum, min, max
	for(i=0;i<n;i++){
		*(arr+i) = (rand() % n) + 1;
		sum += *(arr+i);
		if(min>*(arr+i)) min=*(arr+i);
		if(max<*(arr+i)) max=*(arr+i);
	}
	
	// get mean and var
	mean = sum/(double)n ;
	for(i=0; i<n; i++){
		var += (*(arr+i)-mean)*(*(arr+i)-mean);
	}
	var /= (double)n;
	
	printf("MAX : %d\nmin : %d\nmean : %.2f\nvar : %.2f\n",max,min,mean,var);
	free(arr);
	
	return 0;
}
