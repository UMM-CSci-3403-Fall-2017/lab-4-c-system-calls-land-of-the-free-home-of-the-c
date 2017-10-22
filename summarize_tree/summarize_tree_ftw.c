#include <stdio.h>
#include <sys/stat.h> 
#include <stdbool.h> 
#include <stdlib.h>
#include <dirent.h> 
#include <unistd.h>
#include <string.h>
#include <linux/stat.h>
#include <ftw.h>

#define MAX_FTW_DEPTH 16

int dirCount = 0;
int fileCount = 0;

static int callback(const char *fpath,const struct stat *sb, int typeflag){
	if(typeflag == FTW_D){
		dirCount++;
		return 0;
	} else if (typeflag == FTW_F){
		fileCount++;
		return 0;
	} else{
		return -1;
	}
}
int main(int argc,char** argv){
	if(argc < 2){
		return 0;
		printf("Not enough args");
	}
	else if(argc == 2){

		ftw(argv[1],callback, MAX_FTW_DEPTH);
		printf("Processed all the files from ");
		printf("%s\n",argv[1]);
		printf("There were ");
		printf("%d",dirCount);
		printf(" directories.\n");
		printf("There were ");
		printf("%d",fileCount);
		printf(" files.\n");
		return 1;
	} else if (argc >= 3){
		printf("I got to last case");
		return 0;
	}
}
