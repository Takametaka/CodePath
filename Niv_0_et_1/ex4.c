#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if(argc != 2) return 1;
    int n = atoi(argv[1]);
    
    //de 2 a sqrt(n)
    for(int i = 2; i*i <= n; i++)
        if(n%i == 0)
            return 1;

    printf("premier !\n");
    return 0;
}
