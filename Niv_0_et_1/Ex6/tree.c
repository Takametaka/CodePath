#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "tree.h"

void randNum(int n,int k) {
	FILE *F1 = NULL;
	F1 = fopen("tree.data","wr");
	if (F1 == NULL)
	{
		fprintf(stderr,"FAILED TO OPEN F1\n");
		exit(EXIT_FAILURE);
	}
	
	int i2;
	srand( getpid() );
	for (i2 = 0; i2 < n; i2++)
	{
		fprintf(F1,"%d ",rand()%k);
	}
	fclose(F1);
}

Node createRoot() { //créé un arbre vide
	Node N = NULL;
	N = malloc(sizeof(struct node));
	if (N == NULL)
	{
		return NULL;
	}
	N->g = N->d = NULL;
	return N;
}

void createChild(Node Nd,int i,int pos) { //appel ex : creatChild(Nd,i,0) pos = 0 -> g pos = 1 -> d
	
	if (pos == 0)
	{
		Nd->g = createRoot();
		Nd->g->val = i;
		Nd->g->p = Nd;
	}
	
	if (pos == 1)
	{
		Nd->d = createRoot();
		Nd->d->val = i;
		Nd->d->p = Nd;
	}
	
}

void scan_createChild(Node Nd, int i) {
	
	if (i < Nd->val)
	{
		if (Nd->g == NULL)
		{
			createChild(Nd,i,0);
		}
		else
		{
			scan_createChild(Nd->g,i);
		}
		return;
	}
	if (i > Nd->val)
	{
		if (Nd->d == NULL)
		{
			createChild(Nd,i,1);
		}
		else
		{
			scan_createChild(Nd->d,i);
		}
		return;
	}
	if (i == Nd->val)
	{
		return;
	}
}



void drawDot(Node Rt, FILE *T) {
	
	if (Rt == NULL)
	{
		return;
	}
	if (Rt->p != NULL)
	{
		fprintf(T,"%d->%d\n",Rt->p->val,Rt->val);
		fprintf(stdout,"%d->%d\n",Rt->p->val,Rt->val);
	}
	
	drawDot(Rt->g,T);
	
	drawDot(Rt->d,T);
}
