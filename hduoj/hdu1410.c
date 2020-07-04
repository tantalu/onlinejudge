// P(w:l胜利) = P(w:0) + P(w:1) + ... + 1/2P(w:l)
//            = P(w-1:0) + P(w-1:1) + ... + P(w-1:l)
// WA 但是找不到错误数据
#include<math.h>
#include<stdio.h>

int main(void)
{
	int hp1, hp2, ap1, ap2;
	double res, lgcom;
	int w, l, s;
	int i;
	
	while (scanf("%d%d%d%d", &hp1, &hp2, &ap1, &ap2) !=EOF)
	{
		w = (hp2-1) / ap1 + 1;
		l = (hp1-1) / ap2 + 1;
		s = w + l - 1;
		lgcom = log2(1.0);// com = 1.0;
		res = pow(2, lgcom-s);
		for (i=1; i<l; ++i)
		{
			lgcom += log2((double)(s+1-i)/i);// com = com * (s+1-i) / i;
			res += pow(2, lgcom-s);// res += com*pow(2, -s);
		}
		printf("%.4f\n", 100*res);
	}
	
	return 0;
}
