#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if(argc != 2) return 1;

    int fd = open(argv[1],O_RDONLY);
    if(fd == -1) return 1;

    //0x20 to 0x7E
    int freq[96] = {};
    
    char c;
    while(read(fd,&c,sizeof(char)))
        freq[(int)c - 0x20]++;
    
    for(int i = 0; i < 96; i++)
        printf("%c : %d\n",(char)(i + 0x20),freq[i]);
    
    close(fd);
    return 0;
}
