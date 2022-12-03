#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    multiset<int, greater<int>> priceofTicket;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        priceofTicket.insert(t);
    }
    int customerP;
    multiset<int>:: iterator it;
    while(m--){
        cin>>customerP;

        it = priceofTicket.lower_bound(customerP);
        if(it == priceofTicket.end()){
            cout<<-1<<endl;
        }
        else{
            cout<<*it<<endl;
            priceofTicket.erase(it);
        }

    }
    return 0;
}