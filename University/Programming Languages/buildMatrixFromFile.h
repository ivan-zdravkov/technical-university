#ifndef BUILD_MATRIX_H 
#define BUILD_MATRIX_H 
 
#include <stdio.h> 
 
/** 
 * This function takes a file and builds a two dimensional 
 * array from it with. The array has as many rows as the number 
 * of lines the file has and as many columns as the number of 
 * characters in the longest row. The array is filled with zeros 
 * and ones as values in it, where 0 indicates there is a 
 * character in that position of the file and 1 indicates 
 * there is no character(ASCII '\0') or a space(ASCII ' ') 
 * in that position of the file. (1 and 0 may look strange, 
 * but the task was given in such a way)
 * 
 * @param f 
 *    A pointer to a FILE structure with data 
 *  for the file. 
 * 
 * @param rows 
 *    A pointer to an int the reference which 
 * will be initialized with the number of rows 
 * the file, respectively the matrix has. 
 * 
 * @param columns 
 *    A pointer to an int the reference which 
 * will be initialized with the number of columns 
 * the file, respectively the matrix has. 
 * 
 * @return 
 *    returns a pointer to a pointer to char (char **) 
 *  to the matrix the function has build 
 */ 
char **buildMatrixFromFile(FILE *f, int *rows, int *columns); 
 
#endif // BUILD_MATRIX_H 
