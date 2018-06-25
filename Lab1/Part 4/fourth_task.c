#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

//Part 4: PLEASE READ WITH README FOR MORE INFO :)
//for the color schemes, please refer to the jpeg :)
int main(){
	for (int i = 0; i < 4; ++i){
		if(fork() == 0) //makes 4 child processes, each the parent of the next, to depth 4 (green)
			printf("parentPid =%d, myID = %d\n", getppid(), getpid()); //this makes process #1-4
		//first iteration goes to parent at level 3, then level 2... to origin
		else{//parent processes of children above, so process #1-4
			int status;
			waitpid(-1, &status, 0); 

			//waits for children from above to terminate, and creates children on the left
			if(fork() == 0)
				printf("parentPid =%d, myID = %d\n", getppid(), getpid()); //creates child #5,9,12,15 (purple)
				// these four children will be called "hopeful parents", for reasons explained in README
			else{
				waitpid(-1, &status,0);
				break;
			}
			
			//note: left and right children of "hopeful parents" are labeled (blue)
			if(fork() == 0) //create right  children from the "hopeful parents" from above
				printf("parentPid =%d, myID = %d\n", getppid(), getpid()); //creates process #6, 10, 13, 16

			//here, we're back at the "hopeful parents"
			else{
				int status;
				waitpid(-1, &status, 0);

				//"hopeful parents" create another child process, this time on the left
				if(fork() == 0)
					printf("parentPid =%d, myID = %d\n", getppid(), getpid()); //creates process #7, 11, 14, 17
				//back at the "hopeful parents", who...
				else{
					waitpid(-1, &status,0); //most "hopeful parents" are in charge of making two children
					//only one hopeful parent (#5) creates a third child on depth level five (red)
					if(i == 3){ //use this to make sure only one of the hopeful parents makes the additional child process
						if(fork() == 0)
							printf("parentsPid = %d, myID = %d\n", getppid(), getpid()); //makes process #8, which is "starred" * in README
						else{
							waitpid(-1, &status, 0);
							break;
						}
					}
					//Ends
					break;
				}
				break;
			}

			break;
		}
	}
	return 0;
}
