#include<stdio.h>

int main(void)
{
	int n, w, d, all;
	int ans;
	while (scanf("%d%d%d%d", &n, &w, &d, &all)!=EOF)
	{
		ans = (n*(n-1)/2*w - all) / d;
		printf("%d\n", ans==0 ? n : ans);
	}
    return 0;
}
