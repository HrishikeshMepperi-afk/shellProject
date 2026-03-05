#ifndef CELL_H
#define CELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct token_s{
  char **tokens;
  int size;
}token;

token tokenize(char *args);

void freeToken(token *t);

void execC(token t);


#endif // CELL_H
