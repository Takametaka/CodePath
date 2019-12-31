#include <stdio.h>
#include <stdlib.h>

int isCorrect(char *str)
{
    int count = 0;
    while(*str != '\0')
    {   
        if(*str == '(')
            count++;
        else if(*str == ')')
            count--;
        
        if(count < 0)
            return 0;

        str++;
    }
    if(count != 0)
        return 0;
    return 1;
}

int main(int argc, char **argv)
{
    if(argc != 2) exit(1);
    if( isCorrect(argv[1]) )
        printf("correct\n");
    else 
        printf("uncorrect\n");
}
