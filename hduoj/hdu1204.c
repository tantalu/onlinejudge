// 0  1  2  3  ...   N+M-1  N+M
//  <- ->
//   l  r
//
// u_k 表示有k糖果时的胜率，u_(N+M) = 1, u_0 = 0
// (l+r)u_k = l*u_(k-1) + r*u_(k+1)
// u_(k+1) - u_k = (l/r) * (u_k - u_(k-1))
//               = (l/r)^k * (u_1 - u_0)
//
// 记d_k = u_k - u_(k-1)，
// d_k = (l/r)^(k-1) * d_1
// d_(N+M) - d_1 = (1 + (l/r) + ... + (l/r)^(N+M-1)) * d_1
//               = (1 - (l/r)^(N+M)) / (1 - (l/r)) * d_1
//               = u_(N+M) - u_0
//               = 1
// d_1 = (1 - (l/r) / (1 - (l/r)^(N+M))
//
// d_k = (l/r)^(k-1) * (1 - (l/r)) / (1 - (l/r)^(N+M))
//     = ((l/r)^(k-1) - (l/r)^k) / (1 - (l/r)^(N+M))
//
// u_k = u_0 + d_1 + d_2 + ... + d_k
//     = 0 + (1 - l/r + l/r - (l/r)^2 + ... + (l/r)^(k-1) - (l/r)^k) / (1 - (l/r)^(N+M))
//     = (1 - (l/r)^k) / (1 - (l/r)^(N+M))
//
#include<stdio.h>
#include<math.h>

int main(void)
{
	int n, m;
	double p, q;
	double l, r;
	
	while (scanf("%d%d%lf%lf", &n, &m, &p, &q) !=EOF)
	{
		if (m==0)              				// 0 0
		{
			printf("1.00\n");
		}
		else if (n==0 || p==0 || q==1)      // 分母不能为0
		{
			printf("0.00\n");
		}
		else if (p==q)                      // 退化为线性
		{
			printf("%.2f\n", (double)n/(n+m) );
		}
		else
		{
			l = q*(1-p);
			r = p*(1-q);
		
			printf("%.2f\n", (1-pow(l/r, n)) / (1-pow(l/r, n+m)) );
		}
	}
	return 0;
}
