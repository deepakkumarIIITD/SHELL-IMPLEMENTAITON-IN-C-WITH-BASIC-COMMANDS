#include <readline/readline.h>
#include <stdlib.h>

#include <sys/wait.h>

#include <string.h>

#include <stdio.h>
#include <unistd.h>

int deepak_ka_cat(int count , char **inputarray){
	pid_t cat_command;
	cat_command = fork();
	if(cat_command != 0){
		wait(NULL);
	}
	else{
		if(count != 1){
			execl("/bin/cat",inputarray[0],inputarray[1],NULL);
		}
		else{
			execl("/bin/cat",inputarray[0],NULL);
		}
	}
	return 0;
}