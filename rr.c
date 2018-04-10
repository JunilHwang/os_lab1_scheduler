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
	char tn[] = "Round Robine";
	int i = 0,
		kill_count = 0,
		svc_t = 0,
		next = 0,
		sched_cnt = 0;
	struct task_t *now = NULL;
	startLog(tn);
	

	while(kill_count < 5){
		if(now != NULL){
			printf("%c%d ",now->name,now->svc);
			now->svc -= 1;
			if(now->svc < 0){
				q_pop(); kill_count++;
			}
			
			sched_cnt++;
			if(sched_cnt >= max_sched_cnt){
				//printf("qt : %d, ql : %d\t",qt,ql);
				q_put(now);
				now = q_pop();
				//printf("qt : %d, ql : %d\n",qt,ql);
				sched_cnt = 0;
			}
		}
		//print_queue();
		//printf("%d ",svc_t);
		if(task[next].arv <= svc_t){
			now = &task[next];
			q_put(now);
			next++;
			//printf("%c ",now->name);
		}
		svc_t++;
	}
	printf("\n");

	endLog(tn);
}
