#include<iostream>
#include <vector>
using namespace std;
#define int long long

int32_t main(){
    int n, k;
    cin>>n>>k;
    vector<int> primes(k);
    vector<int> nof(k+1, 0);
    for(int i=0;i<k;i++){
        cin>>primes[i];
    }

    for(int mask = 1;mask < (1<<k);mask++){
        int numberOfDivisors = 0;
        int temp = n;
        for(int i=0;i<k;i++){
            if((1<<i)&mask){
                numberOfDivisors++;
                temp /= primes[i];
            }
        }
        nof[numberOfDivisors] += temp;
    }
    int ans=0;
    for(int i=1;i<=k;i++){
        if(i%2==0){
            ans -= nof[i];
        }
        else{
            ans += nof[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}