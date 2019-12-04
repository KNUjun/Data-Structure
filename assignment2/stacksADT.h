#ifndef __STACKSADT_H__
#define __STACKSADT_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//node of stack
typedef struct node{
	void* dataPtr;
	struct node* link;	
}STACK_NODE;

//head of stack
typedef struct{
	int count;
	STACK_NODE* top;
}STACK;

STACK* createStack(void){
	STACK* stack;
	
	stack = (STACK*)malloc(sizeof(STACK));
	if(stack){
		stack->count = 0;
		stack->top = NULL;
	}
	return stack;
}

bool pushStack(STACK* stack, void* dataInPtr){
	STACK_NODE* newPtr;
	
	newPtr = (STACK_NODE*) malloc(sizeof(STACK_NODE*));
	if(!newPtr)
		return false;
	
	newPtr->dataPtr = dataInPtr;
	newPtr->link = stack->top;
	stack->top = newPtr;
	
	(stack->count)++;
	return true;
}

//remove top node and return dataPtr of top
void* popStack(STACK* stack){
	void* dataOutPtr;
	STACK_NODE* temp;
	
	if(stack->count == 0)
		dataOutPtr = NULL;
	else{
		temp = stack->top;
		dataOutPtr = stack->top->dataPtr;
		stack->top = stack->top->link;
		free(temp);
		(stack->count)--;
	}
	return dataOutPtr;
}

//return dataPtr of top
void* stackTop(STACK* stack){
	if(stack->count == 0)
		return NULL;
	else
		return stack->top->dataPtr;
}

//is Stack empty?
bool emptyStack(STACK* stack){
	return (stack->count == 0);
}

//is heap full?
//namely, we cannot create stack
bool fullStack(STACK* stack){
	STACK_NODE* temp;
	
	if((temp = (STACK_NODE*) malloc(sizeof(STACK_NODE*)))){
		free(temp);
		return false;
	}
	return true;
}

//return count of stack
int stackCount(STACK* stack){
	return stack->count;
}

//free all heap data and return null
STACK* destroyStack(STACK* stack){
	STACK_NODE* temp;
	
	if(stack){
		while(stack->top != NULL){
			free(stack->top->dataPtr);
			
			temp= stack->top;
			stack->top = stack->top->link;
			free(temp);
		}
	free(stack);
	}
	return NULL;
}

#endif
