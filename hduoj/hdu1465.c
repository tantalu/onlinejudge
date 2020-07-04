#include<stdio.h>
// ¥ÌŒª≈≈¡–
int main(void)
{
	long long s[21] = {0, 0, 1};
	int n, i;
	
	for (i=3; i<21; ++i)
	{
		s[i] = (i-1)*(s[i-1]+s[i-2]);
	}
	
	while (scanf("%d", &n) != EOF)
	{
		printf("%I64d\n", s[n]);
	}
	return 0;
}
