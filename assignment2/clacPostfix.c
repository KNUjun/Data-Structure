#include <stdio.h>
#include "stacksADT.h"

bool isOperator(char token);
int calc(int operand1, int oper, int operand2);

int main(void){
	char token;
	int operand1;
	int operand2;
	int value;
	int* dataPtr;
	STACK* stack;
	
	stack = createStack();
	
	//postfix expression
	printf("Input formula: ");
	while((token = getchar()) != '\n'){
		if(!isOperator(token)){
			dataPtr = (int*) malloc(sizeof(int));
			*dataPtr = atoi(&token);
			pushStack(stack, dataPtr);
		}
		else{
			dataPtr = (int*)popStack(stack);
			operand2 = *dataPtr;
			dataPtr = (int*)popStack(stack);
			operand1 = *dataPtr;
			value = calc(operand1, token, operand2);
			dataPtr = (int*)malloc(sizeof(int));
			*dataPtr = value;
			pushStack(stack, dataPtr);
		}
	}
	
	dataPtr = (int*) popStack(stack);
	value = *dataPtr;
	printf("The result is: %d\n", value);
	
	destroyStack(stack);
	return 0;
}

bool isOperator(char token){
	if(token == '*'
		|| token == '/'
		|| token == '+'
		|| token == '-')
		return true;
	return false;
}

int calc(int operand1, int oper, int operand2){
	int result;
	
	switch(oper){
		case '+' :
			result = operand1 + operand2;
			break;
		case '-' :
			result = operand1 - operand2;
			break;
		case '*' :
			result = operand1 * operand2;
			break;
		case '/' :
			result = operand1 / operand2;
			break;
	}
	return result;
}
