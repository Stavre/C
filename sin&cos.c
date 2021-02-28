#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//rudimentary sin and cos implementation using Taylor polynomial 
//the trigonometric identities used are  sin(2x)=2sin(x)cos(x) cos(2x) = 1 - 2*(sin(x))^2
//  sin(30 + dif) = sin(30)cos(diff) + cos(30)sin(diff) cos(30 + dif) = cos(30)sin(diff) - sin(30)sin(diff)
// sin(60 + dif) = sin(60)cos(diff) + cos(60)sin(diff) cos(60 + dif) = cos(60)sin(diff) - sin(60)sin(diff) 
// *s and *c are pointers to the variables used to store sin and cos
int asincos(long double a, long double *s, long double *c)
{
    //x is expressed in degrees 
    const long double pi = 3.14159265358979323846264338327950288;  //storing pi
    int q = 1; // quadrant sin
    int p = 1; // quadrant cos
    int sign = 1; // sin(-x) = -sin(x)  
    
    sign = (a > 0) ? 1 : -1;
    a = (a > 0) ? a : -a; // a = abs(a)

    //sin(x + 2*K*pi) = sin(x) , K is a natural number
    //range reduction from [0, inf) to [0 , 2pi]
    while (a >= 360)
        a = a - 360;

    if (a == 0)
    {
        *s = 0;
        *c = 1;
        return 0;
    }
    if (a == 180)
    {
        *s = 0;
        *c = -1;
        return 0;
    }
    else if(a == 90)
    {
        *c = 0;
        *s = 1;
        return 0;
    }
    else if (a == 270)
    {
        *c = 0;
        *s = -1;
        return 0;
    }

    //setting quadrant and sin argument
    //range reduction from [0, 2*pi] to [0, pi/2]
    if (90 < a && a< 180)
    {
        q = 1;
        p = -1;
        a = 180 - a;
    }     
    else if (180 < a && a < 270)
    {
        q = -1;
        p = -1;
        a = a - 180;
    }      
    else if (270 < a && a < 360)
    {
        q = -1;
        p = 1;
        a = 360 - a;
    }      
    
   // long double x = a*0.0174532925199;
    long double x = a*(0.017453292519943295769236907684886127134);  //transformation from degrees to radians
    //0.0174532925199 = pi/180
    

    if (a < 30)
    {
        //Since sin(2x) = 2sin(x)cos(x) we need to compute sin(x/2) and cos(x/2)
        long double X = x /2;
        long double XX = X*X;
        long double XXX = XX*X;
        //Taylor polynomial for sin(X)
        long double S = (XXX*XXX*XXX - XXX*XXX*X*72 + XXX*XX*3024-XXX*60480 + X*362880) / 362880;

        //Taylor polynomial for cos(X)
        long double C = (XXX*XXX*XX - XXX*XXX*56 + XX*XX*1680 - XX*20160 + 40320) / 40320;
        *s = q*2*S*C; //sin(2x) = 2sin(x)cos(x)
        *c = p*(1- 2*(S)*(S)); //cos(2x) = 1 - 2*(sin(x))^2
   }
    else if (30 <= a && a < 60) // for angles between 30 and 60 degrees
    {
        //sin(30 + dif) = sin(30)cos(diff) + cos(30)sin(diff) = ((1+sqrt(3))/2)*(cos(diff) + sin(diff))
        //cos(30 + dif) = cos(30)sin(diff) - sin(30)sin(diff) = ((sqrt(3) - 1)/2)*(cos(diff) - sin(diff))
        long double X = (x - 0.523598775598298873077107230547); //30 degrees in radians
        // sqrt(3) = 1.73205080756887729352744634151
        long double XX = X*X;
        long double XXX = XX*X;
        //Taylor polynomial for sin(X)
        long double S = (XXX*XXX*XXX - XXX*XXX*X*72 + XXX*XX*3024-XXX*60480 + X*362880) / 362880;
 
        //Taylor polynomial for cos(X)
        long double C = (XXX*XXX*XX - XXX*XXX*56 + XX*XX*1680 - XX*20160 + 40320) / 40320;



        *s = q*(1.73205080756887729352744634151*S+C)/2; //((1+sqrt(3))/2)*(cos(diff) + sin(diff))
        *c = p*(1.73205080756887729352744634151*C-S)/2; //((sqrt(3) - 1)/2)*(cos(diff) - sin(diff))       
    }
    else if (60 <= a && a <= 90) // for angles between 60 and 90 degrees
    {
        //sin(60 + dif) = sin(60)cos(diff) + cos(60)sin(diff) = 
        //cos(60 + dif) = cos(60)sin(diff) - sin(60)sin(diff) 
        long double X = (x - 1.04719755119659774615421446109); //60 degrees in radians
        long double XX = X*X;
        long double XXX = XX*X;
        //Taylor polynomial for sin(X)
        long double S = (XXX*XXX*XXX - XXX*XXX*X*72 + XXX*XX*3024-XXX*60480 + X*362880) / 362880;

        //Taylor polynomial for cos(X)
        long double C = (XXX*XXX*XX - XXX*XXX*56 + XX*XX*1680 - XX*20160 + 40320) / 40320;
 
        *s = q*(S+1.73205080756887729352744634151*C)/2; 
        *c = p*(C-1.73205080756887729352744634151*S)/2;  
    }
    return 0;
}

int main()
{
    long double s;
    long double h;
    for (long double i = 0; i <=360; i = i + 0.5)
    {
        asincos(i, &s, &h);
        printf("%.14Lf\n",h);
    }
    return 0;
}