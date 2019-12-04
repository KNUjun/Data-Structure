//2016117116_LeeJunGi_Assignment1_03
#include <stdio.h>

//printing binary number of 8 bit 
void binary(char c){
	int arr[8], i;
	for(i=7; i>=0; i--){
		arr[i] = c%2;
		c/=2;
	}
	for(i=0; i<8; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");	
}

int main(void){
	char ch;
	printf("문자 하나를 입력하세요 : ");
	scanf("%c",&ch);
	
	printf("입력한 문자 %c의 아스키 코드는 0x%X 이다.\n\n", ch, ch);
	printf("문자 %c의 아스키 코드의 내부 이진수는 다음과 같다\n", ch);
	binary(ch);
	
	return 0;
}
