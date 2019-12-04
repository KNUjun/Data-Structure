#include <stdio.h>
#include <time.h>
#include "queues.h"

//customer Status
typedef struct{
	int custNum;
	int arriveTime;
	int startTime;
	int svcTime;
}custStatus;
//simulation statistics
typedef struct{
	int numCust;
	int totSvcTime;
	int totWaitTime;
	int maxQueueSize;
}simStats;
// data of node
typedef struct Data{
	int custNum;
	int arriveTime;
}custData;

void newCustomer(QUEUE* queue, int clock, int* custNum);
void serverFree(QUEUE* queue, int clock, custStatus* status, bool* moreCusts);
void svcComplete(QUEUE* queue, int clock, custStatus* status, simStats* stats, bool* moreCusts);
void printStats(simStats* stats);

const int ENDTIME = 480;

int main(void){
	QUEUE* queue;
	custStatus custStatus={0,};
	simStats runStats={0,};
	int clock = 0;
	bool moreCusts = false;
	int custNum = 0;
	
	srand(time(NULL));
	queue = createQueue();
	
	while( clock <= ENDTIME || moreCusts){
		newCustomer(queue, clock, &custNum);
		serverFree(queue, clock, &custStatus, &moreCusts);
		svcComplete(queue, clock, &custStatus,
					&runStats, &moreCusts);
		if(!emptyQueue(queue))
			moreCusts = true;
		clock++;
	}
	printStats(&runStats);
	
	destroyQueue(queue);
	
	return 0;
}

void newCustomer(QUEUE* queue, int clock, int* custNum){
	custData* custDataPtr;
	int newCust;
	
	if(clock > ENDTIME) return;
	
	newCust = rand()%4 + 1;
	
	if(newCust==4){
		custDataPtr = (custData*) malloc(sizeof(custData));
		if(custDataPtr){
			(*custNum)++;
			custDataPtr->custNum = *custNum;
			custDataPtr->arriveTime = clock;
			enqueue(queue, (void*)custDataPtr);
		}
	}
}

void serverFree(QUEUE* queue, int clock, custStatus* status, bool* moreCusts){
	custData* custDataPtr;
	
	if(clock > status->startTime + status->svcTime -1){
		if(!emptyQueue(queue)){
			dequeue(queue, (void*) &custDataPtr);
			status->custNum = custDataPtr->custNum;
			status->arriveTime = custDataPtr->arriveTime;
			status->startTime = clock;
			status->svcTime = rand()%10 + 1;
			*moreCusts = true;
			free(custDataPtr);
		}
	}
}

void svcComplete(QUEUE* queue, int clock, custStatus* status,
					simStats* stats, bool* moreCusts){
	int waitTime=0;
	int queueSize=0;
	
	if(clock == status->startTime + status->svcTime -1){
		waitTime = status->startTime - status->arriveTime;
		(stats->numCust)++;
		stats->totSvcTime = stats->totSvcTime + status->svcTime;
		stats->totWaitTime = stats->totWaitTime + waitTime;
		queueSize = queueCount(queue);
		if((stats->maxQueueSize) < queueSize)
			(stats->maxQueueSize) = queueSize;
		printf("#%3d :  [arrTime%4d] [strtTime%4d] [svcTime%4d] [waitTime%4d] [qCnt%3d]\n",
				status->custNum, status->arriveTime, status->startTime,
				status->svcTime, waitTime, queueCount(queue));
		*moreCusts = false;
	}
}

void printStats(simStats* stats){
	double avrgSvcTime=0;
	double avrgWaitTime=0;

	printf("\n\nSimulation Statistics:");
	printf("\nTotal customers: %d", stats->numCust);
	printf("\nTotal service time: %d", stats->totSvcTime);
	avrgSvcTime = (stats->totSvcTime) / (double) (stats->numCust);
	printf("\nAverage servic time: %.3lf", avrgSvcTime);
	avrgWaitTime = (stats->totWaitTime) / (double) (stats->numCust);
	printf("\nAverage wati time: %.3lf", avrgWaitTime);
	printf("\nMaximum queue size: %d\n\n", stats->maxQueueSize);
}


