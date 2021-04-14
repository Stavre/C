#include<stdio.h>
#include<stdlib.h>

void irreducible_fraction(unsigned long *x, unsigned long *y)
{
    for(int i = 2; i < (*x); i++)
    {
        while((*x)%i==0 && (*y)%i==0)
        {
            (*x) = (*x)/i;
            (*y) = (*y)/i;
        }
    }
} 

void printEgyptian(unsigned long x, unsigned long y)
{
    if(x == 0 || y == 0)
        printf("\n");
  
    else if (y%x==0)
        printf("1/%lu ", y/x);
    else
    {
        unsigned long n = y / x + 1;
        printf("%i/%lu + ", 1, n);
        unsigned long X = x*n;
        unsigned long Y = y*n;

        if(X / n != x || Y / n != y)  //check for overflow
        {
            printf("Overflow\n");
            return;
        }
        X = X - y;
        irreducible_fraction(&X, &Y);
        printEgyptian(X, Y);  
    }
}

int main()
{
    printEgyptian(4,11);
    return 0;
}