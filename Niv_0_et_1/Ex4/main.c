#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int premier(int N) {
	int i = N/2;
	printf("prem\n");
	while (i > 2)
	{
		if (N%i == 0)
		{
			return i;
		}
		i = i-1;
	}
	return 1;
}

int main(int argc, char **argv)
{
	int N = 0;
	N = atoi(argv[1]);

	int v = 0;
	if ((v = premier(N)) == 1)
	{
		printf("%d est premier\n",N);
	}
	else
	{
		printf("%d n'est pas premier car divisé par %d\n",N, v);
	}
	
	
	return 0;
}
