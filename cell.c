#include "cell.h"

int main(){
	char *buffer;
	size_t bufsize;
	ssize_t characters;
  token result;
  result.tokens = NULL;
  result.size = 0;
	do{
		characters = getline(&buffer, &bufsize, stdin);
		if (characters != -1){
      result = tokenize(buffer);
      execC(result);
		}
		else{
			perror("getline failed");
			break;
		}
		

	}while(1);
  freeToken(&result);
	free(buffer);
	return 0;
}
