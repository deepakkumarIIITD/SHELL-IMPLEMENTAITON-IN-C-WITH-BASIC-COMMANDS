#include <readline/readline.h>
#include <stdlib.h>

#include <sys/wait.h>

#include <string.h>

#include <stdio.h>
#include <unistd.h>

#include "2019418_rm.c"
#include <stdbool.h>
#include "2019418_date.c"




#include "2019418_mkdir.c"
#include "2019418_ls.c"

#include "2019418_cat.c"


char deepak_ki_current_directory[2000];
char *deepak_ki_history[200];



char **inputtaker(char *arrayinput){
	char *command_seprator = " ";
	char **deepak_ka_malloc = malloc(16*sizeof(char *));
	int position = 0;
	bool infinity = true;
	if(deepak_ka_malloc != NULL){
		char *input_command = strtok(arrayinput,command_seprator);
		while(infinity){
			if(input_command == NULL){
				infinity = false;
			}
			else{
				deepak_ka_malloc[position] = input_command;
				input_command = strtok(NULL, command_seprator);
				position++;
			}
		}
	}else{
		perror("MALLOC IS NOT WORKING , THERE IS ERROR");
		exit(1);
	}
	deepak_ka_malloc[position] = NULL;
	return deepak_ka_malloc;
}


int deepak_ka_cd(char *location){
	return chdir(location);
}

int deepak_ka_echo(char **inputarray){
	bool infinity = true;
	int position = 1;
	while(infinity){
		if(inputarray[position] != NULL){
			printf("%s",inputarray[position]);
			position++;
		}else{
			infinity = false;
		}
	}
	return 0;
}

int deepak_ka_pwd(){
	if(getcwd(deepak_ki_current_directory,sizeof(deepak_ki_current_directory)) == NULL){
		perror("THERE IS AN ERROR FOR CURRENT WORKING DIRECTORY");
	}
	else{
		printf("%s\n",deepak_ki_current_directory);
	}
	return 0;
}

int deepak_ka_exit(){
	printf("WORK IS COMPLETED AND YOU HAVE EXITED THE SHELL\nTHANK YOU FOR USING DEEPAK KA SHELL\n");
	exit(0);
	return 0;
}

int history_adder(char *input, int current) {
	deepak_ki_history[current] = strdup(input);
	return 0;
}

int deepak_ka_history(){
	bool infinity = true;
	int position = 0;
	while(infinity){
		if(deepak_ki_history[position] != NULL){
			printf("%s\n", deepak_ki_history[position]);
			position++;
		}
		else if(position >= 200 || deepak_ki_history[position] == NULL){
			infinity = false;
		}
	}
	return 0;
}




int main() {
	bool infinity = true;
	char **command_got;
	char *present_input;
	int pos = 0;
	char *next_input;
	while (infinity) {
		present_input = readline("DEEPAK KA SHELL >>---# ");
		next_input = strdup(present_input);
		command_got = inputtaker(present_input);
		int ctr = 0;
		if (!command_got[0]) {    
			free(present_input);
			free(command_got);
			continue;
		}
		history_adder(next_input,pos);
		pos++;
		int numcd = strcmp(command_got[0], "cd");
		int numecho = strcmp(command_got[0], "echo");
		int numpwd = strcmp(command_got[0], "pwd");
		int numexit = strcmp(command_got[0], "exit");
		int numhistory = strcmp(command_got[0], "history");
		int numls = strcmp(command_got[0], "ls");
		int numcat = strcmp(command_got[0], "cat");
		int numdate = strcmp(command_got[0], "date");
		int numrm = strcmp(command_got[0], "rm") ;
		int nummkdir = strcmp(command_got[0], "mkdir");
		// 
		if (numcd == 0) {
			if (deepak_ka_cd(command_got[1]) < 0) {
				perror(command_got[1]);
			}
			ctr = 1;
		}
		// 
		else if (numecho == 0) {
			deepak_ka_echo(command_got);
			ctr = 1;
		}
		// 
		else if (numpwd == 0) {
			deepak_ka_pwd();
			ctr = 1;
		}
		// 
		else if (numexit == 0) {
			deepak_ka_exit();
			ctr = 1;
		}
		// 
		else if (numhistory == 0) {
			deepak_ka_history();
			ctr = 1;
		}
		// 
		else if (numls == 0) {
			deepak_ka_ls(pos,command_got);
			ctr = 1;
		}
		// 
		else if (numcat == 0) {
			deepak_ka_cat(pos,command_got);
			ctr = 1;
		}
		// 
		else if (numdate == 0) {
			deepak_ka_date(pos,command_got);
			ctr = 1;
		}
		// 
		else if (numrm == 0) {
			deepak_ka_rm(pos,command_got);
			ctr = 1;
		}
		// 
		else if (nummkdir == 0) {
			deepak_ka_mkdir(pos,command_got);
			ctr = 1;
		}
		free(present_input);
		free(command_got);
		free(next_input);
	}
	return 0;
}