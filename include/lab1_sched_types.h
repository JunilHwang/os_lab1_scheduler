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

struct task_t{
	char name;	// process name
	int arv,	// Arrival time
		svc;	// Sergice time
};
int queue[5];	// queue
void q_pop();	// queue pop
void q_put();	// queue put
struct task_t task[5];	// task info
void taskSet();	// task setting
void startLog(char *);
void endLog(char *);

void fifo();	// first in first out
void sjf();		// shortest job first
void rr();		// round robine
void mlfq();	// Multi level feedback queue
void lottery();	// lottery


#endif /* LAB1_HEADER_H*/



