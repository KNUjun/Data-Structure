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
	printf("���� �ϳ��� �Է��ϼ��� : ");
	scanf("%c",&ch);
	
	printf("�Է��� ���� %c�� �ƽ�Ű �ڵ�� 0x%X �̴�.\n\n", ch, ch);
	printf("���� %c�� �ƽ�Ű �ڵ��� ���� �������� ������ ����\n", ch);
	binary(ch);
	
	return 0;
}
