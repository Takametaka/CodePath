#ifndef _LIST_H
#define _LIST_H

enum ope_s { ADD, SUB, DIV, MUL };
enum par_s { LEFT, RIGHT };

struct _token {
    enum type_s { ENT, OPE, PAR } m_type;
    union m_data { 
        int m_ent;
        enum ope_s m_ope;
        enum par_s m_par;
    } m_data;
};
typedef struct _token token_t;

token_t *create_token();

//LIST
struct _token_list {
    token_t *data;
    struct _token_list *next;
}; 
typedef struct _token_list token_list_t;

token_list_t *new_list(token_t *data);

token_list_t *add_start(token_list_t *list,token_t *data);

token_list_t *add_end(token_list_t *list,token_t *data);

void destroy_list(token_list_t *list);

void display_list(token_list_t *list);

//TREE
struct _token_tree {
    token_t *data;
    struct _token_tree *l;
    struct _token_tree *r;
};
typedef struct _token_tree token_tree_t;

#endif
