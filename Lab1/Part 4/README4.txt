README for Part 4 : 17 Children
Despite the for loops, my code runs semi-recursively. The order in which the processes are made are as follows:
						Origin
                                      /			        \	
				15					1					depth: 1
                            /        \                              /         \
			17		6 			12		2				depth: 2
                                                            /      \           /        \
							14	   13         9		    3			depth: 3
	                                                                     /	\          /       \					 
									   11	10         5            4	depth: 4
										         /  |    \
                               								*8    7    6


How the code works: 

Even though I used a for loop that iterated four times, my program worked semi-recursively, with processes making children 
from largest depth to smallest, with the final, 17th child process created on depth 2. 

Allow me to give a step-by-step run-through on how processes are created in my program.

Within the for loop, the first fork() call creates one child. Since the for loop iterates four times, this creates a line 
of children, each a parent of the other all the way to depth level 4. Then, within the else statement that deals with the 
parent process, the parent waits for the final child process to be created (#4). 
 
After child process #4 exits, its parent, #3, creates another child, as indicated by the first nested fork() call, creating
process #5. This child process is important, as explained later in this file, and I will give it, and the others who serve
the same purpose, a name to better reference these processes. I will call process #5, and others like it, "hopeful parents"
because they are responsible for creating a number of child processes who do not make their own children. Thus, these 
"hopeful parents" are indefinitely parents and will never become "grandparents", so to speak.  

Then, the parent, #3, waits for the child to finish executing (CRUCIAL WAIT), so we move onto the second nested fork call, 
which creates the right child of the "hopeful parent" process #5: #6. 

In the else statement, the "hopeful parent" #5 calls fork() again and makes a left child, #7. Nothing novel, at this point.

However, within the else statement of this fork(), there is a condition that checks for the depth of the "hopeful parent", 
and if the depth is 4, (meaning it is on the 3rd iteration of the for loop) make a third child, #8. This statement ensures
that all of the "hopeful parents" are responsible for creating at least a left and right child process, with the "hopeful
parent" #5 being in charge of creating 3. 

(It is also notable to mention the semi-recursive behavior of this program, as fork() executed the creation of the third 
child when the iteration (i == 3), meaning that process #8 was created before the other children (9-17) who were supposed 
to be created when i<3. From here on out, the child processes of the original four processes (#1-4) are created bottom up,
or largest depth to smallest). 

Now that all child processes for the "hopeful parent" have been created, it exits, and we go back to parent #3, up where I
marked "(CRUCIAL WAIT) up above. Parent #3 breaks, and then control is given to parent #2 creates its children with the 
same procedure in which parent #3 creates its, with the only exception: the "hopeful parent" of this group of processes
only create two children. 

This repeats even when the parent becomes the origin, the original process we were instructed to make child processes of. 
At this stage, it simply creates one "hopeful parent", #15, and two children, #16 and #17.

Now, the forks break, and the program ends! 


How to compile and run:
 
Since I used a for loop with for(int i =0), I needed to include -std=c99 to include the standard c library to compile my code.
I used the same naming scheme to call my output output_of_4.o, and used gcc to compile it. This is what I typed on command
line:
gcc fourth_task.c -std=c99 -o output_of_4.o
Then I used this to run my code:

./output_of_4.o

Output: 
parentPid =13781, myID = 13782
parentPid =13782, myID = 13783
parentPid =13783, myID = 13784
parentPid =13784, myID = 13785
parentPid =13784, myID = 13786
parentPid =13786, myID = 13787
parentPid =13786, myID = 13788
parentsPid = 13786, myID = 13789
parentPid =13783, myID = 13790
parentPid =13790, myID = 13791
parentPid =13790, myID = 13792
parentPid =13782, myID = 13793
parentPid =13793, myID = 13794
parentPid =13793, myID = 13795
parentPid =13781, myID = 13796
parentPid =13796, myID = 13797
parentPid =13796, myID = 13798
