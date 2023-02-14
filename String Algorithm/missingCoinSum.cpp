#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n, cos = 0;
    cin>>n;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    sort(coins.begin(), coins.end());
    int smallestSum = 1;
    for(int i=0;i<n;i++){
        if(smallestSum<coins[i]){
            break;
        }
        smallestSum += coins[i];
    }
    cout<<smallestSum<<endl;
    
}