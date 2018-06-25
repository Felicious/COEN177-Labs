#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "init_read.h"
#include "helper_fxns.h"


//when implementing the algorithm, can make the page algo return the page, i, so you can find the page index easier
//if so, have to change the if statement inside main more.
struct special_page
{
        int page_value;
        int ref;
};
int isInMemory2(int pageRequest, struct special_page pagetable[], int tableSize){
        int i;
        for (i=0; i < tableSize; i++){
                if(pageRequest == pagetable[i].page_value){
                        return i;
                }
        }
        return -1;
}


int main (int argc, char *argv[]){
	//call function parseTableSize to obtain table size from command line input
	int Tablesize = parseTableSize(argc, argv);
	
	// variables to hold our pages on standard in
	int pageRequest= 0;
	int pageTableIndex= 0;
	int numRequest =0; 
	int numMisses = 0;

	// number of page requests - num of misses (page faults) = number of hits
	// hit rate : number of hits/number of requests
	//int  *pageTable = (int *) malloc(sizeof(int)*Tablesize); //every call to malloc must free
	
	struct special_page pageTable[Tablesize];
	
	char *input = NULL; 

	size_t inputAllocated = 0;
	size_t bytesRead;
	//main loop
	while((bytesRead = getline(&input, &inputAllocated, stdin)) != -1){
		pageRequest = atoi(input);
		if(pageRequest == 0){
			continue;
		}
		numRequest++;
	  	//printf("Page Request at this point = %d\n", numRequest);	
		//isInMemory returns the index of page that is the same value as the pageRequest
		int in_memory = isInMemory2(pageRequest, pageTable, Tablesize);
		if(in_memory == -1){ //page is not in memory
		//	printf("Page %d caused a page fault.\n", pageRequest);
			numMisses++;
			if(pageTableIndex < Tablesize){
				pageTable[pageTableIndex].page_value = pageRequest;
				pageTable[pageTableIndex++].ref = 0; //set referenced bit of the new page to 0
			}else{
		//		fprintf(stderr, "Ran out of memory. Implement a page replacement algo!\n");
				
				//set reference bit to 0 when encounter ref = 1
				while(pageTable[pageTableIndex%Tablesize].ref == 1){
					pageTable[pageTableIndex%Tablesize].ref = 0; 
					pageTableIndex++;
				}
				pageTable[pageTableIndex%Tablesize].page_value = pageRequest;
				pageTable[pageTableIndex%Tablesize].ref = 0;
				pageTableIndex++;
			}
		}else{ //is in memory
			pageTable[in_memory].ref = 1;
		}
	} 
	//printf("Page Request = %d\n", numRequest);
	//printf("Number of Misses = %d\n", numMisses);
	printf("Hit rate = %f\n", (numRequest-numMisses)/(double)numRequest);

	free(input);
	//free(pageTable); 
	return 0;
}
