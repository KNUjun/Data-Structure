//2016117116_LeeJunGi_Assignment1_06
#include <stdio.h>

int a();
int g = 200;
void main(void){
	int b = 10;
	printf("%d\n", g + b) ;		// 210
	printf("%d\n", a() ) ;		// 110
	printf("%d\n", a() ) ;		// 112
	printf("%d\n", a() ) ;		// 114
}

static int sg = 100;
int a(){
	static int s = 10 ;
	return s++ + sg++;
}
