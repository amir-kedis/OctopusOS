#pragma once
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "list.h"
#include "minHeap.h"
#include "queue.h"
#include "structs.h"

scheduler_type getScParams(char *argv[], int *quantem);
int getProcess(int *processesFlag, int gen_msgQID, process_t *process);
void freeProcessEntry(void *processEntry);
process_t *createProcess(process_t *process);
void cleanUpScheduler();
void clearSchResources(int signum);

//===============================
// Initializing stat variables
//===============================

void initPerformanceStats();

//===============================
// Scheduling Algorithms
//===============================
void schedule(scheduler_type schType, int quantem, int gen_msgQID);
void freeQueueData(void *data);
int compareHPF(void *e1, void *e2);
int compareSRTN(void *e1, void *e2);
int HPFScheduling(void **readyQueue, process_t *process, int *rQuantem);
int SRTNScheduling(void **readyQueue, process_t *process, int *rQuantem);
int RRScheduling(void **readyQueue, process_t *process, int *rQuantem);
void contextSwitch(process_t *newProcess);

//===============================
// IPC Functions
//===============================
int getRemTime(process_t *p);
void setRemTime(process_t *p, int val);
void sigUsr1Handler(int signum);

//===============================
// Preempting Functions
//===============================
// TODO: Handle in preempting functions restoring the process state and update
// stats
// TODO: make sure that we want to update by the index if not make a version
// with pid
void startProcess(process_t *process);
void preemptProcess(process_t *process);
void resumeProcess(process_t *process);

//==============================
// Logging Functions
//==============================

void createLogFile();
void logger(char *action, process_t *process_pcb);
void writePerfFile();

#endif
