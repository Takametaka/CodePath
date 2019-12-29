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
    int n = N >> 1;
    for(int i = 0; i < n; i++)
        sp += T[i<<1];
    for(int i = 1; i < n; i++)
        si += T[i<<1];
    
    printf("pair \t:%d\n",sp);   
    printf("impair \t:%d\n",si);   
    return 0;
}
