#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

typedef struct {
	char **listOfStrings;
	int size;
}TokenResult;

//function to take the string given by user and convert to an array of strings to execute
TokenResult tokenize(char *args){	
	char *saveptr;
	char delims[] = " \n";
	char **result = NULL;
	int count = 0;
	char *token = strtok_r(args,delims,&saveptr);
	while(token != NULL){
		char ** temp = realloc(result, (count+1)*sizeof(char*));
		if (temp == NULL){
			free(result);
			return NULL;
		}
		
		result = temp;
		result[count] = token;
		count++;

		token = strtok_r(args, delims, &saveptr)
	}
	TokenResult ret;
	ret.listOfStrings = result;
	ret.size = count;

	return ret;
}



int main(){
	//REPL part of my code
	do{
		char *input;
		size_t lenOfIn;
		ssize_t read;
		printf("shell>");
		read = getline(&input, &lenOfIn, stdin);
		if(read == -1){
			break;
		}
		TokenResult givenCode = tokenize(input);
		for(int i = 0; i<givenCode.n; i++){
			printf("%s", givenCode.listOfStrings[i]);
		}

		free(givenCode.listOfStrings);

	}while(1);
}
