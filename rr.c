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

void rr(int max_sched_cnt){
	taskSet();
	char tn[] = "Round Robine\0";
	int i = 0,
		kill_count = 0,
		svc_t = 0,
		next = 0,
		sched_cnt = 0;
	struct task_t *now = &task[next++];
	startLog(tn);
	while(kill_count < SIZE){
		svc_t++;

		if(next<SIZE && task[next].arv <= svc_t){
			q_put(&task[next++]);
		}

		printf("%c ",now->name);
		if(--now->svc <= 0){
			kill_count++;
			sched_cnt = 0;
			now = q_pop();
		} else {
			if(++sched_cnt >= max_sched_cnt){
				sched_cnt = 0;
				q_put(now);
				now = q_pop();
			}
		}
	}
	printf("\n");

	endLog(tn);
}
