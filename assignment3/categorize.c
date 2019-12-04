#include <stdio.h>
#include "queues.h"

void fillQueues(QUEUE*, QUEUE*, QUEUE*, QUEUE*);
void printQueues(QUEUE*, QUEUE*, QUEUE*, QUEUE*);

void printOneQueue(QUEUE* pQueue);

int main(void){
	QUEUE* q0to9;
	QUEUE* q10to19;
	QUEUE* q20to29;
	QUEUE* qOver29;
	
	printf("welcom to a demonstration of categorizing\n");
	
	q0to9 = createQueue();
	q10to19 = createQueue();
	q20to29 = createQueue();
	qOver29 = createQueue();
	
	fillQueues(q0to9, q10to19, q20to29, qOver29);
	printQueues(q0to9, q10to19, q20to29, qOver29);
	
	return 0;
}

void fillQueues(QUEUE* q0to9, QUEUE*q10to19,
				QUEUE* q20to29, QUEUE* qOver29){
	int category;
	int item;
	int* dataPtr;
	int i;
	
	printf("Categorizing data:\n");
	srand(79);
	
	for(i=1; i<=25; i++){
		if(!(dataPtr = (int*) malloc(sizeof(int))))
			printf("Overflow in fillQueues\a\n"), exit(100);
		
		*dataPtr = item = rand()% 51;
		category = item / 10;
		printf("%3d", item);
		if(!(i%11))
			printf("\n");
			
		switch(category){
			case 0 : enqueue(q0to9, dataPtr);
					 break;
			case 1 : enqueue(q10to19, dataPtr);
					 break;
			case 2 : enqueue(q20to29, dataPtr);
					 break;
			default : enqueue(qOver29, dataPtr);
					 break;
		}
	}
	printf("\nEnd of data categorization\n\n");
	return ;
}

void printQueues(QUEUE* q0to9, QUEUE*q10to19,
				QUEUE* q20to29, QUEUE* qOver29){
	printf("Data	0..9:");
	printOneQueue(q0to9);
	printf("Dat   10..19:");
	printOneQueue(q10to19);
	printf("Data  20..29:");
	printOneQueue(q20to29);
	printf("Data over 29:");
	printOneQueue(qOver29);
	
	return;			
}

void printOneQueue(QUEUE* pQueue){
	int lineCount;
	int* dataPtr;
	
	lineCount = 0;
	while(!emptyQueue(pQueue)){
		dequeue(pQueue, (void*)&dataPtr);
		if(lineCount++ >= 10){
			lineCount = 1;
			printf("\n");
		}
		printf("%3d",*dataPtr);
	}
	printf("\n");
	
	return;
}
