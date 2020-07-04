#include<iostream>
#include<set>
#include<string>

using namespace std;

// 最小表示法，O(n)
string MinimumRepresentation(string s)
{
    int l = s.length();
    int i = 0, j = 1, k = 0;
    while (i<l && j<l && k<l)
    {
        int t = s[(i+k)%l] - s[(j+k)%l];
        if (t==0)
        {
            k++;
        }
        else
        {
            if (t > 0)
            {
                i += k+1;
            }
            else
            {
                j += k+1;
            }
            if (i==j)
            {
                ++j;
            }
            k = 0;
        }
    }
    int start = i<j ? i : j;
    string re = s.substr(start, l-start);
    re += s.substr(0, start);
    return re;
}

int main(void)
{
    int n;

    while (cin >> n)
    {
        set<string> necklaces;
        string s;
        necklaces.clear();
        for (int i=0; i<n; ++i)
        {
            cin >> s;
            s = MinimumRepresentation(s);
            if (necklaces.find(s)==necklaces.end())
            {
                necklaces.insert(s);
            }
        }
        cout << necklaces.size() << endl;
    }

    return 0;
}
