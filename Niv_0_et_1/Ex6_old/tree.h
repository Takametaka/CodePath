
struct node {
	int val;
	struct node *p;
	struct node *g;
	struct node *d;
};
typedef struct node* Node;

Node createRoot(); //créé un arbre vide
void createChild(Node Nd,int i,int pos); //ajoute i dans l'arbre recursivement
void scan_createChild(Node Nd, int i);
void drawDot(Node Rt, FILE *T);
void randNum(int n,int k);
