#include <readline/readline.h>
#include <stdlib.h>

#include <sys/wait.h>

#include <string.h>

#include <stdio.h>
#include <unistd.h>

int deepak_ka_date(int count , char **inputarray){
	pid_t date_command;
	date_command = fork();
	if(date_command != 0){
		wait(NULL);
	}
	else{
		if(count != 1){
			execl("/bin/date",inputarray[0],inputarray[1],NULL);
		}
		else{
			execl("/bin/date",inputarray[0],NULL);
		}
	}
	return 0;
}