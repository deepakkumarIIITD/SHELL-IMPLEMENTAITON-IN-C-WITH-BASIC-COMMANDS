#include <readline/readline.h>
#include <stdlib.h>

#include <sys/wait.h>

#include <string.h>

#include <stdio.h>
#include <unistd.h>

int deepak_ka_ls(int count , char **inputarray){
	pid_t ls_command;
	ls_command = fork();
	if(ls_command != 0){
		wait(NULL);
	}
	else{
		if(count != 1){
			execl("/bin/ls",inputarray[0],inputarray[1],NULL);
		}
		else{
			execl("/bin/ls",inputarray[0],NULL);
		}
	}
	return 0;
}