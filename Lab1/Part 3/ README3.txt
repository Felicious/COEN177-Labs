README for Part 3: 12 Children
In this program, I used a for loop that iterated six times to create six children, each a parent of the next, and made 
each parent create one more child, resulting with a total of 12 children.
					Origin
				/			\
		12						1 				depth: 1
						            /       \
							11		2			depth: 2
						                     /      \
								10		3               depth: 3
									     /      \
									  9		4	depth: 4
										    /      \
										   8		5	depth: 5
											     /    \
											   7        6 	depth: 6


How the code works:
Due to the nature of fork(), the program runs semi-recursively even though a for loop was used. When the for loop iterates
from 0 to 5, fork() is called six, creating six children, each a parent of the next. Now, the first if statement has been
fulfilled, creating processes #1-6, as shown above. 

Now, the else statement, containing the parent process, gets to execute, since it was waiting for the six children to make
their calls. Inside the else statement, the first parent that gets its control back is process #5, because it was the 
parent of the most recently created child, process #6. As shown in the else statement, #5 creates one more child (#7) and
breaks, relinquishing its control to its own parent, #4, who takes the same action of creating one more child and giving
control back to its parent. This process repeats even as control is given back to the origin, the process we were in-
structed to make child processes for in this lab assignment. The final child is created by the origin, #12, and finally
the program breaks and the for loop has been completed.

The reason why I stated that the program runs semi-recursively is because after the first six children are created, the 
processes are created from bottom-up, with processes whose parents have greatest depth first. I found it interesting that
although the for loop incremented for every iteration, the else statement executed from in a decremntal fashion.  

how to compile:
Since I used a for loop with for(int i =0), I needed to include -std=c99 to include the standard c library to compile my code.
I used the same naming scheme to call my output output_of_3.o, and used gcc to compile it. This is what I typed on command
line:
gcc third_task.c -std=c99 -o output_of_3.o
Then I used this to run my code:

./output_of_3.o 

Output: 
parentPid = 13870, myID = 13871
parentPid = 13871, myID = 13872
parentPid = 13872, myID = 13873
parentPid = 13873, myID = 13874
parentPid = 13874, myID = 13875
parentPid = 13875, myID = 13876
parentPid = 13875, myID = 13877
parentPid = 13874, myID = 13878
parentPid = 13873, myID = 13879
parentPid = 13872, myID = 13880
parentPid = 13871, myID = 13881
parentPid = 13870, myID = 13882
