#include <stdio.h>
#include <string.h>
#include "stacksADT.h"

int priority(char token);
bool isOperator(char token);
int calc(int operand1, int oper, int operand2);
void calc_postfix(char* postfixIn);

int main(void){
	char postfix[80] = {0};
	char temp[2] = {0};
	char token;
	char* dataPtr;
	STACK* stack;
	
	stack = createStack();
	
	printf("Enter an infix formula: ");
	
	while((token = getchar()) != '\n'){
		if(token == '('){
			dataPtr = (char*) malloc(sizeof(char));
			*dataPtr = token;
			pushStack(stack, dataPtr);
		}
		else if(token == ')'){
			dataPtr = (char*)popStack(stack);
			while(*dataPtr != '('){
				temp[0]= *dataPtr;
				strcat(postfix, temp);
				dataPtr = (char*) popStack(stack);
			}
		}
		else if(isOperator(token)){
			dataPtr = (char*) stackTop(stack);
			while(!emptyStack(stack)
				&& (priority(token) <= priority(*dataPtr))){
				dataPtr = (char*) popStack(stack);
				temp[0] = *dataPtr;
				strcat(postfix, temp);
				dataPtr = (char*) stackTop(stack);
			}
			dataPtr = (char*) malloc(sizeof(char));
			*dataPtr = token;
			pushStack(stack, dataPtr);
		}
		else{
			temp[0] = token;
			strcat(postfix, temp);
		}
	}
	
	while(!emptyStack(stack)){
		dataPtr = (char*)popStack(stack);
		temp[0] = *dataPtr;
		strcat(postfix, temp);
	}
	
	printf("The postfix formula is: ");
	puts(postfix);
	calc_postfix(postfix);
	
	destroyStack(stack);
	return 0;
}


int priority(char token){
	if(token == '*' || token == '/')
		return 2;
	if(token == '+' || token == '-')
		return 1;
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
void calc_postfix(char* postfixIn){
	char token;
	int operand1;
	int operand2;
	int value;
	int* dataPtr;
	STACK* stack;
	int i = 0;
	
	stack = createStack();

	while((token = *(postfixIn+(i++))) != '\0'){
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
}

