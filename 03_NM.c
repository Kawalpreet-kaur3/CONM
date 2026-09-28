// SIMPSON 1/8 RULE : all correct
#include <stdio.h>
#include <stdlib.h>
float f(float x)
{
    return (1 / (4 * x + 5));
}

// whenever f(2) it will return f(x)=1/(4x+5) eg.f(1) = 1/(4(1)+5) = 1/9 = 0.1111

void main()
{
    int n, i;
    // i loop counter
    float a, b, h, sum, intg;

    printf("\n Enter the value of a:");
    scanf("%f", &a);

    printf("\n Enter the value of b:");
    scanf("%f", &b);
    // user to enter lower and upper limit, for simpon rule n must be zero

    printf("\n Enter the value of n:");
    scanf("%d", &n);

    if (n <= 0 || n % 3 != 0)
    {
        printf("\n n must be a positive multiple of 3 for Simpson's 3/8 rule");
        return 0;
    }

    if (a > b)
    {
        printf("\n invaild input");
        exit(0);
    }

    h = (b - a) / n;
    // a = 1, b = 3, n = 4
    sum = f(a) + f(b);
    // f(1) = 1/9 ,f(2) = 1/13, sum = 1/9 + 1/13, f(x0) + f(x4)

    for (i = 1; i < n; i++)
    {
        if (i % 2 == 0)
            // check whether the remainder when i is divided by 2 is 0

            sum = sum + 2 * f(a + (i * h));
        else
            sum = sum + 4 * f(a + (i * h));
    }
    // this calculate the function value at current point the x-cooridinate is x1 =

    intg = (h / 3) * sum;
    printf("\n integer %.4f", intg);
}
// if (i) is even then it is multiply by 2
// if (i) is odd then it is multiply by 4
