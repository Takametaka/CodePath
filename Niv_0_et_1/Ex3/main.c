#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *F = NULL;
	
	F = fopen(argv[1],"r");
	if (F == NULL) exit(EXIT_FAILURE);
	char a;
	
	int *ASCII = NULL;
	ASCII = malloc(128*sizeof(int));
	if (ASCII == NULL) exit(2);
	
	int i;
	for (i = 0; i < 128; i++)
	{
		ASCII[i] = 0;
	}
	
	int s;
	
	while (fscanf(F,"%c",&a) != EOF)
	{
		s = (int)a;  
		ASCII[s] = ASCII[s] + 1;
	}
	
	int i2,j;
	for (i2 = 10; i2 < 129/3; i2++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%3d : %1c : %3d  |  ",i2*3 + j,i2*3 + j,ASCII[i2*3 + j]);
		}
		printf("\n");
	}
	return 0;
}
