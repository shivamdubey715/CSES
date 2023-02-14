#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n, cos = 0;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++){
        cos += abs(arr[n/2] - arr[i]);
    }
    cout<<cos<<endl;
}