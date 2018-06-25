#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	//creating basic shell
	char str1[20];
	int status;
	while(1){
		scanf("%s", str1);
		if(strcmp(str1,"exit")==0) //exit when user types it
			exit(0);
		//if user typed something else, we execute the command
		else{
			if(fork() != 0)// parent process
				waitpid(-1, &status, 0);
			else{ //Child process
				*argv[1];
				argv[0] = str1;
				execvp(str1, argv); //executes wat user inputs
				exit(0);//execve doesn't return, so we exit properly
			}
		}
	}
	return 0;
}
