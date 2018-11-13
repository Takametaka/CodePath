#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node createRoot() { //créé un arbre vide
	Node N = NULL;
	N = malloc(sizeof(struct node));
	if (N == NULL)
	{
		return NULL;
	}
	N->g = N->d = NULL;
	N->val = NULL;
	return N;
}

int createChild(Node Nd,int i,FILE *T) { //ajoute i dans l'arbre recursivement
	
	if (Nd->val == NULL)
	{
		Nd->val = malloc(sizeof(int));
		if (Nd->val == NULL) return -1;
		*(Nd->val) = i;
		return 1;
	}
	
	
	if (i > *(Nd->val))
	{
		if (Nd->d == NULL)
		{
			Node D = createRoot();
			if (D == NULL)
			{
				return -1;
			}
			D->val = malloc(sizeof(int));
			if (D->val == NULL) return -1;
			*(D->val) = i;
			Nd->d = D;
			//~ printf("%d\n",Nd->d->val);
			fprintf(T,"\t%d--%d;\n",*(Nd->val),*(Nd->d->val));
			fprintf(stdout,"\t%d--%d;\n",*(Nd->val),*(Nd->d->val));
			return 1;
		}
		else
		{
			return createChild(Nd->d,i,T);
		}
		return -1;
	}
	
	if (i < *(Nd->val))
	{
		if (Nd->g == NULL)
		{
			Node G = createRoot();
			if (G == NULL)
			{
				return -1;
			}
			G->val = malloc(sizeof(int));
			if (G->val == NULL) return -1;
			*(G->val) = i;
			Nd->g = G;
			fprintf(T,"\t%d--%d;\n",*(Nd->val),*(G->val));
			fprintf(stdout,"\t%d--%d;\n",*(Nd->val),*(G->val));
			return 1;
		}
		else
		{
			return createChild(Nd->g,i,T);
		}
		return -1;
	}
	
	return 0;
}
