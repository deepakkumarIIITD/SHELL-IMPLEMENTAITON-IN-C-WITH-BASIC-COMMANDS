#include <readline/readline.h>
#include <stdlib.h>

#include <sys/wait.h>

#include <string.h>

#include <stdio.h>
#include <unistd.h>

int deepak_ka_rm(int count , char **inputarray){
	pid_t rm_command;
	rm_command = fork();
	if(rm_command != 0){
		wait(NULL);
	}
	else{
		if((count != 1) && (count != 2)){
			execl("/bin/rm",inputarray[0],inputarray[1],inputarray[2],NULL);
		}
		else if(count != 1){
			execl("/bin/rm",inputarray[0],inputarray[1],NULL);
		}
		else if(count != 2){
			execl("/bin/rm",inputarray[0],NULL);
		}
	}
	return 0;
}