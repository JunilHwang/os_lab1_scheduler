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
    int now, prev;           // for now and previous index
    struct task_t *temp;    // for now and previous exchange
    now = ql == 0 ? SIZE-1 : ql-1; // queue index last put
    while(1){
        prev = now == 0 ? SIZE-1 : now-1;   // previous index
        if(!queue[prev] || queue[prev]->svc < queue[now]->svc) break;   // sorted complete
        if(queue[prev]->svc >  queue[now]->svc ||   // sorted
            (queue[prev]->svc == queue[now]->svc && queue[prev]->name > queue[now]->name)){
            temp = queue[now];
            queue[now] = queue[prev];
            queue[prev] = temp;
        }
        now = prev;
    }
}

// SJF(Shortest Job First) Scheduling
void sjf(){
    taskSet();  // task initialize
    char tn[] = "Shortest job first\0", // function name
         in[20];    // for scheduling result print
    int	killed_count = 0, // killed task count
		svc_t = 0,         // for service time increase
		next = 0;          // next 
    struct task_t *now= &task[next++];  // now task
    startLog(tn);
    printf("  ");
	while(killed_count < SIZE){
        // service time same next task arrival time
        // than put next task
        // than sort by service time
        while(next<SIZE && task[next].arv == svc_t){
            q_put(&task[next]);
            sortByServicetime();
            next++;
        }
        printf("%c ",now->name);    // print now task
        in[svc_t] = now->name;
        if(now && now->rst == -1)   // response time check
            now->rst = svc_t - now->arv;
        svc_t++;    // service time increment
        if(--now->svc == 0){
            killed_count++; // kill task
            now->tat = svc_t - now->arv; // turnarround time check
            now = q_pop();  // next task pop
        }
    }
    endl();
    print_table(in);    // print scheduling result table
    print_performance(); // print scheduling  performance
    endLog(tn);
}
