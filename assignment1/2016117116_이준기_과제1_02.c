//2016117116_LeeJunGi_Assignment1_02
#include <stdio.h>

/*
	To find the sum of each digit of
	arbitary decimal number 'n'
	
	ex)
	if n = 2542,
	each digit is 2, 5, 4, and 2.
	therefore, sum is will be 2+5+4+2=13.
*/


int main(void){
	int digit, n, sum=0;
	scanf("%d",&n);
	
	do{
		digit = n%10;
		sum += digit;
		n /= 10;
	}while(n>0);
	
	printf("%d\n", sum);
	
	return 0;
}
