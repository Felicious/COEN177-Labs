#include <stdio.h>
#include <string.h>
#include <stdlib.h>
	int main(int argc, char* argv[]) {
		FILE *fp = fopen(argv[1], "r"); //fopen takes in file as argument
		
		//debugging messages for the opening file
		if(argc < 2){
			printf("Didn't pass in file\n");
			return -1;
		}
		if(fp == NULL){
			printf("Could not open file ):\n");
			return -1;
		}
		
		//fread moves the pointer fp, so it reads until the end of the file
		while(fgetc(fp) != EOF){};
		fclose(fp); 
	return 0;
}
	
	
