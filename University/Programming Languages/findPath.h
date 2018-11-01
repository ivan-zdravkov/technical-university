#ifndef FIND_PATH_H 
#define FIND_PATH_H 
 
#include <stdio.h> 
 
/* 
* The function uses as parameters a matrix, with 1's and 0's  
* the starting point at which we begin building the path 
* (startPointA, startPointB) and the number of rows and  
* columns of the matrix. 
* 
* If the starting position in the matrix is '0' (no character) 
* the function exits saying there is an 'error' in start postition. 
* 
* If the starting position in the matrix is '1' (character) 
* the function checks if the starting position is at the edge  
* of the matrix.  
* 
*  If so the function exits with the node non existant and  
*  displaying a massage saying the start position is at edge 
*  
*  If not the function scans the neighbouring positions and  
*  recursively enters any free postion. If the path is a  
*   'dead end' it returns and continues on until a path has 
*   been found in which case it displays the path, which is  
*   saved in a node 
* 
*/ 
 
struct Node 
{ 
  int pathCoordinateA; 
  int pathCoordinateB; 
  struct Node *next; 
}; 
 
struct Node* findPath(char ** matrix, int startPointA, int startPointB, int 
rows, int columns); 
 
#endif // FIND_PATH_H 
