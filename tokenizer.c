#include "cell.h"

token tokenize(char *args){
  token result;
  result.size = 0;
  result.tokens = NULL;
  char *input_copy = strdup(args);

  if(args == NULL){
    return result;
  }
  
  char* tk = strtok(args, " ");

  while(tk != NULL){
    char **temp = realloc(result.tokens,sizeof(char*)*(result.size+1));
    if(!temp){
      free(input_copy);
      return result;
    }
    result.tokens = temp;
    result.tokens[result.size] = strdup(tk);
    result.size++;

    tk = strtok(NULL, " ");
  }
  free(input_copy);
  return result;
}

void freeToken(token *t){
  for(int i = 0; i < t->size; i++){
    free(t->tokens[i]);
  }
  free(t->tokens);
  t->tokens = NULL;
  t->size = 0;
}

