//insertion sort for strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swapp(char *a, char *b)
{
    char d = *a;
    *a = *b;
    *b = d;
}

void insertionsort(char *str)
{
    int len = strlen(str);
    
    for(int index1 = 0; index1 < len; index1++)
    {
        for(int index2 = index1; index2 > 0; index2--)
        {
            if (str[index2] < str[index2 - 1])
            {
                swapp(&str[index2] ,&str[index2 - 1]);
            }
        }
    }
}

int main()
{
    char r[10] = "bcdqqda";
    insertionsort(r);
    printf("%s\n", r);
    return(0);
}