/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id : 32151839
*	    Student name : Eunyoung Park
*
*   fifo.c : implement of first in first out 
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

void fifo(){
	taskSet();		// task variable initialize
	taskPrint();		// task status print
	char tn[] = "First in First out\0",	// task name
		 in[20];		// for scheduling print
	int killed_count = 0,		// killed task count
		svc_t = 0,			// for service time increase
		next = 0;			// next task index
	struct task_t *now= &task[next++];	 // now task
	startLog(tn);
	printf("   ");
	while(killed_count < SIZE){
		// arrival time same service time than next task put queue
		while(next<SIZE && task[next].arv == svc_t){
			q_put(&task[next]);
			next++;
		}
		printf("%c ",now->name);	// now process name print
		in[svc_t] = now->name;	// store present process name put for print table
		if(now && now->rst == -1)	// response time check
			now->rst = svc_t - now->arv;
		svc_t++;		// service time increament
		if(--now->svc <= 0){	// task kill and next task pop
			killed_count++;
			now->tat = svc_t - now->arv;
			now = q_pop();
		}
	}
	endl();
	print_table(in);		// print task scheduling table
	print_performance();	// print scheduling performance ( turnaround time, response time )
	endLog(tn);
}
