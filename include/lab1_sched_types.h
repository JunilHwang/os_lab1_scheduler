/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id : 32131766, 32151839, 32161756
*	    Student name : 황준일, 박은영, 박유림
*
*   lab1_sched_types.h :
*       - lab1 header file.
*       - must contains scueduler algorithm function's declations.
*
*/

#ifndef _LAB1_HEADER_H
#define _LAB1_HEADER_H
#define SIZE 5	// process size

// struct task
struct task_t{
	char name;	// process name
	int arv,	// Arrival time
		svc;	// Service time
};

// global variable
struct task_t *queue[SIZE],	// queue
			   task[SIZE];	// task
int qt, ql;  //queue top, last position

// default functions
struct task_t *q_pop();	// queue pop
void q_put(struct task_t *);	// queue put
void q_check();
void taskSet();	// task setting
void startLog(char *);
void endLog(char *);
void endl();
void print_queue();

// scheduling functions
void fifo();	// first in first out
void sjf();		// shortest job first
void rr(int);		// round robine
void mlfq();	// Multi level feedback queue
void lottery();	// lottery


#endif /* LAB1_HEADER_H*/



