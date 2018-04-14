/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*
*   set.c : implement of default function 
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

// start log print
void startLog(char *name){
	printf("\nstart \t %s\n",name);
	printf("------------------------------ \n");
}

// end log print
void endLog(char *name){
	printf("------------------------------ \n");
	printf("end \t %s\n\n",name);
}

// enter
void endl(){
	printf("\n");
}

// queue pop
struct task_t *q_pop(){
	struct task_t *task_top = queue[qt];
	queue[qt] = NULL;
	if(++qt >= SIZE) qt = 0;
	return task_top;
}

// queue put
void q_put(struct task_t* task_one){
	queue[ql] = task_one;
	if(++ql >= SIZE) ql = 0;
}

// print queue
void print_queue(){
	int i=0;
    endl();
	for(;i<SIZE;i++){
		if(queue[i] == NULL) continue;
		printf("i:%d,name:%c,svc:%d,prt:%d\n",i,queue[i]->name,queue[i]->svc,queue[i]->prt);
	}
	printf("top:%d, last:%d\n",qt,ql);
	endl();
}

// task array setting
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
		task[i].tat = -1; 
		task[i].rst = -1;
		task[i].tk  = svc[i]*100;
	}

}

// task array print
void taskPrint(){
	int i;
	for(i=0;i<SIZE;i++){
		printf("name : %c, arrival Time : %d, service Time : %d, priority : %d\n",task[i].name,task[i].arv,task[i].svc,task[i].prt);
	}
}


// scheduling table print
void print_table(char arr[]){
	int i=0,j,asize=0;
	for(;i<SIZE;i++){
		printf("%c ",task[i].name);
		for(j=0;j<20;j++){
			if(task[i].name == arr[j]){
				printf("■ ");
			} else {
				printf("□ ");
			}
		}
		endl();
	}
}

// print average value
void print_performance(){
	int sum_tat=0, sum_rst=0,
		i=0;
	float avg_tat, avg_rst;
	for(;i<SIZE;i++){
		sum_tat += task[i].tat;
		sum_rst += task[i].rst;
		printf("[%c] ",task[i].name);
		printf("turnaround %2d  ",task[i].tat);
		printf("response %2d\n",task[i].rst);
	}
	avg_tat = (float)sum_tat/SIZE;
	avg_rst = (float)sum_rst/SIZE;
	printf("[turnaround] ");
	printf("sum %2d, avg %.2f\n",sum_tat,avg_tat);
	printf("[reponse]    ");
	printf("sum %2d, avg %.2f\n",sum_rst,avg_rst);
}
