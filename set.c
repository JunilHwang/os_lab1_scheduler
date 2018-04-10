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
char taskName[] = "taskSet";
void startLog(char *name){
	printf("start \t %s \t ---------- \n",name);
}

void endLog(char *name){
	printf("end \t %s \t ---------- \n",name);
}

void taskSet(){
	//start log print
	startLog(taskName);

	char name[] = "abcde";
	int arv[] = {2,4,6,8,10},
		svc[] = {3,6,4,5,2},
		i;
	
	for(i=0;i<5;i++){
		task[i].name = name[i];
		task[i].arv = arv[i];
		task[i].svc = svc[i];
		printf("name : %c, arrival Time : %d, service Time : %d\n",
				task[i].name,
				task[i].arv,
				task[i].svc);
	}

	//end log print
	endLog(taskName);
}


