This is the Readme for the first part of the lab 

Within main.c of the kernel, the announce function handles attributing credit for the company who created minix. To make changes to the copyright message, I went into the function and altered the printf statement. 

The change I made was in line 275 of main.c.
Second part of lab

In order to alter the speed of the scheduler, I made changes in the pick_proc
function of proc.c, which can be found inside the kernel. The original pick_proc
function worked like this: 

It had an integer variable q that represented the priority number of each process, 
which was already determined by another function. The highest priority value (so
the process would run first) is 0, and the lowest priority value is an integer 
represented by NR_SCHED_QUEUES (which was 16 in this case). Each process would run
in the order given by the priority value determined in another function. This 
original pick_proc caused minix to start up in about 12 seconds. 

To skew the priority scheduler, I created an integer value called lottery that 
generated a random number from 0 to 9 for each iteration of the for loop when
a value of q is already determined for a process. Then, if the lottery value
happens to be 3 (this number was chosen randomly by me), the current value of q
would be randomly assigned to a lower priority value, represented by the integer
r. Low priority in this case is any priority value between 3 and NR_SCHED_QUEUES.

Thus, approximately 10% of the time, the priority of a random process would be
randomly altered to a lower priority, slowing down the start-up of minix. 

My changes are in proc.c, between lines 1313-1316.

How I tested my changes:
After I made alterations to main.c and proc.c, I tested whether my changes work-
ed as expected by typing "get main.c" or "get proc.c" to import my replaced the
minix files with my altered ones. Then, I typed exit to exit the ftp mode. I am
currently in the minix file containing the kernel and I type cd .. to go back 
one directory. Here, I type in the command "make world", and after it is done,
I type "reboot" to compile and run minix with my changes. 

For part 1, I am simply looking for changes to the text in the print statement,
and my change was simply adding "and me!" to the end of the copyright state-
ment. 

For part 2, I timed how long it took to reboot minix. Originally, the unaltered
minix finishes running in 12 seconds. I timed mine, and it finished running in
2 and a half minutes for one interation.    
