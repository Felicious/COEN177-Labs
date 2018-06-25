README for Part 1: Basic Shell

For the first assignment, I created a basic shell that takes in the string input 
from the user and executes it if the user types anything other than "exit." The
program ends if the user types exit.

How the code works:
Firstly, the program takes in the string input from the user and checks whether
the user typed exit. If they do, we simply exit, but if they don't, the program 
does the following:

-Takes the input and calls fork() to make a copy of the call
-makes the parent process wait for the child to finish (in if statement)
-In the child process (else statement) executes the string input the user gave 
  by calling execvp. And since execvp doesn't exit on its own, we exit at the end.

How to compile and run:
Use the gcc command to run the vim file, which is named first_task.c. To distinguish
between my outputs, I used -o to name the output file output_of_1.o. The full command
I typed on the terminal was:

gcc first_task.c -o output_of_1.o
Then, I typed this to run my code:

./output_of_1.o 