// simson's 3/8 rule
#include <stdio.h>
#include <stdlib.h>
float f(float x)
{
    return (1 / (1 + (x * x)));
    // 1/(1+2x)
}
int main()
{
    int n, i;
    float a, b, sum, h, intg;
    printf("\n Enter the value of a:");
    scanf("%f", &a);

    printf("\n Enter the value of b:");
    scanf("%f", &b);

    printf("\n Enter the value of n:");
    scanf("%d", &n);

    h = (b - a) / n;
    sum = f(a) + f(b);
    for (i = 1; i < n; i++)
    {
        if (i % 3 == 0)
            // check wheather (i) is a multiple of 3

            sum = sum + 2 * f(a + (i * h));
        // if (i) is divisible by 3, the function value get a weight of 2

        else
            sum = sum + 3 * f(a + (i * h));
    }
    intg = ((3 * h) / 8) * sum;
    printf("\n Integral %.4f", intg);

    return 0;
}