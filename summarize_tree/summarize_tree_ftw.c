#include <stdio.h>  
#include <stdlib.h>
#include <dirent.h> 
#include <ftw.h>

#define MAX_FTW_DEPTH 16

int dirCount = 0;
int fileCount = 0;
//callback looks at the typeflag of the current files and updates counts accordingly
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
		ftw(argv[1],callback, MAX_FTW_DEPTH);

		printf("There were %d directories.\n",dirCount);
		printf("There were %d regular files.\n", fileCount);
		return 0;
}
