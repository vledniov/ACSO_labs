Laboratory work 5&6
=========

Goal
-
  - have a simple multitasking implemented
  - your OS multitasking should have the following functions available:
Reaching the goal
  
    - `void sched_add_task(void* func_ptr)` – add a task to scheduler by giving a function pointer
    - `void yield(void)` – give control to scheduler in a task
    - `void sched_run(void)` – start the scheduler

Reaching the goal
-

*setjmp.h*


  - I created anothet file in **/lib** directory called **setjmp.h**, where I copied the structure I user in LaboratoryWork4

The structure

    typedef struct
        {
        unsigned edi, esi, ebp, esp, ebx, edx, ecx, eax;
        unsigned eip, eflags;
        } jmp_buf[1];
        
plus declared 2 functions we are going to use 

    int setjmp(jmp_buf b);
    void longjmp(jmp_buf b, int ret_val);
    
*kmain.c*
  
- First we import **setjmp.h**, and **longjmp.c** 

        #include "lib/setjmp.h"
        #include "lib/longjmp.c"
- Right after this we define a variable called `TASK_STACK_SIZE` to be the `512`.
- Also we had to add 2 different structures in our file.
    
        typedef enum {
        TS_RUNNABLE = 1, TS_BLOCKED = 2, TS_ZOMBIE = 3
        } task_status_t;
 
        typedef struct {
            jmp_buf       state;
            task_status_t status;
            unsigned char stack[TASK_STACK_SIZE];
        } task_t;

- Plus some global variables.
        
            task_t _sched_tasks[3];  // Tasks array
            int task_added = 0;      // number of tasks we added
            int _sched_num_tasks = 0;// current working task

-  First function to add was the `wait(void)` one. We need this function to make a "sleep" period between our tasks, so that we can see how they're switching between them.

            void wait (void) {
               int i=0;
               while ( i<99999999)
               {
                i++;
               };
            }

- Next 2 functions are our tasks. They switch the letters on the screen between A/B.

        void task0 (void) {
          while (1) {
            yield();
            vidmem[0] = vidmem[0] == 'B' ? 'A' : 'B';
            wait();
          }
        }
            
        void task1 (void) {
        
          while (1) {
            yield();
            vidmem[2] = vidmem[2] == 'B' ? 'A' : 'B';
            wait();
          }
        }
        
    
-  `void sched_add_task(void* func_ptr)` is the function that adds our task to the scheduler by giving a function pointer

        void sched_add_task(void* func_ptr){
        
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

  -  `void yield(void)` switches from a task to a task. At the moment just switches between task1/task0

            void yield(void){
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
            
  - `void sched_run(void)` - after all is set, comes this function which starts the process.

            void sched_run(void){
                longjmp(_sched_tasks[0].state,0); 
            }

  - And the `main(void)` funtion to check how multitasking is working, and if it is really working.

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



