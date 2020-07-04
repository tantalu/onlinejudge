#include<stdio.h>

int main(void)
{
    int n, i;
    double sum;

    while (scanf("%d", &n) != EOF && n!=0)
    {
        sum = n;

        for (i=1; i<n; ++i)
        {
            sum += 2.0*(n-i)/(i+1);
        }
        printf("%.2f\n", sum);
    }
    return 0;
}
