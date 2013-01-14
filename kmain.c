#include "lib/video.c"
#include "lib/io.c"
#include "lib/kbd.c"
#include "lib/setjmp.h"
#include "lib/longjmp.c"


#define TASK_STACK_SIZE 512
void task0 (void);
void task1 (void);

typedef enum {
  TS_RUNNABLE = 1, TS_BLOCKED = 2, TS_ZOMBIE = 3
} task_status_t;
 
typedef struct {
    jmp_buf       state;
    task_status_t status;
    unsigned char stack[TASK_STACK_SIZE];
} task_t;

char* vidmem = (char *) 0xb8000;

int main( void )
{
  // putc('a');
  vidmem[1] = 0x7;
  // putc('1');
  vidmem[3] = 0x7;
  // putc('2');
  sched_add_task(task0);
  sched_add_task(task1);
  sched_run();
}

task_t _sched_tasks[1];
int task_added = 0;
int _sched_num_tasks = 0;

void wait (void) {
   int i=0;
   while ( i<100000)
   {
    i++;
   };  
}

void task0 (void)
{
  while (1) {
    yield();
    vidmem[0] = vidmem[0] == 'B' ? 'A' : 'B';
    wait();
  }
}

void task1 (void)
{
  while (1) {
    yield();
    vidmem[2] = vidmem[2] == 'B' ? 'A' : 'B';
    wait();
  }
}

void sched_add_task(void* func_ptr)
{
// Adding the task into array
  task_t *task = & _sched_tasks[task_added];
// Incrementing task_added for the future task
  task_added++;
  unsigned * initial_stack_ptr;
  initial_stack_ptr = (unsigned) task->stack + TASK_STACK_SIZE;
  // set stack pointer of the task context to initial_stack_ptr
  task->state[0].esp = initial_stack_ptr;
  // set instruction pointer of the task context to func_ptr
  task->state[0].eip=func_ptr;
  // set status of the task as runnable
  task->status=1;
  task->state[0].eflags = 0x200; //some magic for longjmp
}

// It switches between task0/task1
void yield(void)
{
     if (!setjmp(_sched_tasks[_sched_num_tasks].state)) {
        if (_sched_num_tasks != 0) {
            _sched_num_tasks = 0;
        }
        else {
            _sched_num_tasks = 1;
        }
        longjmp(_sched_tasks[_sched_num_tasks].state, 1);
    }
}


void sched_run(void)
{
 longjmp(_sched_tasks[0].state,0); 
}
