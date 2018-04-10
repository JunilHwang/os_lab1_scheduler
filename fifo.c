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
	char tn[] = "fifo";
	int allTurnaroundTime;
	int i,j;
	int t;
	struct task_t *ttask;
	startLog(tn);

	printf("fifo 관련 실행\n");

	taskSet();
	
	for(i=0;i<SIZE;i++){
		allTurnaroundTime+=task[i].svc;
	}
	printf("%d", allTurnaroundTime);
/*	for(t=0;t<allTurnaroundTime;t++)
	{
		printf("%d",t);
	for(i=0;i<SIZE;i++){
		if(task[i].arv==t)
		{
			t++;
			printf("%d",t);
			for(j=0;task[i].svc;j++){
			q_put(&task[i]);
			ttask=q_pop();
			printf("%c", ttask->name);
	
			}
		}
		
	}
	}
	print_queue();
*/
	endLog(tn);
}


