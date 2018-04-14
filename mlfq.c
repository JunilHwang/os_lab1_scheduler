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

// sort by priority
void sortByPrt(){
	int now = ql-1,prev;
	struct task_t *temp;
	if(now < 0) now = SIZE-1;

	// order by priority 
	while(1){
		prev = now-1;
		if(prev < 0) now = SIZE-1;
		if(!queue[prev] || queue[prev]->prt == queue[now]->prt || prev == qt) break;
		if(queue[prev]->prt > queue[now]->prt){
			temp = queue[now];
			queue[now] = queue[prev];
			queue[prev] = temp;
		}
		now = prev;
	}

}

// multi level feedback queue
void mlfq(){
	taskSet();
	char tn[] = "Multi Level Feedback Queue\0",
		 in[20];
	int i = 0,
		kill_count = 0,
		svc_t = 0,
		next = 0;
	struct task_t *now = &task[next++];
	startLog(tn);
	printf("  ");
	q_put(now);
	while(kill_count < SIZE){
		if(next<SIZE && task[next].arv <= svc_t){
			now = &task[next++];
		} else {
			now = q_pop();
		}
		printf("%c ",now->name);
		if(now && now->rst == -1) now->rst = svc_t - now->arv;
		in[svc_t++] = now->name;
		now->prt++;
		if(--now->svc <= 0){
			kill_count++;
			now->tat = svc_t - now->arv;
		} else {
			q_put(now);
			sortByPrt();
		}
	}
	endl();
	print_table(in);
	print_performance();
	endLog(tn);
}