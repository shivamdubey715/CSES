#include <bits/stdc++.h>

using namespace std;

const int modu = 1e9+7;

int power(long long a, int b, int MOD)
{
    long long res = 1;
    if (!b) return res;
    a %= MOD;
    if (!a) return 0;
    while (b > 0)
    {
        if (b & 1) res = ((res*a)%MOD);
        b >>= 1;
        a = ((a*a)%MOD);
    }
    return res;
}

int main()
{
    long long n;
    cin >> n;
    while (n--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << power(a, power(b, c, modu-1), modu) << '\n';
    }
}
