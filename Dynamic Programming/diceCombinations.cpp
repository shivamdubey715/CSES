#include <bits/stdc++.h>
using namespace std;
 
int mod = 1000000007;
 
int solve(int n, vector<int> &dp)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
 
    if (dp[n] != -1)
        return dp[n];
 
    int ans = 0;
 
    for (int i = 1; i <= 6; i++)
    {
        ans += solve(n - i, dp);
        ans %= mod;
    }
 
    return dp[n] = ans;
}
 
int main()
{
 
    int n;
    cin >> n;
 
    vector<int> dp(n + 1, -1);
 
    cout << solve(n, dp);
 
    return 0;
}