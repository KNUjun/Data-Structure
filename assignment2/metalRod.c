#include <stdio.h>
#include "stacksADT.h"

int main(void){
	STACK* stack;
	char token;
	bool isLaser;
	int rod = 0;
	char* dataPtr;
	
	stack = createStack();
	
	while((token = getchar()) != '\n'){
		if(token == '('){
			isLaser = true;
			dataPtr = (char*) malloc(sizeof(char));
			*dataPtr = token;
			pushStack(stack, dataPtr);
		}
		else if(token ==')' && isLaser){
			isLaser = false;
			dataPtr = popStack(stack);
			rod += stackCount(stack);
			free(dataPtr);
		}
		else{	// token == ')' && !isLaser
			dataPtr = popStack(stack);
			rod += 1;
			free(dataPtr);
		}
	}
	
	printf("# of rod : %d", rod);
	
	destroyStack(stack);
	return 0;
}
