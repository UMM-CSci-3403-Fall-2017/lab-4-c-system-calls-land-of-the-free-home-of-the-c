#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024


void disemvowel(FILE* inputFile, FILE* outputFile){
	char buffer[BUF_SIZE + 1];
	int amountRead = fread(buffer, sizeof(char), BUF_SIZE, inputFile);
	buffer[BUF_SIZE]= '\0';
	printf("%s", buffer);
}


int main(int argc, char *argv[]){
	FILE *inputFile;
	FILE *outputFile;
	if(argc == 0){
	inputFile = stdin;
	outputFile = stdout;
	disemvowel(inputFile,outputFile);
	return 0;
	} else if(argc == 1){
	inputFile = fopen(argv[0],"r");
	outputFile = stdout;
	disemvowel(inputFile,outputFile);
	return 0;
	} else if(argc == 2){
	inputFile = fopen(argv[0],"r");
	outputFile = fopen(argv[1],"w");
	disemvowel(inputFile,outputFile);
	return 0;
	}
}
