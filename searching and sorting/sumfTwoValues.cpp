#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    vector<pair<int, int>> b;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b.push_back({a[i], i+1});
    }
    sort(b.begin(), b.end());
    int i=0, j = b.size()-1;
    while(i<j){
        // int mid = (j-1)/2;
        if(b[i].first + b[j].first > k){
            j--;
        }
        else if(b[i].first + b[j].first < k){
            i++;
        }
        else if(b[i].first + b[j].first == k){
            cout<<b[i].second<<" "<<b[j].second<<endl;
            break;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}