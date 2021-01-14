#include<stdlib.h>
#include <stdio.h>
#include <math.h>
//computes e precisely until the 18th decimal place
//computer the first 20 powers of e with an accuracy of at least six decimal places
long double e(long double x)
{
   
    long double E = 1 + x; // the first two terms of the taylor series for e^x in x=0

    int f = 2;
    long double c = 0.0;
    long double y = 0;
    long double t = 0;
    long double term = (x*x)/2; //the term to be added to the sum
    while (f < 2500)
    {
       // printf("%i  %Lf %Lf  %Lf  \n", f, factorial,x, x/factorial);
        //Ep = E;
        //using kahan's summation algorithm
        y = term - c;
        t = E + y;
        c = ( t - E) - y;
        E = t;
  
        //calculates the next term to be added to the sum
        //instead of calculating every time n! and x^n it multiplies term with x(creating x^n) and divides term by(creating x^n/n!)
        term = term*x;
        f = f + 1;
        term = term/f;
    }

    return E;
}


int main() //driver code
{
    for(int i = 1; i < 31; i++)
    {
        printf("%i %.6Lf \n",i, e(i));
        printf("%i %f \n",i, pow(M_E,i)); //comparison with pow
    }
    return 0;
}