#include<stdlib.h>
#include<stdio.h>
#include<float.h>
typedef struct 
{
    float s; //root of equation
    char t; //root status
    // t = '0'  root doesn't exist in the given interval
    //t = '1'  approximation of the root
    //t = '2'  the exact root
} solution;


float equation(float x)
{
    //return x*x*x*x*x*x*x*x*x*x*x*x*x*x - 4;
    return 2.71828182846 - x*x*x - x*x*x*x; //this is f(x); f is a function; x is a root if f(x) = 0
}
float absolut(float x , float (*p)(float x))
{
    float y = p(x);
    return ( y >=0 ? y : -y );
}

solution bisect(float X_left, float X_right, float epsilon, float (*p)(float x) )
{
    //searching for a root inside interval [X_left, X_right]
    solution r;
    float pd; //store past iteration's (X_right - X_left) value
    int i = 1; //stores number of iterations;
    if (epsilon < FLT_MIN)
        epsilon = FLT_MIN;  //forces epsilon to the smallest value a float can handle
    if (X_right - X_left < epsilon)
    {
        printf("Accuracy cannot be guaranteed \n");
    }
    
    if ( p(X_left) * p(X_right) > 0) 
    {
        printf("Either there is no root in this interval, or there are 2*n roots, n is a natural number\n");
        r.t = '0';
        r.s = -1;
    }
    //checking if the interval's margins are roots
    else if ( p(X_left) == 0)
    {
        r.t = '2';
        r.s = X_left;
    }
    else if ( p(X_right) == 0)
    {
        r.t = '2';
        r.s = X_right;
    }
    else
    {
        r.s = (X_right + X_left) / 2;
        printf("iteration no. %i X_right %f  approx. %f  p(x) %f X_left %f \n", i, X_right, r.s, p(r.s), X_left);
        i++;
        // (p(r.s) >= 0) ? p(r.s) : -p(r.s) = fabs(p(r.s))
        //in case of underflow X_right - X_left will be very close to 0 and  
        //(X_right + X_left) / 2 will become irrelevant
        //pd != (X_right - X_left) stops the algorithm when underflow occurs
        while (  absolut(r.s, equation) > epsilon && pd != (X_right - X_left) )
        {
            pd = X_right - X_left; 
            if (p(X_left) * p(r.s) < 0)
                X_right = r.s;     // root is in the left half of the interval
            else
                X_left = r.s;      // root is in the right half of the interval
            
            r.s = (X_right + X_left) / 2;  
            printf("iteration no. %i X_right %f  approx. %f  p(x) %f X_left %f \n", i, X_right, r.s, p(r.s), X_left);
            i++;
        }
    }
    if (p(r.s) == 0) //if r.s is the exact root
        r.t = '2';
    else             //if r.s is the approximation of the root
        r.t = '1';
    return r;
}


int main()
{ 
    solution sol;

    sol = bisect(0 ,10, 11 , equation);
    printf("cod %c \nsol %f \n", sol.t, sol.s);
    return 0;
}