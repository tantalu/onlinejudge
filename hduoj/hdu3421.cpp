// ˮˮ����������кͣ������к�Ϊ�����������ж��ҳ����ͺ���
#include<cstdio>

using namespace std;

int main(void)
{
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; ++i)
    {
        int n;
        scanf("%d", &n);
        long long sum = 0;
        int sub = 0;
        for (int j=0; j<n; ++j)
        {
            int m;
            scanf("%d", &m);
            // ����0����ʼһ���µ�������
            if (m <= 0)
            {
                continue;
            }
            ++sub;
            sum += m;
            for (++j; j<n; ++j)
            {
                scanf("%d", &m);
                // �������٣��������������м������0����
                if (m < 0)
                {
                    break;
                }
                sum += m;
            }
        }
        printf("Case %d:\n%d %I64d%s", i, sub, sum, i==t?"\n":"\n\n");
    }
    return 0;
}
