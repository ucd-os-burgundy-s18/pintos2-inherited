#ifndef DEVICES_TIMER_H
#define DEVICES_TIMER_H

#include <round.h>
#include <stdint.h>
#include <list.h>
/* Number of timer interrupts per second. */
#define TIMER_FREQ 100
#define TIMER_PRI_RECALC_FREQ 4

struct sleeping_thread
  {
    struct semaphore* sema;
    int64_t wake_time;
    struct list_elem elem;
    const char* name;//used for debug pourpuses
    int priority;
  };

void timer_init (void);
void timer_calibrate (void);

int64_t timer_ticks (void);
int64_t timer_elapsed (int64_t);

/* Sleep and yield the CPU to other threads. */
bool sleeping_thread_compare(struct list_elem *t, struct list_elem *u, void *aux);
void timer_sleep (int64_t ticks);
void timer_msleep (int64_t milliseconds);
void timer_usleep (int64_t microseconds);
void timer_nsleep (int64_t nanoseconds);

/* Busy waits. */
void timer_mdelay (int64_t milliseconds);
void timer_udelay (int64_t microseconds);
void timer_ndelay (int64_t nanoseconds);

void timer_print_stats (void);

#endif /* devices/timer.h */
