#include<stdio.h>
int binary_search(int e, int v[], int s, int d)
{
    int r = -1; //returns -1 if e is not found, else returns e's position
    if(s <= d)
    {
        int m = s + (d - s)/2;
        if (e == v[m])
            r = m;
        else if(e < v[m])
            r = binary_search(e, v, s, m-1);
        else if(e > v[m])
            r = binary_search(e, v, m+1, d);
    }
    return r;
}


int main()
{
    int v[] = {1,1,5,7, 8, 10, 100, 122, 203};
    printf("pos %i\n", binary_search( 1, v, 0, 8));
    return 0;
}