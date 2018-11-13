#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void longestWord(char * s) {
	char * Wo = NULL;
	Wo = malloc(64*sizeof(char)); if (Wo == NULL) exit(2);
	
	char * Lo = NULL;
	Lo = malloc(64*sizeof(char)); if (Lo == NULL) exit(2);
	
	int max = 0;
	while (sscanf(s,"%s",Wo) != EOF)
	{
		if (strlen(Wo) > max) 
		{
			strcpy(Lo, Wo);
			max = strlen(Wo);
		}
		
		s = &s[strlen(Wo) + 1];
	}
	printf("longest word : \"%s\" of size : %d\n",Lo, max);
}

int main(int argc, char **argv)
{
	char c[1000] = "For dessert what would you suggest to get the taste of the main course out of my mouth";
	
	longestWord(c);
	
	return 0;
}
