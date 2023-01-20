#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n;
    cin>>n;
    vector<int> dp(1e6+1, 0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        dp[x]++;
    }
    for(int gcd = 1e6;gcd>=1;gcd--){
        int count=0;
        for(int j=gcd;j<=1e6;j+=gcd){
            count += dp[j];
        }
        if(count>1){
            cout<<gcd<<endl;
            return 0;
        }
    }
    return 0;
}