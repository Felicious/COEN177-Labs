#ifndef ALGO_H
#define ALGO_H
#include <iostream>
#include <ctime>
using namespace std;

int mini(int need[], int n){
        int min = need[0];
        int index = 0;
        for(int i =1; i < n; i++){
                if(need[i] < min){
                        min = need[i];
                        index = i;
                }
        }
        return index;

}

bool Banker(pair<int,int> process[], int n, int resources){
    int need[n];
	int count = n-1;
	for(int i =0; i < n; i++)
		need[i] = process[n].first - process[n].second;
	while((resources >=0)&&(count >0)){
		int index = mini(need,n);
		resources -= need[index];
		if(resources <= 0){
			break;
		}
		need[index] = 200;
		resources+=process[index].first;
		count--;
	}
	if((resources <= 0) || (count != 0)){
		cout<< "Deadlock: unable to allocate all resources." << endl;
		return false;
	}
	else if((resources > 0) || (count = 0)){
		cout<< "Successfully allocated resources!" << endl;
 		return true;
	}else{
        	cout<< "I've reached the end and idk what to do" <<endl;
	}
}

bool Haphazard(pair<int,int>process[], int n, int resources){
	int count = n-1;
	int need[n];
        for(int i =0; i < n; i++){
                need[i] = process[n].first - process[n].second;
	}
	srand(time(NULL));
	while((resources > 0)&&(count >0)){
		resources -= need[count];
		if(resources < 0){
			break;
		}
		else{
			resources+=process[count].first;
			count--;
		}
	}
	if((resources < 0)||(count > 0)){
	cout<<"deadlock: unable to allocate all resources." << endl;
                return false;
        }
        else if((resources >= 0) || (count = 0)){
                cout<< "Successfully allocated resources!" << endl;
                return true;
	}else{
        	cout<< "I've reached the end and idk what to do" <<endl;
	}
}       
#endif
