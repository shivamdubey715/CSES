#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, y = 0, count = 0, ans = 0;
    while (i < n)
    {
        if (a[i] < b[y])
        {
            count++;
            i++;
        }
        else
        {
            count--, y++;
        }
        ans = max(ans, count);
    }
    cout << ans << endl;
    return 0;
}