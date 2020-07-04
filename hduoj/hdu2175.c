#include<stdio.h>
#include<math.h>

int main(void)
{
	int n;
	long long m;

	while (scanf("%d%I64d", &n, &m) && (m||n))
	{
		printf("%d\n", (int)log2(m&(-m))+1);
	}
	
	return 0;
}
