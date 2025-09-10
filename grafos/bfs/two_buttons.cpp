#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ll n, m, r = 0;
    cin >> n >> m;

    if (n >= m)
    {
        r = n - m;
        cout<<r<<endl;
        return 0;
    }
    
    while (m>n)
    {
        if (m % 2 == 0)
        {
            m = m / 2;
        
        }
        else
        {
            m = m + 1;
        }
        r++;
    }
    r+=(n-m);
    cout << r << endl;

    return 0;
}