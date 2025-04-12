#include <stdio.h>
#include <stdlib.h>

#include "conway.h"

#define PARAM_ERR 101;
#define MALLOC_ERR 102;

int main(int argc, char *argv[]) {
  int ret = 0;

  //getting the game parameters from the user
  int* params = getParams();
  if(params == NULL) {
    fprintf(stderr, "ERROR: Invalid user input!");
    return PARAM_ERR;
  }
  
  int width = params[0];
  int height = params[1];
  int fps = params[2];
  int iterations = params[3];

  //creating the game canvas
  int** canvas = getCanvas(width, height);
  if(canvas == NULL) {
    fprintf(stderr, "ERROR: Memory allocation failed!");
    free(params);
    return MALLOC_ERR;
  }

  free(params);

  return ret;
}
