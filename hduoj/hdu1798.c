#include<stdio.h>
#include<math.h>

int main(void)
{
	double xa, ya, ra, xb, yb, rb;      // ��double���ݣ���Ȼ��Output Limit Exceeded
	double pi = 2*asin(1.0);
	double s;
	double d, anglea, angleb;
	
	while (scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &ra, &xb, &yb, &rb) != EOF)        // Output Limit Exceeded
	{
		d = sqrt( (xa-xb)*(xa-xb) + (ya-yb)*(ya-yb) );
		if (d>=ra+rb)               // ���룬������0Ҳ�� AC
		{
			s = 0;
		}
		else if (d<=fabs(ra-rb))    // �ں�
		{
			s = rb<ra ? pi*rb*rb : pi*ra*ra;
		}
		else                       // �ཻ������180�����Ϊ���������ж�
		{
			anglea = 2*acos( (ra*ra+d*d-rb*rb) / (2*ra*d) );
  			angleb = 2*acos( (rb*rb+d*d-ra*ra) / (2*rb*d) );

			s = (anglea-sin(anglea)) * ra*ra/2 + (angleb-sin(angleb)) * rb*rb/2;
		}
		printf("%.3f\n", s);
	}
	return 0;
}
