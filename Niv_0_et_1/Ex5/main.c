#include <stdio.h>
#include <stdlib.h>

double phi(int N) {
	long long a = 1;
	long long b = 1;
	long long i = 0;
	long long tmp = 0;
	double fi = 0.0;
	while (i < N)
	{
		tmp = a;
		a = a + b;
		b = tmp;
		fi = (double) a/b;
		printf("%f\n",fi);
		i++;
	}
	
	return fi;
}

int main(int argc, char **argv)
{
	
	printf("Phi approximé est %f\n", phi(40));
	
	return 0;
}
