#include<stdio.h>

int main(void)
{
    long long s[51] = {0, 3};
    long long d[51] = {0, 0};
    int n, i;

    for (i=2; i<51; ++i)
    {
        s[i] = 2*s[i-2] + d[i-2];
        d[i] = 2*s[i-1] + d[i-1];
    }
    d[1] = 3;

    while (scanf("%d", &n) != EOF)
    {
        printf("%I64d\n", d[n]);
    }
    return 0;
}
