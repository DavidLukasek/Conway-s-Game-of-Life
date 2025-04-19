#include <stdlib.h>
#include <stdio.h>

#include "conway.h"

#define MAX_WIDTH 200
#define MAX_HEIGHT 100
#define MAX_ITERATIONS 1000
#define MAX_FPS 120
#define LIVE_CELL '#'
#define DEAD_CELL ' '

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

Canvas_t* getCanvas(int width, int height) {
    Canvas_t* canvas = (Canvas_t*)malloc(sizeof(Canvas_t));
    if(canvas == NULL) {
        return NULL;
    }

    canvas->data = (int**)malloc(height*sizeof(int*));
    if(canvas->data == NULL) {
        return NULL;
    }

    canvas->width = width;
    canvas->height = height;

    //allocating memory for the inside of the canvas each line separately
    for(int i = 0; i < height; i++) {
        canvas->data[i] = (int*)malloc(width*sizeof(int));
        if(canvas->data[i] == NULL) {
            return NULL;
        }
    }

    return canvas;
}

//-------------------------------------------------------------

void fillCanvasRandom(Canvas_t* canvas) {
    int width = canvas->width;
    int height = canvas->height;

    for(int r = 0; r < height; r++) {
        for(int c = 0; c < width; c++) {
            canvas->data[r][c] = rand() % 2;
        }
    }
}

//-------------------------------------------------------------

void freeCanvas(Canvas_t* canvas) {
    int height = canvas->height;

    for(int i = 0; i < height; i++) {
        free(canvas->data[i]);
    }
    free(canvas->data);
    free(canvas);
}

//-------------------------------------------------------------

void printCanvas(Canvas_t* canvas) {
    int width = canvas->width;
    int height = canvas->height;

    for(int r = 0; r < height; r++) {
        for(int c = 0; c < width; c++) {
            printf("%d ", canvas->data[r][c]);
        }
        putchar('\n');
    }
}

//-------------------------------------------------------------

void copyCanvas(Canvas_t* canvas, Canvas_t* copy) {
    int width = canvas->width;
    int height = canvas->height;

    for(int r = 0; r < height; r++) {
        for(int c = 0; c < width; c++) {
            copy->data[r][c] = canvas->data[r][c];
        }
    }
}

//-------------------------------------------------------------

int updateCanvas(int** canvas, int width, int height) {
    int ret = 1;

    return ret;
}
