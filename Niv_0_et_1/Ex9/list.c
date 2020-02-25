#include <stdio.h>
#include <stdlib.h>
#include "list.h"

token_t *create_token()
{
    token_t *tok = (token_t *)malloc(sizeof(token_t));
    if(tok == NULL)
    {
        fprintf(stderr,"Erreur de malloc dans la creation d'un token\n");
        exit(1);
    }
    return tok;
}

//LIST
token_list_t *new_list(token_t *data)
{
    token_list_t *list = (token_list_t *)malloc(sizeof(token_list_t));
    if(list == NULL)
    {
        fprintf(stderr,"Erreur de malloc dans la creation de la liste\n");
        exit(1);
    }
    list->data = data;
    list->next = NULL;
    return list;
}

token_list_t *add_start(token_list_t *list,token_t *data)
{
    token_list_t *tmp = new_list(data);
    tmp->next = list;
    return tmp;
}

token_list_t *add_end(token_list_t *list,token_t *data)
{
    if(list == NULL) return new_list(data);
    token_list_t *head = list;
    token_list_t *tmp = list;
    while(tmp != NULL) 
    {
        list = tmp;
        tmp = tmp->next;
    }
    list->next = new_list(data);
    //Pas obligatoire mais pour la consistance
    return head;
}

void destroy_list(token_list_t *list)
{
    token_list_t *tmp = list;
    while(list != NULL)
    {
        tmp = list->next;
        free(list->data);
        free(list);
        list = tmp;
    }
}

void display_list(token_list_t *list)
{
    printf("### LIST ###\n");
    while(list != NULL)
    {
        printf("[");
        if(list->data->m_type == OPE)
        {
            switch(list->data->m_data.m_ope)
            {
                case ADD : printf("+"); break;
                case SUB : printf("-"); break;
                case MUL : printf("*"); break;
                case DIV : printf("/"); break;
            }
        } 
        else if(list->data->m_type == PAR)
        {
            switch(list->data->m_data.m_par)
            {
                case LEFT : printf("("); break;
                case RIGHT : printf(")"); break;
            }
        }
        else
        {
            printf("%d",list->data->m_data.m_ent);
        }
        printf("]");
        list = list->next;
    }
    printf("\n");
}
