//2016117116_LeeJunGi_Assignment1_07
#include <stdio.h>

// adding n to every element of array
void plus(int data[], int n){
	int i;
	
	for(i=0;i<7;i++){
		data[i]+=n;
	}
}

int main(void){
	int data[] = {3,21,35,57,24,82,8};
	int n, i;
	
	printf("n = ? : ");
	scanf("%d", &n);
	
	plus(data, n);
	for(i=0; i<7; i++){
		printf("%d ",data[i]);
	}
	printf("\n");
	
	return 0;
}
