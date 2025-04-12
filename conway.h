#ifndef CONWAY_H
#define CONWAY_H

/**
 * Gets the parameters from the user.
 * @return Pointer to an array of integers containing the parameters:
 *          [0] - canvas width
 *          [1] - canvas height
 *          [2] - simulation rate (FPS)
 *          [3] - number of iterations
 *          NULL if invalid input or memory allocation failed.
 *          The caller is responsible for freeing the memory.
 */
int* getParams(void);

/**
 * Allocates memory for the canvas and initializes it.
 * @param width - width of the canvas
 * @param height - height of the canvas
 * @return Pointer to a 2D array of characters representing the canvas.
 *         The caller is responsible for freeing the memory.
 */
char** getCanvas(int width, int height);

#endif
