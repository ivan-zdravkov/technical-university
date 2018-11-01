// In a positive integer N, find all ordered representations of N, as the product of natural numbers. 
// Breaking is in lexicographical order

#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

int findRepresentations(int **A, int *B, int size, int g, int **Check, int N);
int CheckForRepeat(int *A, int **Check, int g, int size, int N);
void print(int **A, int fact, int Numbers, int N);
void quickSort(int A[], int start, int stop);
void ColumnSort(int **A, int g, int Numbers);

void main()
{
	int N = 0; // Entering N!
	while (N <= 0)
	{	
		printf("Enter N: ");
		scanf("%d", &N);
	}

	int i;
	int *Massive = (int*)malloc(sizeof(int)*N); // Inicializing Massive[N];
	for(i=0; i<N; i++)
		Massive[i] = 0;

	int temp = N;
	i = 2;
	while(i <= temp)
	{
		if(temp%i == 0)
		{
			temp /= i;
			Massive[i]++;
			i=1;
		}
		i++;	
	}

	int Numbers = 0;
	for(i=0; i<N; i++)
		Numbers += Massive[i]; //Initializing and Setting the number of prime numbers that form N

	if (Numbers==0) //A check weather N is a prime number
	{
		printf("\n\nTotal Numbers are 1 << %d >>", N); 
		printf("\n\n%d", N);
		getche();
		exit(0);
	}

	int k=0;
	int *Nums = (int*)malloc(sizeof(int)*Numbers); // Creating and filling the Prime Numbers in the array Nums[Numbers]
	for(i=0; i<N; i++)
	{
		if(Massive[i]!=0)
		{
			Nums[k]=i;
			k++;
			Massive[i]--;
			i=0;
		}
	}

	printf("\n\nTotal Prime Numbers are %d << ", Numbers); // Printing out the Prime Numbers
	for(i=0; i<Numbers; i++)
		printf("%d ", Nums[i]); 
	printf(">>"); 

	int fact = 1; // Initializing and Setting the facturiel of Numbers. // fact = Numbers!
	for(i=Numbers; i>1; i--)
		fact *= i;

	printf("\n\n%d! = %d\n",Numbers, fact);

	int **A = (int**)malloc(sizeof(*A)*fact); // Inicializing  A[Numbers!][Numbers]
		for(i=0; i<fact; i++)
			A[i] = (int*)malloc(Numbers*sizeof(int));
	for (i=0; i<fact; i++)
		for (int j=0; j<Numbers; j++)
			A[i][j] = N-1;

	int **Check = (int**)malloc(sizeof(*Check)*fact); // Initializing Check[fact][N].
		for(i=0; i<fact; i++)
			Check[i] = (int*)malloc(N*sizeof(int));
	for (i=0; i<fact; i++)
		for (int j=0; j<N; j++)
			Check[i][j] = 0;

	int g = findRepresentations(A, Nums, Numbers, 0, Check, N); // A counter for the rows in A[][]

	for(i=0; i<g; i++) // Sorting the rows of A
		quickSort(A[i], 0, Numbers-1);

	ColumnSort(A, g, Numbers-1); // Sorting the columns of A

	for(i=0; i<Numbers; i++) // Putting in A[][] the set of Prime Numbers of N.
		A[0][i] = Nums[i];

	
	printf("\ng = %d", g); // PRINTING OUT THE RESULTS !!!
	printf("\n\n");
	print(A, fact, Numbers, N); 
	printf("\n\n");

	getche();
}

void print(int **A, int fact, int Numbers, int N)
{
	for(int i=0; i<fact; i++)
	{
		if(A[i][0] == N-1 && A[i][1] == N-1)
			continue;
		for(int j=0; j<Numbers; j++)
			if(A[i][j]!=N-1)
				printf("%d ", A[i][j]);
		printf("\n");
	}
}

int CheckForRepeat(int *A, int **Check, int g, int size, int N)
{
	int i, j, count=0;
	for (i=0; i<g; i++)
	{
		for (j=0; j<size; j++)
		{			
			if(Check[i][A[j]]&&A[j]!=N-1)
				count++;
		}
		if(count == size-1)
			return 1;
		else
			count = 0;
	}
	for(j=0; j<size; j++)
	{	
		if(A[j]==N-1)
			continue;
		Check[g][A[j]] = 1;
	}
	return 0;
}

int findRepresentations(int **A, int *B, int size, int g, int **Check, int N)
{
	int k;
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			if(j!=i)
			{
				A[g][j] = B[i]*B[j];
				for(k=0; k<size; k++)
					if(k!=j&&k!=i)
						A[g][k] = B[k];
			}
			if(!CheckForRepeat(A[g], Check, g, size, N))
			{
				if(size==3)
					g++;
				else
				{
					g++;
					//g = findRepresentations(A, A[g], size-1, g++, Check, N);
				}
			}
			else 
				for(int v=0; v<size; v++)
					A[g][v] = N-1;
		}
	}
	return g;
}

void quickSort(int A[], int start, int stop)
{
	int i, j;
	i = start;
	j = stop;
	float m, k;
	m = A[(start + stop)/2];
	do
	{
		while(A[i] < m) i++;
		while(A[j] > m) j--;
		if (i <= j)
		{
			k = A[i];
			A[i] = A[j];
			A[j] = k;
			i++;
			j--;
		}
	}
	while(i <= j);
	if (j > start)
		quickSort(A, start, j);
	if (i < stop)
		quickSort(A, i, stop);
}

void ColumnSort(int **A, int g, int Numbers)
{
	int* p = (int*)A;
	int i,j;
	int hold;
	for(i = 0; i < ((Numbers * g)-1); i++)
	{
		for(j = i+1; j < (Numbers * g); j++)
		{
			if(p[i] < p[j])
			{
				hold = p[i];
				p[i] = p[j];
				p[j] = hold;
			}
		}
	}
}
