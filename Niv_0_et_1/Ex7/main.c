#include <stdio.h>
#include <stdlib.h>

struct _abr {
    int data;
    struct _abr *d; //supp
    struct _abr *g; //inf
};
typedef struct _abr abr_t;

abr_t *newAbr(int data)
{
    abr_t *Node = (abr_t *)malloc(sizeof(struct _abr));
    if(Node == NULL) exit(3);
    Node->data = data;
    Node->d = NULL;
    Node->g = NULL;
    return Node;
}

//returns the root of the tree with the data added 
abr_t *pushAbr(abr_t *root,int data)
{
    if(root == NULL)
        return newAbr(data);
    
    if(root->data < data)
        root->d = pushAbr(root->d,data);
    else if(root->data > data)
        root->g = pushAbr(root->g,data);

    return root;
}

void destroyAbr(abr_t *root)
{
    if(root == NULL) return;
    abr_t *g = root->g;
    abr_t *d = root->d;
    free(root);
    destroyAbr(g);
    destroyAbr(d);
}

void scanAbr(abr_t *root,FILE *dot)
{
    if(root == NULL) return;
    if(root->d != NULL) 
    {
        if(root->data != root->d->data)
        {
            fprintf(dot,"%d--%d\n",root->data,root->d->data);
            scanAbr(root->d,dot);
        }
    }
    if(root->g != NULL) 
    {
        if(root->data != root->g->data)
        {
            fprintf(dot,"%d--%d\n",root->data,root->g->data);
            scanAbr(root->g,dot);
        }
    }
}

int searchAbr(abr_t *root,int toFind)
{
    if(root == NULL)
        return 0;
    if(root->data == toFind)
        return 1;
    else 
    {
        if(root->data > toFind)
            return searchAbr(root->g,toFind);
        if(root->data < toFind)
            return searchAbr(root->d,toFind);
    }
    return 0;
}

//return 1 -> wrong number of arguments
//return 2 -> failed to open file
//return 3 -> failed to allocate tree node
int main(int argc, char **argv)
{   
    if(argc != 3) exit(1);
    FILE *fstr = fopen(argv[1],"r");
    if(fstr == NULL) exit(2);
    
    FILE *dot = fopen("tree.dot","w");
    if(dot == NULL) exit(2);

    int input;
    abr_t *root = NULL; 
    //make tree
    while(fscanf(fstr,"%d\n",&input) != EOF)
        root = pushAbr(root,input);
    
    //scan tree
    fprintf(dot,"graph tree {\n");
    scanAbr(root,dot);

    //find argv[2] in tree
    int toFind = atoi(argv[2]);
    int ret = searchAbr(root,toFind);
printf("%d returned %d\n",toFind, ret);
    if(ret)
        fprintf(dot,"%d [style=filled, fillcolor=red]\n",toFind);

    fprintf(dot,"}\n");

    destroyAbr(root);
    fclose(dot);
    fclose(fstr);
    return 0;
}
