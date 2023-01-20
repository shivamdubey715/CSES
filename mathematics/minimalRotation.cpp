#include<iostream>
using namespace std;
#define int long long

int32_t main(){
    string s;
    cin>>s;
    s+=s;
    int n = s.size();
    int i = 0, ans = 0;

    while(i<n/2){
        ans = i;
        // cout<<ans<<endl;
        int k = i, j=i+1;
        while(j<n && s[j] >= s[k]){
            // cout<<k<<" "<<j<<endl;
            if(s[k] == s[j]){
                k++;
            }
            if(s[j]>s[k]){
                k=i;
            }
            j++;
        }
        while(i<=k){
            i += j-k;
        }
    }
    cout<<s.substr(ans, n/2)<<endl;;
    return 0;
}