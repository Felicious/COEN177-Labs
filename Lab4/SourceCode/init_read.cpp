#include "init_read.h"

int parseTableSize(int argc, char *argv[]){
        int TableSize;
        if(argc == 2 && (TableSize = atoi(argv[1]))){
                return TableSize;
        }
        fprintf(stderr, "Wrong arguments, Pass tableSize as argument!\n");
        exit(-1);
}

int isInMemory(int pageRequest, int *pagetable, int tableSize){
        int i;
        for (i=0; i < tableSize; i++){
                if(pageRequest == pagetable[i]){
                        return i;
                }
        }
        return -1;
}


