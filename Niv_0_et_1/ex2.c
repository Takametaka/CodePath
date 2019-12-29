#include <stdio.h>
#define is_letter(C) ( ((C) >= 'a' && (C) <= 'z') || ((C) >= 'A' && (C) <= 'Z') )
int main()
{
    char *str = "Pellentesque accumsan tempus congue. Suspendisse pellentesques sem pretium dolor tincidunt gravida. Suspendissenonfacilisis dui, in elementum magna. Nam a tincidunt ante. Praesent ut massa ligula. Sed tincidunt dolor augue, id vestibulum.";
    char *ptr = str;
    char ret[max];
    int currIndex = 0;
    int fromIndex = 0;
    int currWord = 0;
    int max = 0;

    while(*ptr != '\0')
    {   
        if(is_letter(*ptr))
            currWord++;
        else 
        {
            if(currWord > max)
            {
                max = currWord;
                fromIndex = (currIndex - currWord);
            }
            currWord = 0;
        }
        currIndex++;
        ptr++;
    }
    for(int i = 0; i < max; i++)
        ret[i] = *(str + i + fromIndex);

    printf("%d\n",max);
    printf("%s\n",ret);
    return 0;
}
