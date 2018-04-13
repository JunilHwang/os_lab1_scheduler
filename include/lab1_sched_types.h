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
#define SIZE 5		// process size

// struct of task
struct task_t{
	char name;	// process name
	int tat,	// turnarround time
		rst,	// response time
		arv,	// Arrival time
		svc,	// Service time
		prt,	// Priority
		tk;		// ticket
};

/* global variable { */
struct task_t	*queue[SIZE],	// queue
				task[SIZE];		// task
int qt,		// queue top index
	ql;		// queue last index
/* } global variable */

/* default functions {
	 will be implement in set.c */
struct task_t *q_pop();			// queue pop
void q_put(struct task_t *);	// queue put
void taskSet();					// task array setting
void taskPrint();				// task array  print
void startLog(char *);			// start log print
void endLog(char *);			// end log print
void endl();					// enter character
void print_queue();				// queue print
void print_table(char *);		// shceduling table print
void print_performance();		// print scheduling performance
/* } default functions */

/* scheduling functions { */
void fifo();	// implement at fifo.c	first in first out
void sjf();		// implement at sjf.c	shortest job first
void rr(int);	// implement at rr.c	round robine
void mlfq();	// implement at mlfq.c	Multi level feedback queue
void lottery();	// implement at lottery.c
/* } scheduling functions */


#endif /* LAB1_HEADER_H*/



