#include <stdio.h>
#include <stdlib.h>

int * randTabint(int N, int K) {
	int *T = NULL;
	T = malloc(N*sizeof(int));
	if (T == NULL)
	{
		fprintf(stderr,"Failed to malloc");
		exit(EXIT_FAILURE);
	}
	
	int i;
	for (i = 0; i < N; i++)
	{
		T[i] = rand()%K;
	}
	
	return T;
}

int SumTabint(int *T, int N) {
	int S = 0;
	int i;
	for (i = 0; i < N; i++)
	{
		S = S + T[i];
	}
	
	return S;
}

int SumEvenTabint(int *T, int N) {
	int S = 0;
	int i;
	for (i = 0; i < N; i = i + 2)
	{
		S = S + T[i];
	}
	
	return S;
}

int SumUnevenTabint(int *T, int N) {
	int S = 0;
	int i;
	for (i = 1; i < N; i = i + 2)
	{
		S = S + T[i];
	}
	
	return S;
}

int main(int argc, char **argv)
{
	int S = 0;
	int *T = randTabint(1000,100);
	S = SumTabint(T,1000);
	fprintf(stdout,"Somme Totale \t\t= %d\n", S);
	
	S = SumEvenTabint(T,1000);
	fprintf(stdout,"Somme indices pair \t= %d\n", S);
	
	S = SumUnevenTabint(T,1000);
	fprintf(stdout,"Somme indices impair \t= %d\n", S);
	
	return 0;
}
