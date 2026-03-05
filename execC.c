#include "cell.h"


void execC(token t){
  if (t.size == 0) return;
  
  pid_t pid = fork();

  if(pid<0){
    perror("Fork failed");
    exit(EXIT_FAILURE);
  }
  else if (pid == 0) {
    char ** args = malloc(sizeof(char*)*(t.size+1));
    for (int i = 0;i<t.size;i++) {
      args[i] = t.tokens[i];
    }
    args[t.size] = NULL;

    if(execvp(args[0], args) == -1){
      perror("exec failed");
    }
    
    free(args);
    exit(0);
  }
  else{
    int status;
    waitpid(pid, &status, 0);

    if(WIFEXITED(status)){
      printf("parent and child executed with the status %d\n", WEXITSTATUS(status));
    }
  }
}
