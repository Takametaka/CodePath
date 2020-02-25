#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

//return 1 si l'expression est bien parenthésée 0 sinon
int isCorrect(char *str);

token_list_t *lex(char *str);

//MAIN
int main(int argc, char **argv)
{
    if(argc != 2) 
    {
        fprintf(stderr,"Mauvais nombre d'arguments\n");
        exit(1);
    }
    if(!isCorrect(argv[1]) )
    {
        fprintf(stderr,"Mauvais Parenthesage de l'expression\n");
        exit(1);
    }
    token_list_t *tokenList = lex(argv[1]);
    display_list(tokenList);
    destroy_list(tokenList);
    return 0;
}

int isCorrect(char *str)
{
    int cnt = 0;
    while(*str != '\0')
    {
        if(*str == '(') cnt++;
        else if (*str == ')') cnt--;
        if(cnt < 0) return 0;
        str++;
    }
    if(cnt != 0) return 0;
    return 1;
}

token_list_t *lex(char *str)
{
    token_list_t *list = NULL;

    while(*str != '\0')
    {
        token_t *tok = create_token();
        //isInt ?
        if(*str >= 0x30 && *str <= 0x39)
        {
            int n = *str - 0x30;
            str++;
            while(*str >= 0x30 && *str <= 0x39)
            {   
                n *= 10;
                n += *str - 0x30;
                str++;
            }
            tok->m_type = ENT;
            tok->m_data.m_ent = n;
            str--; //decallé d'un cran en trop pour detecter la fin de l'entier
        }
        else switch(*str)
        {
            case '+' : 
                tok->m_type = OPE;
                tok->m_data.m_ope = ADD;
                break;
            case '-' :
                tok->m_type = OPE;
                tok->m_data.m_ope = SUB;
                break;
            case '*' :
                tok->m_type = OPE;
                tok->m_data.m_ope = MUL;
                break;
            case '/' :
                tok->m_type = OPE;
                tok->m_data.m_ope = DIV;
                break;
            case '(' :
                tok->m_type = PAR;
                tok->m_data.m_par = LEFT;
                break;
            case ')' :
                tok->m_type = PAR;
                tok->m_data.m_par = RIGHT;
                break;
            default :
                tok->m_type = ENT;
                tok->m_data.m_ent = 0;
        }
        list = add_end(list,tok);
        str++;
    }
    return list;
}
