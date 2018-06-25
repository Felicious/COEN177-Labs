README for Part 2: 8 Children

How the code works:
This program simply creates eight child processes, each a parent of the next. 
To do this, the for loop iterates 8 times, and each time, one child process is 
created in the if statement, where fork() is called. Then, in the else, the 
process waits for the child to finish making the children they need. So, the 
parent process #1 waits.

Then, child process #2 is created from #1, and #3 from #2, until #8 is created.
Once #8 is created, it breaks, ending the child process, which triggers the
parent #7 to break, because #7 was waiting for #8 to break. This successively 
causes #6 all the way to #1 to break, and the program ends.

how to compile:
Since I used a for loop with for(int i =0), I needed to include -std=c99 to include the standard c library to compile my code.
I used the naming scheme to call my output output_of_2.o, and used gcc to compile it. This is what I typed on command
line:
gcc second_task.c -std=c99 -o output_of_2.o
Then I used this to run my code:

./output_of_2.o 

Output: 
parentPid = 22009, myId = 22010
parentPid = 22010, myId = 22011
parentPid = 22011, myId = 22012
parentPid = 22012, myId = 22013
parentPid = 22013, myId = 22014
parentPid = 22014, myId = 22015
parentPid = 22015, myId = 22016
parentPid = 22016, myId = 22017
