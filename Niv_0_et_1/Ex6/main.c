#include <stdio.h>
#include <stdlib.h>

struct _abr {
    int data;
    struct _abr *d; //supp
    struct _abr *g; //inf
};
typedef struct _abr abr_t;

//return 1 -> wrong number of arguments
//return 2 -> failed to read input file
//return 3 -> failed to allocate tree node
int main(int argc, char **argv)
{   
    if(argc != 2) exit(1);
    FILE *fstr = fopen(argv[1],"r");
    if(fstr == NULL) exit(2);
    
    int input;
   abr_t *root = NULL; 
    while(fscanf(fstr,"%d\n",&input) != EOF)
    {
        root = pushAbr(root,input);
        //continue here
    }
    fclose(fstr);
    return 0;
}

abr_t *newAbr(int data)
{
    abr_t *Node = (abt_t *)malloc(sizeof(struct _abr));
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
    else if(root->data >= data)
        root->d = pushAbr(root->d,data);
    else if(root->data < data)
        root->g = pushAbr(root->g,data);
    return root;
}
