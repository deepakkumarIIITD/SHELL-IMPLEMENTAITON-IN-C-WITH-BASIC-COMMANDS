#include <readline/readline.h>
#include <stdlib.h>

#include <sys/wait.h>

#include <string.h>

#include <stdio.h>
#include <unistd.h>

int deepak_ka_mkdir(int count , char **inputarray){
	pid_t mkdir_command;
	mkdir_command = fork();
	if(mkdir_command != 0){
		wait(NULL);
	}
	else{
		if((count != 1) && (count != 2) && (count != 3)){
			execl("/bin/mkdir",inputarray[0],inputarray[1],inputarray[2],inputarray[4],NULL);
		}
		else if((count != 2) && (count != 3)){
			execl("/bin/mkdir",inputarray[0],NULL);
		}
		else if((count != 1) && (count != 3)){
			execl("/bin/mkdir",inputarray[0],inputarray[1],NULL);
		}
		else if((count != 1) && (count != 2)){
			execl("/bin/mkdir",inputarray[0],inputarray[1],inputarray[2],NULL);
		}
	}
	return 0;
}