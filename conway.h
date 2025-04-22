#ifndef CONWAY_H
#define CONWAY_H

/**
 * Structure representing the canvas.
 * Data should contain a 2-dimensional array
 * of 1s and 0s with dimensions given by the
 * width and height parameters
 */
typedef struct Canvas_t {
    int** data;
    int width;
    int height;
} Canvas_t;

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
 * Allocates memory for the canvas and initializes it randomly
 * with 1s for live cells and 0s for dead cells.
 * @param width - width of the canvas
 * @param height - height of the canvas
 * @return Canvas containing a pointer to a 2D array of integers
 *         representing it and its dimensions. NULL if error.
 * The caller is responsible for freeing the memory.
 */
Canvas_t* getCanvas(int width, int height);

/**
 * Fills the canvas randomly with 1s for live cells and 0s for dead cells.
 * @param canvas - pointer to the Canvas structure
 */
void fillCanvasRandom(Canvas_t* canvas);

/**
 * Frees the memory allocated for the canvas.
 * @param canvas - pointer to the Canvas structure
 */
void freeCanvas(Canvas_t* canvas);

/**
 * Prints the current state of the canvas to the console.
 * @param canvas - pointer to the Canvas structure
 */
void printCanvas(Canvas_t* canvas);

/**
 * Copies the given canvas into the copy canvas memory.
 * @param canvas - pointer to the Canvas structure
 * @param copy - pointer to the Canvas structure to copy into
 */
void copyCanvas(Canvas_t* canvas, Canvas_t* copy);

/**
 * Updates the canvas by applying the rules of Conway's Game of Life.
 * @param canvas - pointer to the Canvas structure
 * @param copy - pointer to the Canvas structure to copy into
 */
void updateCanvas(Canvas_t* canvas, Canvas_t* copy);

/**
 * Counts the number of neighboring live cells in a 3x3 grid around the
 * cell defined by the given coordinates, accounts for index looping
 * @param canvas - pointer to the Canvas structure
 * @param row - index of the row of the middle cell
 * @param col - index of the collumn of the middle cell
 * @return Number of live neighboring cells
 */
int countNeighbors(Canvas_t* canvas, int row, int col);

#endif
