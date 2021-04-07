#include<stdio.h>
#include<string.h>


void swapp(char *a, char *b)
{
    char d = *a;
    *a = *b;
    *b = d;
}

int partition(char *A, int begin, int end)
{
    //begin and end are both inclusive
    char pivot = A[(begin + end) / 2];
    int i = begin - 1;
    int j = end + 1;
    
    while(1)
    {
        while (A[++i] < pivot);
        while (A[--j] > pivot);

        if(i >= j)
            return j;
        swapp(&A[i], &A[j]);
        //printf("%s\n", A);
    }
}

void Quick_sort(char *str, int begin, int end)
{
    if(begin < end)
    {
        int pivot_pos = partition(str, begin, end);
        Quick_sort(str, begin, pivot_pos);
        Quick_sort(str, pivot_pos + 1, end);
    }
}

void main()
{
    char r[] = "asdtcera";
    Quick_sort(r, 0, strlen(r)-1);
    printf("%s\n", r);
}