typedef unsigned int   uint;
typedef unsigned short ushort;
typedef unsigned char  uchar;
typedef uint pde_t;
typedef struct lock_t{
    uint locked; //flag

    //char *name; //name of lock
    //struct cpu *cpu; //cpu holding lock
    //uint pcs[10]; //call stack that called lock

}lock_t;
