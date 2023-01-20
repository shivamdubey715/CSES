#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = (int)1e9 + 7;

int32_t main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(1000001, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    b[0] = 1;
    for (int j = 1; j <= n; j++)
    {
        for (int i = 0; i <= k; i++)
        {
            if (i - a[j - 1] >= 0)
            {
                b[i] += b[i - a[j - 1]];
                b[i] %= MOD;
            }
        }
    }
    cout << b[k] << endl;
    return 0;
}