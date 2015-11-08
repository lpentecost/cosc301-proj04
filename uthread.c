#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"
#include "x86.h"

/*
 * This is where you'll need to implement the user-level functions
 */

void lock_init(lock_t *lock) {
    lock -> locked = 0;
    //lock -> cpu = 0;
}

void lock_acquire(lock_t *lock) {
    //check if already holding
    //if (lock->locked && lock->cpu == cpu){
       //panic("acquire");
    //}

    while ((xchg(&lock->locked, 1)) != 0);

    //lock -> cpu = cpu;
}

void lock_release(lock_t *lock) {
    //check that we are holding the lock
    //if (!(lock->locked && lock-> cpu == cpu)){
        //panic("release");
    //}
    //lock -> cpu = 0;
    xchg(&lock -> locked, 0);
}

int thread_join(int pid) {
    return -1;
}

int thread_create(void (*start_routine)(void *), void *arg) {
    return -1;
}
