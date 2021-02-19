#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int abs_bit(int n)
{
    int a = n >> 31;
    n = n^a;
    n = n + (a&1);
    return n;
}

int abs_if(int a)
{
    if (a < 0)
        return -a;
    return a;
}
int main()
{
    clock_t start, stop;
    long double elapsed, ab, abs_b, abs_i;
    int num = 0;
    int a, b, c, errors;
    ab = 0;
    abs_b = 0;
    abs_i = 0;
    int iter = 10;
    for (int i = 0; i < iter ; i++)
    {
        srand(time(0)); 
        num = (rand() % (1000 - (-1000) + 1)) + (-1000);


        start = clock();
        a = abs(num);
        stop = clock();
        elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
        ab = ab + elapsed;

        start = clock();
        b = abs_bit(num);
        stop = clock();
        elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
        abs_b = abs_b + elapsed;

        start = clock();
        c = abs_if(num);
        stop = clock();
        elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
        abs_i = abs_i + elapsed;

        if (a != b || a !=c)
            errors++;
    }
   
    printf("Errors %i Average abs %Lf  Average abs_bit %Lf average abs_if %Lf\n",errors, ab/iter, abs_b/iter, abs_i/iter);

    return 0;
}
