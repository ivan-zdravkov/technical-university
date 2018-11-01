#include "buildMatrixFromFile.h" 
#include "findPath.h" 
#include "stdio.h" 
#include "stdlib.h" 
 
int flagForFuncEntry = 0; // flag that shows if there has been a recursion or not 
int nonExistant = 0; // flag that shows weather the path taken is a dead end 
 
void main(int argc, char *argv[]) 
{ 
   
  struct Node *head = NULL; // The node, that the findPath function uses 
  char **matrix = NULL; 
  int columns = 0, rows = 0; 
  int entryPointA = 0; 
  int entryPointB = 0; 
  int i = 0, j = 0; 
  FILE *f; 
 
  f = fopen("C:\\hello.txt", "r"); 
  if(!f) { 
    printf("\nError in opening file! File may not exist\n"); 
    system("PAUSE"); 
    return ; 
  } 
 
  matrix = buildMatrixFromFile(f, &rows, &columns);
 
  // The creation of the starting point from where to start the path 
  printf("Enter the starting point for A coordinate (rows): "); 
  scanf("%d", &entryPointA); 
  printf("Enter the starting point for B coordinate (columns): "); 
  scanf("%d", &entryPointB); 
 
  //Writes the content of the Matrix on the output. 
  for(i = 0; i < rows; i++)  
  { 
    for(j = 0; j < columns; j++) 
      printf("%d ", matrix[i][j]); 
    printf("\n"); 
  }
   
  head = findPath(matrix, entryPointA, entryPointB, rows, columns);
  if(nonExistant == 1) 
  { 
    printf("Error! There is non existant path for a starting point (%d, %d) to the end of the matrix!\n", entryPointA, entryPointB); 
    system("PAUSE"); 
    return ; 
  } 
  
  if(head==NULL) 
  { 
    if(flagForFuncEntry == 0) // If we have not entered in recursion, the entry point is at the end of the matrix! 
	{    
      printf("The entry point is at the edge of matrix.\n"); 
      printf("(%d, ", entryPointA); 
      printf("%d);\n", entryPointB); 
    } 
    printf("The node is none existant!\n"); 
    system("PAUSE"); 
    return ;   
  } 
  else 
  { 
    struct Node* head_pointer = (struct Node *) malloc(sizeof(struct Node)); 
    head_pointer->pathCoordinateA = entryPointA; 
    head_pointer->pathCoordinateB = entryPointB; 
    head_pointer->next = head; 
    printf("BEGINNING to print out the path of the way out of the matrix:\n"); 
    while (head_pointer != NULL) 
    { 
      printf("(%d, ", head_pointer->pathCoordinateA); 
      printf("%d);\n", head_pointer->pathCoordinateB); 
      head_pointer = head_pointer->next; 
    } 
    printf("END\n"); 
  } 
  system("PAUSE"); 
  fclose(f); 
} 


