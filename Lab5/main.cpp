#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono> 
#include "algo.h"
using namespace std;
using namespace std::chrono;

inline int make_even(int n);

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);

	//filling the array with what each process wants and currently has
	//first: want; second: currently have    
    pair<int,int> process[n];
    srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++){
        	int rand_int = 1+(rand()%100);
        	process[n].first = rand_int;
        	process[n].second = 1+(rand()%rand_int);
//        	cout << "(" << process[n].first << ", " << process[n].second << ")"<<endl;    
    } 
	
	int resources = 1+ (rand()%500);
//	cout << "Resources: " << resources <<endl;
	high_resolution_clock::time_point t1= high_resolution_clock::now();
	bool b = Banker(process, n, resources);
 	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>( t2 - t1 ).count();

	
	high_resolution_clock::time_point t3= high_resolution_clock::now();
	bool h = Haphazard(process, n, resources);
	high_resolution_clock::time_point t4 = high_resolution_clock::now();
	 auto duration2 = duration_cast<microseconds>( t4 - t3 ).count();

	if(b){
		cout<<"Banker's: " << (static_cast<double>(n)/duration1)*100 << endl;
		
	}
	if(h){
		cout<< "Random: " << (static_cast<double>(n)/duration2*100) << endl;
	}
	return 0;
}
inline int make_even(int n)
{
    return n - n % 2;
}

