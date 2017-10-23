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
	char* in_buffer = (char*) calloc(BUF_SIZE + 1,sizeof(char));
	char* out_buffer = (char*) calloc(BUF_SIZE+1,sizeof(char));
	int amountRead=0;
	bool running = true;
	int num_non_vowels;
	while(running){
		amountRead = (int)fread(in_buffer,sizeof(char),BUF_SIZE,inputFile);
	//	printf("Read %d\n",amountRead);
		if(!amountRead){
			break;
		}
		in_buffer[amountRead]='\0';
		//printf("%s\n\n",in_buffer);
		num_non_vowels = copy_non_vowels(amountRead,in_buffer,out_buffer);
		fwrite(out_buffer,sizeof(char),num_non_vowels,outputFile);
	}
	fclose(outputFile);
	fclose(inputFile);
	free(in_buffer);
	free(out_buffer);
}


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
