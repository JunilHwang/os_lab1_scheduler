/*
*	DKU Operating System Lab
*		Lab1 (Scheduler Algorithm Simulator)
*		Student id : 32131766
*		Student name : junil hwang
*
*   rr.c : implemen source of round robin
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

void rr(int max_sched_cnt){
	taskSet();  // task initialize
	char tn[30] = "Round Robin \0",	// task name
		  max[1],	// for round robin scheduling conut number
		  in[20];	// string for scheduling result print 
	int kill_count = 0,	// task killed count
		svc_t = 0,	// service time
		next = 0,		// next task index
		sched_cnt = 0; // schedule count
	struct task_t *now = &task[next++]; // now task
	sprintf(max,"%d",max_sched_cnt);
	strcat(tn,max);
	startLog(tn);
	printf("   ");
	while(kill_count < SIZE){
		printf("%c ",now->name);
		in[svc_t] = now->name;
		if(now && now->rst == -1) // response time check
			now->rst = svc_t - now->arv;
		svc_t++;

		while(next<SIZE && task[next].arv == svc_t){
			q_put(&task[next++]);		// put next task
		}
		if(--now->svc <= 0){
			kill_count++; // kill task
			now->tat = svc_t - now->arv; // turnaround time check
			sched_cnt = 0; // initialize scheduling time
			now = q_pop();
		} else {
			if(++sched_cnt >= max_sched_cnt){
				sched_cnt = 0; // initialize scheduling time
				q_put(now);
				now = q_pop();
			}
		}
	}
	endl();
	print_table(in);	// print scheduling result table
	print_performance(); // print scheduling performance
	endLog(tn);
}
