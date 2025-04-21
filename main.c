#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "conway.h"

#define PARAM_ERR 101;
#define MALLOC_ERR 102;

#define MICROSECONDS 1000000

//-------------------------------------------------------------

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
  Canvas_t* canvas = getCanvas(width, height);
  if(canvas == NULL) {
    fprintf(stderr, "ERROR: Memory allocation failed!");
    free(params);
    return MALLOC_ERR;
  }
  fillCanvasRandom(canvas);

  //creating the canvas copy for effective iterations
  Canvas_t* copy = getCanvas(width, height);
  if(copy == NULL) {
    fprintf(stderr, "ERROR: Memory allocation failed!");
    freeCanvas(canvas);
    free(params);
    return MALLOC_ERR;
  }
  copyCanvas(canvas, copy);

  //printing the initial state of the canvas
  printCanvas(canvas);

  //running the simulation
  for(int i = 0; i < iterations; i++) {
    updateCanvas(canvas, copy);
    printCanvas(canvas);
    copyCanvas(canvas, copy);
    usleep((int)MICROSECONDS/fps);
  }
  
  freeCanvas(canvas);
  freeCanvas(copy);
  free(params);

  return ret;
}

