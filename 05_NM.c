// gauss jordan mathod
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
float f

(float x)
{
    return (x * x * x * x);
    // here f(x)=x power 4
}
void main()
{
    int n, i;
    float a, b, h, sum, intg;
    // a,b = limits of integration
    // n = number of trapezoids
    // h = width of each strip
    // sum = store sum inside brackets
    // intg = finial answer

    printf("\n Enter the value of a:");
    scanf("%f", &a);

    printf("\n Enter the value of b:");
    scanf("%f", &b);

    printf("\n Enter the value of n:");
    scanf("%d", &n);
    // takes a,b and n value from the user

    if (a > b)
    {
        printf("\n INVALID INPUT");
    }
    // if the lower limit(a) is greater than upper limit(b), it shows invalid

    h = (b - a) / n;
    // the trapezodial rule divide the interval [a,b] into n equal parts

    sum = f(a) + f(b);
    // the first and last terms are addes by once

    for (i = 1; i < n; i++)
    {
        sum = sum + 2 * f(a + (i * h));
        // calculate the intermidate value of x
    }
    intg = (h / 2) * sum;
    printf("\n integral %.4f", intg);
    // this applies the finial trapezodial formula
    // %.4f displays 4 digits after decimal points
}
