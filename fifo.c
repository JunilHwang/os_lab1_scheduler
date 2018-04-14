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

void fifo(){
	taskSet(); taskPrint();
	char tn[] = "First in First out\0",
		 in[20];
	int i = 0,
		killed_count = 0,
		svc_t = 0,
		next = 0;
	struct task_t *now= &task[next++];
	startLog(tn);
	printf("   ");
	while(killed_count < SIZE){
		if(next<SIZE && task[next].arv <= svc_t){
			q_put(&task[next]);
			next++;
		}
		printf("%c ",now->name);
		in[svc_t] = now->name;
		if(now && now->rst == -1)
			now->rst = svc_t - now->arv;
		svc_t++;
		if(--now->svc <= 0){
			killed_count++;
			now->tat = svc_t - now->arv;
			now = q_pop();
		}
	}
	endl();
	print_table(in);
	print_performance();
	endLog(tn);
}
