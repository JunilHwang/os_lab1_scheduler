/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id : 32161756
*	    Student name : Yurim Park
*
*   sjf.c : implement of shortest job first
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

// sort by service time of queue
void sortByServicetime(){
    int now_idx, prev_idx;
    struct task_t *temp;
    now_idx = ql-1;
    if(now_idx < 0) now_idx = SIZE-1;
    while(1){
        prev_idx = now_idx-1;
        if(prev_idx < 0) prev_idx = SIZE-1;
        if(!queue[prev_idx] || queue[prev_idx]->svc < queue[now_idx]->svc) break;
        if(queue[prev_idx]->svc > queue[now_idx]->svc || (queue[prev_idx]->svc == queue[now_idx]->svc && queue[prev_idx]->name > queue[now_idx]->name)){
            temp = queue[now_idx];
            queue[now_idx] = queue[prev_idx];
            queue[prev_idx] = temp;
        }
        now_idx = prev_idx;
    }
}

// SJF(Shortest Job First) Scheduling
void sjf(){
	taskSet();
	char tn[] = "Shortest job first\0",
         in[20];
	int	killed_count = 0,
		svc_t = 0,
		next = 0;
    int i,now_idx,prev_idx; //control variable
	struct task_t *now= &task[next++];
	startLog(tn);
    printf("  ");
	while(killed_count < SIZE){
        
		if(next<SIZE && task[next].arv <= svc_t){
            q_put(&task[next]);
            sortByServicetime();
            next++;
        }
        printf("%c ",now->name);
        in[svc_t] = now->name;
        if(now && now->rst == -1)
            now->rst = svc_t - now->arv;
        svc_t++;

        now->svc--;
		if(now->svc == 0){
			killed_count++;
			now->tat = svc_t - now->arv;
			now = q_pop();
		}
    }
    endl();
    print_table(in);
	print_performance();
	endLog(tn);
}
