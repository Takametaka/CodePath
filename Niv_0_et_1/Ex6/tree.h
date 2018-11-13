
struct node {
	int *val;
	struct node *g;
	struct node *d;
};
typedef struct node* Node;

Node createRoot(); //créé un arbre vide
int createChild(Node Nd,int i,FILE *T); //ajoute i dans l'arbre recursivement
