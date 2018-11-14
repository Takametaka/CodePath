#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(int argc, char **argv)
{
	
	if (argc != 3)
	{
		return 0;
	}
	
	randNum(atoi(argv[1]),atoi(argv[2]));
	
	FILE *F;
	F = fopen("tree.data","r+");
	if (F == NULL) exit(1);
	
	FILE *T;
	T = fopen("tree.dot","w+");
	if (T == NULL) exit(1);
	
	
	
	fprintf(T,"digraph tree{\n");
	fprintf(stdout,"graph tree{\n");
	
	Node Rt = NULL;
	Rt = createRoot();
	
	int i;
	
	while(fscanf(F,"%d",&i) != EOF) {
		scan_createChild(Rt,i);
	}
	
	drawDot(Rt,T);
	
	fprintf(T,"}\n");
	fprintf(stdout,"}\n");
	
	
	fclose(T);
	
	return 0;
}
