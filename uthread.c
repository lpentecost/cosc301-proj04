#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"
#include "x86.h"
#include "param.h"
#include "mmu.h"

/*
 * This is where you'll need to implement the user-level functions
 */
#define NPROC       64
uint stacks[NPROC]; //use array of size NPROC to assign stack for each thread

void lock_init(lock_t *lock) {
    lock -> locked = 0;
}

void lock_acquire(lock_t *lock) {
    while ((xchg(&lock->locked, 1)) != 0);
}

void lock_release(lock_t *lock) {
    xchg(&lock -> locked, 0);
}

int thread_join(int pid) {
    int retval = join(pid);
    if (retval > 0 && retval < NPROC){
        free((void *)stacks[retval-1]);
    }
    return retval;
}

int thread_create(void (*start_routine)(void *), void *arg) {
    void *stack = malloc(PGSIZE);
    if((uint)stack % PGSIZE) //page alignment, taken from clonetest
        stack = stack + (PGSIZE - (uint)stack % PGSIZE);
    int retval = clone(start_routine, arg, stack);
    if (retval > 0 && retval <NPROC){
        stacks[retval-1] = (uint)stack;
    }
    return retval;
}
