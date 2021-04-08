#include<stdio.h>

void checkboard(char m[8][8], int x, int y)  //auxiliary function for creating checkboard
{
    if ((x + y)%2 == 0)
       m[x][y] = '_';
    else
        m[x][y] = '#';
}

void print_board(char m[8][8])  //auxiliary function for printing solution
{
    for(int x = 0; x < 8; x++)
    {
        for(int y = 0; y < 8; y++)
            printf("%c ", m[x][y]);
        printf("\n");
    }
}

void set_board(char m[8][8])  //auxiliary function for setting checkboard
{
    for(int x = 0; x < 8; x++)
        for(int y = 0; y < 8; y++)
            checkboard(m, x, y);
}

int check(char m[8][8], int x, int y)  //checks if queen can be placed at (x, y)
{
    int r = 0;
    //check line
    for(int i = 0; i < 8; i++)
        if(m[i][y] == 'Q')
            r = 1;
    //check column
    for(int i = 0; i < 8; i++)
        if(m[x][i] == 'Q')
            r = 1;
    //check first diagonal
    for(int xx = x, yy = y; xx<8 && yy<8; xx++, yy++)
        if(m[xx][yy] == 'Q')
            r = 1;
    for(int xx = x, yy = y; xx>=0 && yy>=0; xx--, yy--)
        if(m[xx][yy] == 'Q')
            r = 1;
    //check second diagonal
    for(int xx = x, yy = y; xx>=0 && yy<8; xx--, yy++)
        if(m[xx][yy] == 'Q')
            r = 1;
    for(int xx = x, yy = y; xx<8 && yy>=0; xx++, yy--)
        if(m[xx][yy] == 'Q')
            r = 1;
    return r;
}

int queens(char m[8][8], int line)  
{
    int r = 1;
    if (line == 8)
    {
        //base case. If line equals 8 then the board has a queen on each row.
        printf("\nSolution:\n");
        print_board(m); //Prints soluntion
        r = 0;
    }      
    else
    {
        for(int x = 0; x < 8; x++)  //iterate through the columns
        {
            if(check(m,x, line) == 0)  //checks position
            {
                (m[x][line]) = 'Q';  //sets queen
                r = queens(m, line+1);  //recursive call on 
                checkboard(m, x, line); //removes queen and moves on to the next column
            }
        }
    }
    return r;
}

int main()
{
    char k[8][8];
    set_board(k);
    queens(k, 0);
    return 0;
}