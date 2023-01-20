#include<iostream>
#include<vector>
#include<climits>
using namespace std;
#define int long long

int32_t main(){
    int n, maxi = INT_MIN;
    cin>>n;
    vector<int> values(n);
    for(int i=0;i<n;i++){
        cin>>values[i];
        maxi = max(maxi, values[i]);
    }
    vector<vector<int> > divisorsOf(maxi+1);
    for(int i=2;i<=maxi;i++){
        if(divisorsOf[i].size()==0){
            divisorsOf[i].push_back(i);
            for(int j=2*i;j<=maxi;j+=i){
                divisorsOf[j].push_back(i);
            }
        }
    }

    vector<int> valDiviBy(maxi+1);
    vector<int> primedivisorsOf(maxi+1);
    for(int i=0;i<n;i++){
        for(int mask =1; mask < (1<<(divisorsOf[values[i]].size()));mask++){
            int combi = 1;
            int primeDivisors = 0;
            for(int position = 0; position < divisorsOf[values[i]].size(); position++){
                if((1<<position)&mask){
                    combi *= divisorsOf[values[i]][position];
                    primeDivisors++;
                }
            }
            valDiviBy[combi]++;
            primedivisorsOf[combi] = primeDivisors;
        }
    }
    int totalPossiblePairs = n*(n-1)/2;
    int pairsValid = 0;
    for(int i=0;i<=maxi;i++){
        if(primedivisorsOf[i]%2==0){
            pairsValid -= (valDiviBy[i]*(valDiviBy[i] - 1))/2;
        }
        else{
            pairsValid += (valDiviBy[i]*(valDiviBy[i] - 1))/2;
        }
    }
    cout<<totalPossiblePairs - pairsValid<<endl;
    return 0;
}