#define N 256
#define K 128

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int T[N];
    for(int i = 0; i < N; i++)
        T[i] = rand()%K;

    int s = 0;
    for(int i = 0; i < N; i++)
        s += T[i];
    
    printf("%d\n",s);   
    return 0;
}
