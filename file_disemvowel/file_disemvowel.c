#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUF_SIZE 1024
//Boolean that returns true if the given char is a vowel
bool is_vowel(char c){
	if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U'){
		return true;
	}else{
		return 	false;
	}
}
// Takes the number of characters in the in_buf and an out_buf 
// and copies all non-vowel characters from the in_buf to the out_buf
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
//Takes an input file and output file and copies all non-vowels from the input file
//to the output file
void disemvowel(FILE* inputFile, FILE* outputFile){
	char* in_buffer = (char*) calloc(BUF_SIZE + 1,sizeof(char));
	char* out_buffer = (char*) calloc(BUF_SIZE+1,sizeof(char));
	int amountRead=0;
	bool running = true;
	int num_non_vowels;
	//while we have not reached the end of the file keep reading from it and copying the non-vowels
	while(running){
		amountRead = (int)fread(in_buffer,sizeof(char),BUF_SIZE,inputFile);
		if(!amountRead){
			break;
		}
		in_buffer[amountRead]='\0';
		num_non_vowels = copy_non_vowels(amountRead,in_buffer,out_buffer);
		fwrite(out_buffer,sizeof(char),num_non_vowels,outputFile);
	}
	//close the files we are reading from and free allocated memory
	fclose(outputFile);
	fclose(inputFile);
	free(in_buffer);
	free(out_buffer);
}

//handles what happens with different numbers of arguments, if none, run from stdin and stdout
//if 1 expect that to be the path to an input file
//if 2 expect the first argument to be the path to an input file and the second to be output file
int main(int argc, char *argv[]){
	FILE *inputFile;
	FILE *outputFile;
	if(argc == 1){
		inputFile = stdin;
		outputFile = stdout;
		disemvowel(inputFile,outputFile);
		return 0;
	} else if(argc == 2){
		inputFile = fopen(argv[1],"r");
		outputFile = stdout;
		disemvowel(inputFile,outputFile);
		return 0;
	} else if(argc == 3){
		inputFile = fopen(argv[1],"r");
		outputFile = fopen(argv[2],"w");
		disemvowel(inputFile,outputFile);
		return 0;
	} else {
		printf("Invalid number of args");
		exit(0);
	}
}
