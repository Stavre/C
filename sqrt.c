#include<stdio.h>
#include<math.h>

double square_root(long double i)
{
    //calculating sqrt(i) using newton's method

    long double x = i/3; //initial estimation (not a very good one)
    long double y = -1;
    int j = 0;
    while (j < 51) //51 iterations
    {      
        x = 0.5*(x+((double)i)/x);   
        j = j+1;
    }
    return x;
}

int main()
{
    //code used for comparison with sqrtl
   /* 
    for(long double i = 1; i < 123456789; i++)
    {
        double a = square_root(i);
        double b = sqrtl(i);
        //keeping only the first ten digits
        a = a*10;
        a = trunc(a);
        a = a / 10;
        b = b * 10;
        b = trunc(b);
        b = b / 10;
        if (a!=b)
        {
            printf("i: %Lf\n",i);
            printf("%.17lf \n", a);
            printf("%.17lf \n", b);
        }
    }*/
    printf("%lf \n", square_root(9.36));

    return 0;
}
//compile with  gcc -o foo foo.c -lm 
