#include<stdio.h>
#define PI 3.14159265359

int main( void )
{
    const double pi = 3.14159265359;
    int l;

    scanf("%d", &l);
    while(l!=0)
    {
        printf("%.2f\n",(double)l*l/pi/2);
        scanf("%d",&l);
    }

    return 0;
}
