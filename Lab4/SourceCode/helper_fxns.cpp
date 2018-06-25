#include "helper_fxns.h"

//helper function for LRU to find the index of the page that will be thrown out
int min(int LRU_cache[], int Tablesize){
	int mem_index = 0; // mem_index that'sto be returned
	int min = LRU_cache[0];
	for(int i = 1; i < Tablesize; i++){
		if(LRU_cache[i] < min){
			min = LRU_cache[i];
			mem_index = i;
		}
	}
	return mem_index;
	
}



