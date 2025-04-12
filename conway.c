#include <stdlib.h>
#include <stdio.h>

#include "conway.h"

#define MAX_WIDTH 200
#define MAX_HEIGHT 100
#define MAX_ITERATIONS 1000
#define MAX_FPS 120

//-------------------------------------------------------------

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

//-------------------------------------------------------------

int** getCanvas(int width, int height) {
    int** canvas = (int**)malloc(height*sizeof(int*));
    if(canvas == NULL) {
        fprintf(stderr, "ERROR: Memory allocation failed!\n");
        return NULL;
    }

    //allocating memory for the inside of the canvas each line separately
    for(int i = 0; i < height; i++) {
        canvas[i] = (int*)malloc(width*sizeof(int));
        if(canvas[i] == NULL) {
            fprintf(stderr, "ERROR: Memory allocation failed!\n");
            return NULL;
        }
    }

    //filling the array with random 1s and 0s
    for(int r = 0; r < height; r++) {
        for(int c = 0; c < width; c++) {
            canvas[r][c] = rand() % 2;
        }
    }

    return canvas;
}
