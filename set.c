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
void startLog(char *name){
	printf("\nstart \t %s \t ---------- \n",name);
}

void endLog(char *name){
	printf("end \t %s \t ---------- \n\n",name);
}

void endl(){
	printf("\n");
}

void q_check(){
	//if(qt == ql)
	//	qt = ql = 0;
}

struct task_t *q_pop(){
	struct task_t *task_top = queue[qt];
	queue[qt] = NULL;
	if(++qt >= SIZE) qt = 0;
	q_check();
	return task_top;
}

void q_put(struct task_t* task_one){
	int now=ql, prev;
	struct task_t* temp;
	queue[ql] = task_one;

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
	if(++ql >= SIZE) ql = 0;
	q_check();
}

void print_queue(){
	int i=0;
	for(;i<SIZE;i++){
		if(queue[i] == NULL) continue;
		printf("i:%d,name:%c,svc:%d\n",i,queue[i]->name,queue[i]->svc);
	}
	printf("top:%d, last:%d\n",qt,ql);
	endl();
}

void taskSet(){

	char name[] = "abcde\0";
	int arv[] = {0,2,4,6,8},
		svc[] = {3,6,4,5,2},
		i;
	qt = ql = 0;
	for(i=0;i<SIZE;i++){
		queue[i] = NULL;
		task[i].name = name[i];
		task[i].arv = arv[i];
		task[i].svc = svc[i];
		task[i].prt = 0;
		printf("name : %c, arrival Time : %d, service Time : %d, priority : %d\n",
				task[i].name,
				task[i].arv,
				task[i].svc,
				task[i].prt);
	}

}

