// 暴力试出四组解，也可以手算
#include<stdio.h>

int main(void)
{
    int t;
   	int match[4][8] = {{7,3,1,4,5,8,6,2}, {7,4,1,3,6,8,5,2}, {2,6,8,5,4,1,3,7}, {2,5,8,6,3,1,4,7}};
   	int num[10];
    int re, ans, flag;
    int i, j, k;
    
    scanf("%d", &t);
    for (j=1; j<=t; ++j)
    {
        for (i=0; i<8; ++i)
        {
            scanf("%d", &num[i]);
        }

		ans = 0;
        for (i=0; i<4; ++i)
        {
        	flag = 1;
        	for (k=0; k<8; ++k)
        	{
        		if (num[k]!=0 && num[k]!=match[i][k])
        		{
        			flag = 0;
        			break;
        		}
        	}
        	if (flag==1)
        	{
        		ans++;
        		re = i;
        	}
        }
        
        if (ans==0)
        {
        	printf("Case %d: No answer\n", j);
        }
        else if (ans==1)
        {
        	printf("Case %d: ", j);
			for (i=0; i<8; ++i)
			{
				printf("%d%c", match[re][i], i==7?'\n':' ');
			}
        }
        else
        {
        	printf("Case %d: Not unique\n", j);
        }
    }
    return 0;
}
