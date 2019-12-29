#include <stdio.h>
#include <stdint.h>
#define P 40
int main()
{
    uint64_t a = 1;
    uint64_t b = 1;
    uint64_t c = 0;
    int i = 0;
    while(i < P)
    {
        c = a + b;
        b = a;
        a = c;
        i++;
    }
    printf("phi = %f\n",(double)a/(double)b );
    return 0;
}
