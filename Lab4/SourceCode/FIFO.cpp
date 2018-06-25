#include <stdio.h>
#include <stdlib.h>
#include "init_read.h"

// The following is my FIFO algorithm, even though it says it is main
int main (int argc, char *argv[]){
	//call function parseTableSize to obtain table size from command line input
	
	 int Tablesize = parseTableSize(argc, argv);

        // variables to hold our pages on standard in
        int pageRequest= 0;
        int pageTableIndex, numRequest, numMisses = 0;

        // number of page requests - num of misses (page faults) = number of hits
        // hit rate : number of hits/number of requests
	int *pageTable = (int *) malloc(sizeof(int)*Tablesize); //every call to malloc must free
        char *input = NULL;

        size_t inputAllocated = 0;
        ssize_t bytesRead;
        //main loop
	while((bytesRead = getline(&input, &inputAllocated, stdin)) != -1){
                pageRequest = atoi(input);
                if(pageRequest == 0){
                        continue;
                }
                numRequest++;
		//if requested page not in memory, call page fault
                if(isInMemory(pageRequest, pageTable, Tablesize)== -1){
                       // printf("Page %d caused a page fault \n", pageRequest);
                        numMisses++;
                        if(pageTableIndex < Tablesize){
				pageTable[pageTableIndex++]= pageRequest;
                	}else{
                        //	fprintf(stderr, "Ran out of memory. Implemented a FIFO page replacement algorithm :D\n");
                        	//would you increment misses when you have to do a page replacement algo?
				//Implement FIFO with circular index
				pageTable[pageTableIndex%Tablesize] = pageRequest;
                      		pageTableIndex++; 
                	}
		}
	}
	printf("Hit rate = %f\n", (numRequest-numMisses)/(double)numRequest);

        free(input);
        free(pageTable);
        return 0;
	}
