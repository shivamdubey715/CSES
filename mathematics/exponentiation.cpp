#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = (int) 1e9 + 7;
 
int solve(int a, int b)
{
    int res = 1;
    while(b>0){
        if(b&1){
            res = (res*a)%MOD;
        }
        a = (a*a)%MOD;
        b>>=1;
    }
    return res;
    
}
 
int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        cout<<solve(a, b)<<endl;
    }

    return 0;
}