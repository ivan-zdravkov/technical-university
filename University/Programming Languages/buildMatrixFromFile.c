#include <stdio.h> 
#include <stdlib.h> 
 
char **buildMatrixFromFile(FILE *f, int *rows, int *columns) 
{ 
  char **matrix = NULL; 
  char fileToString[10000]; 
  int columnsInCurrentRow; 
  int currentPosInString = 0; 
  int i, j; 
   
  // initialize the rows and columns so we can count them 
  *rows = 0; 
  *columns = 0; 
   
  while(!feof(f)) { 
     
    columnsInCurrentRow = 0; // cycle through each row and count the number of characters it has
    while(!feof(f)) 
	{ 
      fileToString[currentPosInString] = fgetc(f); 
      if(fileToString[currentPosInString++] != '\n') 
        columnsInCurrentRow++; 
      else 
        break; 
      if(currentPosInString > 10000) 
	  { 
        printf("\nError: file too big"); 
        return NULL; 
      } 
    } 
     
    // find the row with the most characters 
    if(columnsInCurrentRow > *columns)  
      *columns = columnsInCurrentRow; 
   (*rows)++; 
  } 
   
  fileToString[currentPosInString - 1] = '\n'; 
 
  // build the matrix 
  matrix = (char **) malloc(sizeof(char *) * (*rows)); 
   
  currentPosInString = 0; 
  for(i = 0; i < *rows; i++) 
  { 
    matrix[i] = (char *) malloc(sizeof(char) * (*columns)); 
	
    // fill the matrix with zeros and ones 
    j = 0; 
    while(fileToString[currentPosInString] != '\n') 
	{ 
      if(fileToString[currentPosInString] == '\0' || fileToString[currentPosInString] == ' ') 
        matrix[i][j] = 1; 
      else 
        matrix[i][j] = 0; 
      j++; 
      currentPosInString++; 
    } 
   
    currentPosInString++; 
    // if there are no more characters in the line fill the rest of the row with ones 
    while(j < *columns) 
      matrix[i][j++] = 1; 
  }  
  return matrix; 
} 
