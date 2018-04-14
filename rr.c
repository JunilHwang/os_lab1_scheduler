/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id : 32131766
*	    Student name : junil hwang
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
	taskSet();
	char tn[30] = "Round Robin \0",
		 max[1],
		 in[20];
	int i = 0,
		kill_count = 0,
		svc_t = 0,
		next = 0,
		sched_cnt = 0;
	struct task_t *now = &task[next++];
	sprintf(max,"%d",max_sched_cnt);
	strcat(tn,max);
	startLog(tn);
	printf("   ");
	while(kill_count < SIZE){

		printf("%c ",now->name);
		in[svc_t] = now->name;
		if(now && now->rst == -1) now->rst = svc_t - now->arv;
		svc_t++;

		if(next<SIZE && task[next].arv <= svc_t){
			q_put(&task[next++]);
		}
		if(--now->svc <= 0){
			kill_count++;
			now->tat = svc_t - now->arv;
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
	endl();
	print_table(in);
	print_performance();
	endLog(tn);
}
