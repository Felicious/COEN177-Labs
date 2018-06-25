#include <stdio.h>
#include <stdlib.h>

#ifndef INIT_READ_H
#define INIT_READ_H

int parseTableSize(int argc, char *argv[]);

int isInMemory(int pageRequest, int *pagetable, int tableSize);

#endif

