// �ܱ�ʾΪ 2^m * (2n+1)^2 ��ʽ������T(n)=1
// ��˿���ʹ��ɸ��
#include<iostream>
#include<cmath>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    for (int k=0; k<t; ++k)
    {
        int i, n = 0;
        cin >> i;
        for (int j=1; j*j<=i; j+=2)
        {
            n += (int)log2(1.0*i/(j*j))+1;
        }
        cout << n%2 << endl;
    }

    return 0;
}