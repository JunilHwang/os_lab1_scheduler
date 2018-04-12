/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id : 32131766
*	    Student name : junil hwang
*
*   mlfq.c : implement Source of Multi Level Feedback Queue
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
void mlfq(){
	taskSet();
	char tn[] = "Multi Level Feedback Queue\0";
	int i = 0,
		kill_count = 0,
		svc_t = 0,
		next = 0;
	struct task_t *now = &task[next++];
	startLog(tn);
	q_put(now);
	while(kill_count < SIZE){
		if(next<SIZE && task[next].arv <= svc_t){
			now = &task[next++];
		} else {
			now = q_pop();
		}
		svc_t++;
		now->prt++;
		printf("%c ",now->name);
		if(--now->svc <= 0){
			kill_count++;
		} else {
			q_put(now);
		}
	}
	endl();
	endLog(tn);
}

