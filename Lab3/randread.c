#include <stdio.h>
#include <string.h>
#include <stdlib.h>
        int main(int argc, char* argv[]) {
                FILE *fp = fopen(argv[1], "r"); //fopen takes in file as argument
                char buff[1];//character buffer that reads 1 character at a time

		//debugging to make sure file opens
		if(fp == NULL){
                        printf("Could not open file ):\n");
                        return -1;
                }
		
		//ptr that moves to the end of the file
		fseek(fp, 0L, SEEK_END); //0L represents beginning of file
		unsigned long long filesz = ftell(fp);
		//count keeps track of how many more characters have to be read 
		unsigned long long counter = filesz; 
		while(counter >= 0){
			int temp = 1;
			//temp stores value telling whether fseek successfully ran
			while(temp != 0){
				// num stores random # to randomly jump to
				unsigned long long num = rand();	
				temp = fseek(fp, num, SEEK_SET);
				counter--;
			}
			fread(buff, 1, 1, fp);
		}
 	return 0;
}
