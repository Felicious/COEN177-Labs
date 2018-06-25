README for general (housekeeping) purposes
To three very large files of sizes 1G, 2.5G, and 5G by typing:
	cat /dev/urandom|head -c (insert size)>/local/weka/(insert size)
ex)	cat /dev/urandom|head -c 5G>/local/weka/5G.bin
	Note: I used .bin to distinguish my files from some other student's file
	which followed the same naming scheme. 

Also, to make sure I am using the same file I created previously, I would type:
	ls -1 /local/weka 
and this displays all the local weka files on the current computer. 


In order to read all of the 1G, 2.5G, and 5G files in a batch, I did the follow-
ing:
	I made a shell file that was type .sh and typed out execution calls in
	it as if I were running the .o output file in terminal. I repeated each
	call three times to run each thrice. Also, I included an echo before
	I started running a new program to let myself know which one of the 
	programs just finished.
Then, to run the batch, I typed bash <insert name of .sh file made above> and 
the batch would start running.
	To exit and do something else,
		CTRL + A, CTRL + D
	Check to see if the batch is running:
		screen -ls
	Then, later when you want to return and check the progress of the batch,
		screen -r
		(use exit and do something else command above when done)
	To exit (do you really want to do this??)
		CTRL + D

README for sequential read (seqread.c):
	seqread.c simply takes in a file path at execution a parameter and reads the
	file, 1 byte at a time. To do this, the program uses a pointer that goes
	through each character of the file (using a while loop) and reads it until
	the ptr reaches the end. Then, it closes the file at the end. 

	And, as I had a few problems with file I/O, this program also features a 
	few debugging if statements to make sure the file is opening properly.

README for random read (randread.c):
	This program also takes in a file (path) when compiling and running it. It
	opens the file and creates a ptr fp that will be used to read a certain char
	it is pointing to. However, in this program, the character that is read is
	randomly selected. 

	First, the first fseek moves the ptr fp to the end of the file, and I used 
	the function call ftell to  give the size of the file, specifically the num
	of characters in it. I also kept a counter variable to keep track of how 
	many more bytes my program needs to randomly read in. 

	Inside the while loop, which runs until the counter variable reaches 0, me-
	aning the required number of bytes has been read, a variable temp, which
	acts like a boolean, is initialized to 1. This functions to tell us whether 
	or not fseek chose an index that's within the size of the file. If not, it
	would just proceed to read what was read previously.
	
	Within the second while loop, a random number is chosen for a random
	index to read. (If the random number is out of bounds, fseek would return 0
	and the program would try again at selecting a random number). At the end of
	it all, once a random index that's within the bounds is selected, that chara-
	cter is read. The program would keep doing this until the counter goes to 0,
	and the number of characters equivalent to the size of the file is read and
	that's it!



To compile and run:
Used gcc to compile my code and named seq.o and rand.o my output files for my 
sequential read and random read programs. To run the code and generate the time
at the output, I typed this into the command line:
(used random read of a 1G file here for example)
/bin/time -f %E ./rand.o /local/weka/1G.bin


Output:

seq.o 1G.bin
0:06.01
0:05.95
0:06.02
Average : 5.99 seconds

seq.o 2.5G.bin
0:14.29
0:14.40
0:14.48
Avg: 14.39 seconds

seq.o 5G.bin
0:29.57
0:29.35
0:29.56
Avg: 29.49 seconds 

rand.o 1G.bin
27:05.14
26:24.10
26:26.02
Avg: 26.52 minutes

rand.o 2.5G bin
50:34.75
50:11.50
50:11.39
Avg: 50.19 minutes

rand.o 5G.bin
1:42:58
1:42:59
1:42:57
Avg: 1 hour 42 minutes and 58 milliseconds

Three relationships between the times:

For sequential read, the time for 1G was about 6 seconds, and the time for the
5G file was almost 30 seconds. 30/6 = 5, and it makes sense that the 5G seqread
would take five times longer than the 1G, because the 5G file is 5 times longer
than 1G, and the speed of reading a file sequentially is dependent on the size
of the file, in this case. 
The same thing happens with the 2.5G seqread. The 2.5G file took about14 seconds
to run, and 14/6= 2.3, which is close to 2.5. Thus, the 2.5G file took 2.3 times
longer than the 1G file, which makes sense given that 2.5G is 2.5 times bigger
than 1G. 

In the case of random read, the relationship between 1G and 2.5G, also 1G and
5G are not as clear-cut. 1G, which finished in 26 minutes, took half the time of
2.5G, which took about 50 minutes. As the 2.5G file is 2.5x as large, it should
have had taken 2.5 times, but it only took about 2 times. This is because, un-
like sequential read, my program randomly selects the next character to read.

Thus, if by chance the next character were in an more easily accessible location
such as at the beginning of the file or where the last character was, the
program would have to put in less work and time to find the next "random" bit. 
On the flip side, if I were unlucky and the read ptr would have to jump all over
the file to find the next random character, it would take longer than it should.

Additionally, it would take longer to finish reading if the rand function kept
choosing indices that are out of bounds of the file. Therefore, if the program 
kept having to re-select a random value in bounds, it would also slow down the 
run time of a randread file. 
Thus, I think 1G took a little longer than it should and 2.5 finished faster due
to these random chances.

By some chance, the 5G randread took took about twice as long as 2.5G (appox. 1 
hour 40 min to 50 min). This relationship is interesting because it is the same
as seqread, where the 2.5G file took half the time as the 5G one because the 
file size of 5G is twice is large as 2.5G. This means that both times the 2.5
and 5G files were running, the random selection of the next character to read 
did not drasticly speed up or slow down the overall reading process. Both of
these iterations of the random and sequential reads behaved typically, and had
about the same (relative to its size) number of random numbers that were out
of bounds of the file.  
