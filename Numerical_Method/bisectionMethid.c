#include <stdio.h>
#include <math.h>
#define EPS 0.000001

float f(float x)
{
    return x * x * x - 2 * sin(x);
}

int main(void)
{
    float a, b, c;
    int n = 0;
    do
    {
        printf("Enter value of a: ");
        printf("Enter value of b: ");
        scanf("%f %f", &a, &b);
    } while (f(a) * f(b) >= 0);

    do
    {
        n++;
        c = (a + b) / 2;
        if (f(c) == 0)
            break;
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    } while (fabs((b - a) / a) > EPS);

    printf("The approximate root of given function is %f with %d number is iteration", c, n);
    return 0;
}
