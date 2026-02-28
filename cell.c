#include<stdio.h>
#include<stdlib.h>

int main(){
	char *buffer;
	size_t bufsize;
	size_t characters;
	do{
		

		characters = getline(&buffer, &bufsize, stdin);
		if (characters != -1){
			printf("%s", buffer);
		}
		else{
			perror("getline failed");
			break;
		}
		

	}while(1);
	free(buffer);
	return 0;
}
