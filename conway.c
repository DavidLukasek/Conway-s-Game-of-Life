#include <stdlib.h>
#include <stdio.h>

#include "conway.h"

#define MAX_WIDTH 200
#define MAX_HEIGHT 100
#define MAX_ITERATIONS 1000
#define MAX_FPS 120

int* getParams(void) {
    int* params = (int*)malloc(4*sizeof(int));
    if(params == NULL) {
        fprintf(stderr, "ERROR: Memory allocation failed!\n");
        return NULL;
    }

    //getting the dimensions of the canvas
    printf("Please, enter canvas dimensions (up to %d x %d max):\n",
            MAX_WIDTH, MAX_HEIGHT);
    if(scanf("%d %d", &params[0], &params[1]) != 2 ||
            params[0] < 1 || params[0] >= MAX_WIDTH ||
            params[1] < 1 || params[1] >= MAX_HEIGHT) {
        free(params);
        return NULL;
    }

    //getting the simulation rate (FPS)
    printf("Please, enter simulation rate (up to %d max):\n", MAX_FPS);
    if(scanf("%d", &params[2]) != 1 || params[2] < 1 || params[2] > MAX_FPS) {
        free(params);
        return NULL;
    }

    //getting the number of iterations
    printf("Please, enter number of iterations (up to %d max):\n",
            MAX_ITERATIONS);
    if(scanf("%d", &params[3]) != 1 || params[3] < 1 ||
       params[3] > MAX_ITERATIONS) {
        free(params);
        return NULL;
    }

    return params;
}

char** getCanvas(int width, int height) {
    char** canvas = (char**)malloc(height*sizeof(char*));
    if(canvas == NULL) {
        fprintf(stderr, "ERROR: Memory allocation failed!\n");
        return NULL;
    }

    //allocating memory for the inside of the canvas each line separately
    for(int i = 0; i < height; i++) {

    }
}