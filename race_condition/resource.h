#ifndef RACE_CONDITION_H
#define RACE_CONDITION_H
#define THREADS 4

extern pthread_mutex_t mutex;
extern sem_t sem;
extern long global;

void *mutex_example(void *arg);
void *semaphore_example(void *arg);

#endif