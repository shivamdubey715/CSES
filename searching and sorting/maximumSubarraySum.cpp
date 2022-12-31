#include<bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=a[0], sm=a[0];
    for(int i=1;i<n;i++){
        sm = max(sm+a[i], a[i]);
        ans = max(ans, sm);
    }
    cout<<ans<<endl;
    return 0;
}