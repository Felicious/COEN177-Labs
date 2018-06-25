#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

//please refer to README3.txt for more information :)
int main(){
	for(int i = 0; i < 6; ++i){
		if(fork() == 0) //creates six child processes, each the parent of the next
			printf("parentPid = %d, myID = %d\n", getppid(), getpid()); //processes #1-6
		else{ //parent process
			int status;
			waitpid(-1, &status, 0);
			//waits for the above six children to execute
			//once control is given back to the parent process, each of the parent processes of #1-5 each make a child
				if(fork() == 0)
					//even the origin creates one more child, as it is also a parent process
					printf("parentPid = %d, myID = %d\n", getppid(), getpid()); //process #7-12
				else{
					waitpid(-1, &status, 0);
					break; //exits and relinquishes control to its parent, who creates one more child
				}
			break;	
		}
	}
	return 0;	
}
