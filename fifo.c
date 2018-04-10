/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id : 
*	    Student name : 
*
*   lab1_sched.c :
*       - Lab1 source file.
*       - Must contains scueduler algorithm function'definition.
*
*/

#include <aio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <pthread.h>
#include <asm/unistd.h>

#include "lab1_sched_types.h"

/*
 * you need to implement FCFS, RR, SPN, SRT, HRRN, MLFQ scheduler. 
 */
/*
void rr(int test){
	printf("%d\n",test);
}
*/

void fifo(){
	char tn[] = "First in First out;
	int i = 0,
		killed_count = 0,
		svc_t = 0,
		next = 0;
	struct task_t *now = &task[next++];
	startLog(tn);
	while(killed_count < SIZE){
		svc_t++;
		if(next<SIZE && task[next].arv <= svc_t){
			q_put(&task[next++]);
		}
		printf("%c%d ",now->name,now->svc);
		if(--now->svc <= 0){
			now = q_pop();
		}
	}

	printf("\n");

	endLog(tn);
}
