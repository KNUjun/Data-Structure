//2016117116_LeeJunGi_Assignment1_05 
#include <stdio.h>

void copy_array(int from[], int to[], int n){
	int i;
	for(i=0;i<n;i++){
		to[i]=from[i];
	}
}

int main(void){
	int from[] = {7, 2, 1, 0, 4, 6};
	int to[20];
	int i, n, size_f, size_t;
	
	printf("n = ? : ");
	scanf("%d", &n);
	
	size_f = sizeof(from)/sizeof(int); // length of 'from'
	size_t = sizeof(to)/sizeof(int); // length of 'to'
	
	// if n is larger than length of array
	// or n is negative integer, break
	if( (size_f<n)||(size_t<n)||(n<0) ){
		printf("n is wrong number.\n");
		return 0;
	}
	
	copy_array(from, to, n);
	
	for(i=0;i<n;i++){
		printf("%d ",to[i]);
	}
	printf("\n");
	
	return 0;
}
