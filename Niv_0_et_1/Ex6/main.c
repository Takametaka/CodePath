#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(int argc, char **argv)
{
	FILE *F;
	F = fopen("tree.data","r+");
	if (F == NULL) exit(1);
	
	FILE *T;
	T = fopen("tree.dot","w+");
	if (T == NULL) exit(1);
	
	fprintf(T,"graph tree{\nrankdir=LR;\n");
	fprintf(stdout,"graph tree{\n");
	
	Node Rt = NULL;
	Rt = createRoot();
	
	int *i = NULL;
	i = malloc(sizeof(int));
	if (i == NULL) exit(2);
	
	while(fscanf(F,"%d",i) != EOF) {
		if(createChild(Rt,*i,T) == -1)
		{
			exit(EXIT_FAILURE);
		}
	}
	
	
	fprintf(T,"}\n");
	fprintf(stdout,"}\n");
	
	return 0;
}
