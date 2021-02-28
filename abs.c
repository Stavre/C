//implementations of abs function using bitwise operations and if conditional statement
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int abs_bit(int n)  //bitwise implementation
{
    int a = n >> 31;
    n = n^a;
    n = n + (a&1);
    return n;
}

int abs_if(int a)  //if implementation
{
    if (a < 0)
        return -a;
    return a;
}
int main()  //comparison bbetween the two implementation and C's abs function
{
    clock_t start, stop;  //start and stop
    long double elapsed, ab, abs_b, abs_i; 
    //elapsed = function running time
    // ab = abs total running time
    // abs_b = abs_bit total running time
    // abs_i = abs_if total running time
    int num = 0; // stores random number
    int a, b, c, errors;
    //a = abs(num);
    //b = abs_bit(num);
    //c = abs_if(num);
    //errors = number of errors;
    ab = 0;
    abs_b = 0;
    abs_i = 0;
    int iter = 10; //number of iterations
    for (int i = 0; i < iter ; i++)
    {
        srand(time(0));  // seed
        num = (rand() % (1000 - (-1000) + 1)) + (-1000); //generate random number between -1000 and 1000


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
