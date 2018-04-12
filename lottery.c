/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id : 32131766
*	    Student name : junil hwang
*
*   lottery.c : implement source of lottery scheduling
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

void lottery(){
	char tn[] = "Lottery\0";
	int i = 0,
		kill_count = 0,
		arv_cnt=1,
		svc_t=0,
		max, stack_tk, win_number;
	taskSet();
	startLog(tn);
	srandom(time(NULL));
	max = task[i].tk;
	while(kill_count < SIZE){
		svc_t++;
		win_number = random() % max;
		//printf("\nmax:%d,win:%d,",max,win_number);
		for(i=stack_tk=0;i<arv_cnt;i++){
			if(task[i].svc>0) stack_tk += task[i].tk;
			if(win_number < stack_tk){
				if(task[i].svc == 0) continue;
				printf("%c ",task[i].name);
				if(--task[i].svc<=0){
					kill_count++;
					max -= task[i].tk;
				}
				break;
			}
		}
		for(i=arv_cnt;i<SIZE;i++){
			if(task[i].arv <= svc_t){
				max += task[i].tk;
				arv_cnt++;
			}
		}

	}
	endl();
	endLog(tn);

}
