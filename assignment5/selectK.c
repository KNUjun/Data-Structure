#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heapADT.h"

void buildHeap(HEAP* heap, int arrSize);
bool selectK(HEAP* heap, int heapLast);
int cmpInt (int* argu1, int* argu2);
void printHeap(HEAP* heap);

int main(void){
	HEAP* heap;
	int heapSize;
	
	printf( " ====================================	\n"
			"| Enter positive integer numbers.    |	\n"
			"| Please enjoy my program.           |	\n"
			"| Thank you.                         |	\n"
			" ====================================	\n\n"
			"Enter size of HEAP : ");
	scanf("%d",&heapSize);
	heap = heapCreate(heapSize, cmpInt);
	
	buildHeap(heap, heapSize);
	selectK(heap, heap->last);
	
	heapDestroy(heap);
	return 0;
}

void buildHeap(HEAP* heap, int arrSize){
	int walker;
	int* numPtr;
	
	printf("\nEnter integers :\n");
	walker = 0;
	while(walker++ < arrSize){
		if( numPtr = (int*) malloc(sizeof(int))){
			scanf("%d", numPtr);
			if(*numPtr <= 0) break;
			heapInsert(heap, numPtr);
		}
	}
	while(getchar() != '\n' );
	
	printHeap(heap);
	return;
}

bool selectK(HEAP* heap, int heapLast){
	int origHeapSize;
	int* temp;
	int* holdOut;
	int i = 0;
	int k;
	
	printf("Enter k for the k-th largetst number : ");
		
	scanf("%d", &k);
	
	if(k> heap->size){
		printf("k is larger than heap size\n");
		return false;
	}
	
	origHeapSize = heap->size;
	while((i++) < k-1){
		heapDelete(heap, &temp);
		heap->heapAry[heap->last+1] = temp;
	}
	holdOut = heap->heapAry[0];
	while(heap->size < origHeapSize){
		heapInsert(heap, heap->heapAry[heap->last+1]);
	}
	
	printf("\nthe %d-th largest num : %d\n", k, *holdOut);
	return true;
}

int cmpInt (int* argu1, int* argu2){
	int result;
	int num1;
	int num2;
	
	num1 = *argu1;
	num2 = *argu2;
	
	if(num1 < num2)
		result = -1;
	else if(num1 > num2)
		result = +1;
	else
		result = 0;
	return result;
}

void printHeap(HEAP* heap){
	int num;
	int i;
	
	printf("\nheap array : ");
	for(i=0; i < heap->size; i++){
		num = *(heap->heapAry[i]);
		printf("%d ", num );
	}
	printf("\n\n");
}
