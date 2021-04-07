//Selection sort on string
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapp(char *a, char *b)
{
    char d = *a;
    *a = *b;
    *b = d;
}

void selectionsort(char *str)
{
    int minpos = 0;  
    int len = strlen(str);
    for (int index1 = 0; index1 < len; index1++)
    {
        minpos = index1;
        for (int index2 = index1; index2 < len; index2++)
            if (str[index2] < str[minpos])
                minpos = index2;
        swapp(&str[index1], &str[minpos]);
    }
}

int main()
{
    char r[] = "vvsabcdw";
    selectionsort(r);
    printf("sorted %s\n", r);
    
    
    return(0);


}