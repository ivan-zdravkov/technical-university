#include <stdio.h> 
#include <stdlib.h> 
 
struct Node // The struct node which saves the path  
{ 
  int pathCoordinateA;  
  int pathCoordinateB; 
  struct Node *next; 
}; 
 
extern int flagForFuncEntry; // flag that shows if there has been a recursion or not 
extern int nonExistant; // flag that shows weather the path taken is a dead end 
 
struct Node* findPath(char ** matrix, int startPointA, int startPointB, int rows, int columns) 
{ 
  struct Node* head_pointer = NULL; 
 
  if(matrix[startPointA][startPointB] == 0) // Check, weather the starting point is a legit position 
  { 
    printf("Error! Starting Position is not an empty symbol!\n"); 
    flagForFuncEntry = 1; 
    return head_pointer; 
  } 
  if((startPointA == 0) || (startPointA == rows - 1) || (startPointB == 0) || (startPointB == columns - 1)) // 'end of matrix' check 
  { 
    return head_pointer;  
  } 
 
  // Checking all the neighbouring positions for a free space to move 
  if(matrix[startPointA + 1][startPointB] == 1) 
  { 
    matrix[startPointA][startPointB] = 0; // changing the current position to 0, so that it wont enter it again 
    head_pointer = (struct Node *) malloc(sizeof(struct Node)); // creating a node 
    head_pointer->pathCoordinateA = startPointA + 1; // saving the A coordinate in the node 
    head_pointer->pathCoordinateB = startPointB; // saving the B coordinate in the node 
    flagForFuncEntry = 1; // setting the recursion flag to 1 
    head_pointer->next = findPath(matrix, startPointA + 1, startPointB, rows, columns); // recursion 
    matrix[startPointA][startPointB] = 1; // changing the current position again to 1, after the recursion is exiting, weather because of 'dead end' or success! 
    if(head_pointer->next==NULL) // if the previous function exited with NULL, return head_pointer to exit the recursion. 
    { 
      return head_pointer; 
    } 
  } 
  if(matrix[startPointA - 1][startPointB] == 1) 
  { 
    matrix[startPointA][startPointB] = 0; 
    head_pointer = (struct Node *) malloc(sizeof(struct Node)); 
    head_pointer->pathCoordinateA = startPointA - 1; 
    head_pointer->pathCoordinateB = startPointB; 
    flagForFuncEntry = 1; 
    head_pointer->next = findPath(matrix, startPointA - 1, startPointB, rows, columns); 
    matrix[startPointA][startPointB] = 1; 
    if(head_pointer->next==NULL) 
    { 
      return head_pointer; 
    } 
  } 
if(matrix[startPointA][startPointB + 1] == 1) 
  { 
    matrix[startPointA][startPointB] = 0; 
    head_pointer = (struct Node *) malloc(sizeof(struct Node)); 
    head_pointer->pathCoordinateA = startPointA; 
    head_pointer->pathCoordinateB = startPointB + 1; 
    flagForFuncEntry = 1; 
    head_pointer->next = findPath(matrix, startPointA, startPointB + 1, rows, columns); 
    matrix[startPointA][startPointB] = 1; 
    if(head_pointer->next==NULL) 
    { 
      return head_pointer; 
    } 
  }
   if(matrix[startPointA][startPointB - 1] == 1) 
  { 
    matrix[startPointA][startPointB] = 0; 
    head_pointer = (struct Node *) malloc(sizeof(struct Node)); 
    head_pointer->pathCoordinateA = startPointA; 
    head_pointer->pathCoordinateB = startPointB - 1; 
    flagForFuncEntry = 1; 
    head_pointer->next = findPath(matrix, startPointA, startPointB - 1, rows, columns); 
    matrix[startPointA][startPointB] = 1; 
    if(head_pointer->next==NULL) 
    { 
      return head_pointer; 
    } 
  } 
  else 
  { 
    nonExistant = 1; 
    return NULL; // return NULL to exit recursion if a dead end! 
  } 
} 
 
