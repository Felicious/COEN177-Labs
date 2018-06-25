#include <stdio.h> 
#include <stdlib.h>
#include "init_read.h"
#include "helper_fxns.h"

//This is the LRU algorithm
int recency_counter = 0;

int main (int argc, char *argv[]){
	//call function parseTableSize to obtain table size from command line input
	int Tablesize = parseTableSize(argc, argv);
	
	// variables to hold our pages on standard in
	int pageRequest = 0;
	int pageTableIndex, numRequest, numMisses = 0;

	// number of page requests - num of misses (page faults) = number of hits
	// hit rate : number of hits/number of requests
	int *pageTable = (int *) malloc(sizeof(int)*Tablesize); //every call to malloc must free
	int *LRU_cache = (int *) malloc(sizeof(int)*Tablesize); 
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
		//stores the index where the request was found 
		int memory_index = isInMemory(pageRequest, pageTable, Tablesize);
		if(memory_index == -1){
			//printf("Page %d caused a page fault \n", pageRequest);
			numMisses++;
			//not in memory when the table is not completely full
			if(pageTableIndex < Tablesize){
				pageTable[pageTableIndex]= pageRequest;
				//stores recency value of a page in the corresponding index of a parallel array
				LRU_cache[pageTableIndex++] = recency_counter;
			}else{
                                //fprintf(stderr, "Ran out of memory. Implemented a FIFO page replacement algorithm :D\n");
				//function min returns the index of the page with smallest recency value
				int i = min(LRU_cache, Tablesize);
				pageTable[i]= pageRequest;
				LRU_cache[i] = recency_counter;
			}
		}else{ //if page IS in memory
			LRU_cache[memory_index] = recency_counter;		
	
		}
		//this increments with every instruction
		recency_counter++;

	}	 

	printf("Hit rate = %f\n", (numRequest-numMisses)/(double)numRequest);
	
	
	free(input);
	free(pageTable);
	free(LRU_cache); 
	return 0;
}
