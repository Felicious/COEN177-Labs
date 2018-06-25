#include "helper_fxns.h"

int min(int LRU_cache[], int Tablesize){
        int index = 0;
        int min_val= LRU_cache[0];
        for (int i = 1; i < Tablesize; i++){
                if(LRU_cache[i] < min_val){
                        index = i;
                        min_val = LRU_cache[i];
                }
        }
        return index;
}

