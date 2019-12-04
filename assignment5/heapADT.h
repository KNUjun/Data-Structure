#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct{
	int** heapAry;
	int last;
	int size;
	int (*compare) (int* argu1, int* argu2);
	int maxSize;
}HEAP;

HEAP* heapCreate (int maxSize, int (*compare) (int* argu1, int* argue2));
int (*compare) (int num1, int num2);
bool heapInsert (HEAP* heap, int* dataPtr);
bool heapDelete (HEAP* heap, int** dataOutPtr);
int heapCount (HEAP* heap);
bool heapFull (HEAP* heap);
bool heapEmpty (HEAP* heap);
HEAP* heapDestroy (HEAP* heap);
static void _reheapUp (HEAP* heap, int childLoc);
static void _reheapDown (HEAP* heap, int root);

HEAP* heapCreate (int maxSize, int (*compare) (int* argu1, int* argu2)){
	HEAP* heap;
	
	heap = (HEAP*)malloc(sizeof (HEAP));
	if (!heap)
 		return NULL;
 		
	heap->last = -1;
	heap->compare = compare;

	heap->maxSize = (int) pow (2, floor(log2(maxSize)+1)) - 1;
	heap->heapAry = (int**)	calloc(heap->maxSize, sizeof(int*));
	
	return heap;
}

bool heapInsert (HEAP* heap, int* dataPtr){
	if (heap->size == 0){
 		heap->size = 1;
 		heap->last = 0;
 		heap->heapAry[heap->last] = dataPtr;
		return true;
 	}
	if (heap->last == heap->maxSize - 1)
 		return false;
	++(heap->last); 
	++(heap->size);
	heap->heapAry[heap->last] = dataPtr;
	_reheapUp (heap, heap->last);
	
	return true;
}
bool heapDelete (HEAP* heap, int** dataOutPtr){
	if (heap->size == 0)
		return false;
	*dataOutPtr = heap->heapAry[0];
	heap->heapAry[0] = heap->heapAry[heap->last];
	(heap->last)--;
	(heap->size)--;
	_reheapDown (heap, 0);
	return true;
}

int heapCount (HEAP* heap){
	return heap->size;	
}
bool heapFull (HEAP* heap){
	HEAP* temp;
	
	if((temp = (HEAP*) malloc(sizeof(HEAP)))){
		free(temp);
		return false;
	}
	return (heap->size >= heap->maxSize);
}
bool heapEmpty (HEAP* heap){
	return (heap->size == 0);
}

static void _reheapUp (HEAP* heap, int childLoc){
	int parent;
	int** heapAry;
	int* hold;

	if (childLoc){
 		heapAry = heap->heapAry;
 		parent = (childLoc - 1)/ 2;
 		if (heap->compare(heapAry[childLoc], heapAry[parent]) > 0){
 			hold = heapAry[parent]; 
 			heapAry[parent] = heapAry[childLoc];
 			heapAry[childLoc] = hold;
 			_reheapUp (heap, parent);
		}
 	}
	return;
}
static void _reheapDown (HEAP* heap, int root){
	int* hold;
	int* leftData;
	int* rightData;
	int largeLoc;
	int last;

	last = heap->last;
	if ((root * 2 + 1) <= last){
 		leftData = heap->heapAry[root * 2 + 1];
 		if ((root * 2 + 2) <= last)
 			rightData = heap->heapAry[root * 2 + 2];
 		else
 			rightData = NULL;
 
 		if ((!rightData) || heap->compare (leftData, rightData) > 0){
 			largeLoc = root * 2 + 1;
 		}
 		else{
 			largeLoc = root * 2 + 2;
 		}
 		if (heap->compare (heap->heapAry[root], heap->heapAry[largeLoc]) < 0){
 			hold = heap->heapAry[root];
 			heap->heapAry[root] = 
 			heap->heapAry[largeLoc]; 
 			heap->heapAry[largeLoc] = hold;
 			_reheapDown (heap, largeLoc);
 		}
	}
	return;
}	

HEAP* heapDestroy(HEAP* heap){
	int* deletePtr;
	int index=0;
	
	if(heap){
		while(index < heap->size){
			deletePtr = heap->heapAry[index++];
			free(deletePtr);
		}
		free(heap->heapAry);
		free(heap);
	}
	return NULL;
}
