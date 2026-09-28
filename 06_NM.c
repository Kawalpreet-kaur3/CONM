// GAUSS JORDAN METHOD
#include <stdio.h>
#include <math.h>
#define max 50
// program can make arrays with the maximum size of 50

int main()
{

    int i, n, j, k;
    // i: row, n:number of equations, j:column, k:pivot number

    float a[max][max], x[max], sum, u, temp;
    // this is main matrix[it store the agumented matrix, i.e coeff + R.H.S value]

    printf("\n Enter number of equations:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    // run once for every equation
    {
        printf("\n Enter the coeff and R.H.S value for equation %d", i + 1);
        for (j = 0; j < n + 1; j++)
        // bcz there are n coeff + 1 R.H.S value

        {
            scanf("%f", &a[i][j]);
            // the user enters each value as a floating point number
        }
    }

    printf("contents of matrix are\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
            // it will only display coefficient but not R.H.S
            printf("\t%.3f", a[i][j]);
        printf("\n");
    }
    // this displays the matrix

    for (k = 0; k < n; k++)
    // current pivot element (k=0) pivot is a[0][0]
    {
        if (a[k][k] == 0)
        {
            printf("\n division by zero");
            return 0;
        }
        temp = a[k][k];
        //the currect pivot is shored in temp
        for (j = k; j < n + 1; j++)
            // this is the most important step. the entire pivot is divided by the pivot
            a[k][j] = a[k][j] / temp;
        for (i = 0; i < n; i++)
        // the purpose is to make the entire enteries in pivot collumn is equal to 0
        {
            if (i != k)
            {
                u = a[i][k];
                for (j = k; j < n + 1; j++)
                    a[i][j] = a[i][j] - u * a[k][j];
                    // stores the value that we want to elimate
            }
        }
    }

    printf("\n solution of linear equation");
    // it will display the output
    for (i = 0; i < n; i++)
    {
        x[i] = a[i][n];
        // in this program a[10][10] is a arugmented matrix
        printf("\n x[%d]=%.3f", i + 1, x[i]);
    }

    return 0;
}
// k identifies pivot row/column
// for n=3
// k=0
// k=1
// there is not need for k=2 because after eliminating 2nd row, matrix is already triangular.

// it is a numerical method used to solve a system of equation
// for example:
// a1x + b1y + c1z = d1
// a2x + b2y + c2z = d2
// a3x + b3y + c3z = d3

// this method has 2 stages: forward eliminations and backward elimination
