#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n], maxi = INT_MIN;
    set<int> st;
    for(int i=0;i<n;i++){
        cin>>a[i];
        st.insert(a[i]);
    }
    cout<<st.size()<<endl;
    return 0;
}