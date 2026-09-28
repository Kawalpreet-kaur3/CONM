// GAUSS ELIMINATION METHOD
#include <stdio.h>
#include <math.h>
#define max 50
// this means maximum size of matrix is 50 * 50

int main()
{

    int i, n, j, k;
    // i: rowloop, n:number of equations, j:column, k:elimination step

    float a[max][max + 1], x[max], sum, u;
    // the matrix can contain 50 rows and columns
    // elimination multiplies [sum used during back substritution]

    printf("\n Enter number of equations:");
    scanf("%d", &n);
    // the user enters for eg:3, n=3 [the programs will solve 3 equations with 3 unknowns]

    if (n <= 0 || n > max)
    {
        printf("\nInvalid number of equations");
        return 0;
    }

    // this take all the cofficients and R.H.S value
    for (i = 0; i < n; i++)
    {
        printf("\n Enter the coeff and R.H.S value for equation %d", i + 1);
        for (j = 0; j < n + 1; j++)
        // [j<n+1] n cofficients + 1 R.H.S(coff)

        {
            scanf("%f", &a[i][j]);
        }
    }
    // this takes all the cofficients and R.H.S value

    printf("contents of matrix are\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
            printf("\t%.3f", a[i][j]);
        printf("\n");
    }
    // %3f means the number will be printed 3 digits after the decimal point.

    for (k = 0; k < n - 1; k++)
    {
        if (a[k][k] == 0)
        {
            printf("\n division by zero");
            return 0;
        }
        for (i = k + 1; i < n; i++)
        {
            u = a[i][k] / a[k][k];
            for (j = 0; j < n + 1; j++)
                a[i][j] = a[i][j] - u * a[k][j];
        }
    }
    printf("upper triangle matrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
            printf("\t%.3f", a[i][j]);
        printf("\n");
    }
    for (i = n - 1; i >= 0; i--)
    {
        sum = 0;
        for (j = i + 1; j < n; j++)
            sum += a[i][j] * x[j];
        x[i] = (a[i][n] - sum) / a[i][i];
    }
    printf("\n solution of linear equation");
    for (i = 0; i < n; i++)
        printf("\n x[%d]=%.3f", i + 1, x[i]);

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
