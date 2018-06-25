#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	for(int i = 0; i < 8; ++i){
		if(fork() == 0){ //makes eight child process 
			printf("parentPid = %d, myId = %d\n" , getppid(), getpid());
		}else{ //parent doesn't do anything, just exits
			int status;
			waitpid(-1, &status,0); 
			break;
		}
	}
	return 0;
}
	
