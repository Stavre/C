#include<stdio.h>
#include<stdlib.h>

//Implementation of counting sort used for sorting arrays of digits only

int *Counting_Sort(int *arr, int l)
{
    int *output = (int*)calloc(l, sizeof(int));
    int frequency[10] = {0}; //frequency vector

    for (int i = 0; i < l; ++i )
        ++frequency[arr[i]];

    for (int i = 1; i < 10; ++i )
        frequency[i] += frequency[i-1];

    for (int i = 0; i < l; i++)
    {
        output[frequency[arr[i]] - 1] = arr[i];
        frequency[arr[i]]--;
    }

    return output;
}

void main()
{
    int l = 5;
    int *t = (int*)malloc(l * sizeof(int));

    for(int i = 0; i < l; i++)
        scanf("%i", &t[i]);
    printf("\n");
    
    int *o = (int*)malloc(l * sizeof(int));
    o = Counting_Sort(t, l);
    for(int i = 0; i < l; i++)
        printf("%i ", o[i]);
    printf("\n");
}