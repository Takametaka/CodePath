#define N 256
#define K 128

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int T[N];
    for(int i = 0; i < N; i++)
        T[i] = rand()%K;

    int sp = 0;
    int si = 0;
    for(int i = 0; i < N; i+=2)
        sp += T[i];
    for(int i = 1; i < N; i+=2)
        si += T[i];
    
    printf("pair \t:%d\n",sp);   
    printf("impair \t:%d\n",si);   
    return 0;
}
