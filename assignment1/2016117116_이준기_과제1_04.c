//2016117116_LeeJunGi_Assignment1_04
#include <stdio.h>

int main(void){
	short a[][3] = {2, 4, 6, 8, 10, 12, 1, 3, 5, 7, 9, 11};
	printf( "%d\n", sizeof(a) ); 			// 24
	printf( "%d\n", sizeof(a[0]) ); 		// 6
	printf( "%d\n", sizeof(a[0][0]) ); 		// 2
	printf( "%d\n", sizeof(a) / sizeof(a[0]) ); 		// 4
	printf( "%d\n", sizeof(a[0]) / sizeof(a[0][0]) ); 	// 3
	printf( "%d\n", sizeof(a) / sizeof(a[0][0]) ); 		// 12
	
	return 0;
}
