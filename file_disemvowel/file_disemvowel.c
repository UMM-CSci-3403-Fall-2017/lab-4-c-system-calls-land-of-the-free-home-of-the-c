#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUF_SIZE 1024

bool is_vowel(char c){
	if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U'){
		return true;
	}else{
		return 	false;
	}
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf){
	int i, j=0;
	for(i = 0; i < num_chars;i++){
		if(!is_vowel(in_buf[i])){
			out_buf[j] = in_buf[i];
			j++;
		}
	}
	out_buf[j] = '\0';
	return j;
}

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
