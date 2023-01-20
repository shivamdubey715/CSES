// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// void solve(int n){
    
//     vector<int> dp;
//     for(int i=2;i*i<=n;i++){
//         if(n%i==0){
//             int ans=0;
//             while(n%i==0){
//                 ans++;
//                 n/=i;
//             }
//             dp.push_back(ans);
//         }
//     }
//     if(n!=1){
//         dp.push_back(1);
//     }
//     int res=1;
//     for(int i : dp){
//         res *= (i+1);
//     }
//     cout<<res<<endl;
// }

// int32_t main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         solve(n);
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// vector<int> sieveE(int n){
//     vector<int> sp(n+1);
//     sp[0] = 0;
//     for(int i=1;i<=n;i++){
//         sp[i] = i;
//     }

//     for(int i=2;i*i<=n;i++){
//         if(sp[i]==i){
//             for(int j=i*i;j<=n;j+=i){
//                 if(sp[j] == j){
//                     sp[j] = i;
//                 }
//             }
//         }
//     }
//     return sp;
//     // cout<<2<<endl;
// }

// void solve(int n, vector<int> sp){
//     int ans=1;
//     // cout<<sp[0]<<endl;
//     while(n!=1){
//         int y = sp[n];
//         int temp = 1;
//         while(n%y==0){
//             temp++;
//             n/=y;
//         }
//         ans *= temp;
//     }
//     cout<<ans<<endl;
// }

// int32_t main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         vector<int> sp = sieveE(n);
//         solve(n, sp);
//     }
//     return 0;
// }

/*
Problem Name: Counting Divisors
Problem Link: https://cses.fi/problemset/task/1713
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << "=" << a << ", "; err(++it, args...);}
#define int long long
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define L cout<<'\n';
#define E cerr<<'\n';
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
const ll inf = INT_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

#define MAX 1000005
int spf[MAX];
void sievespf(int n) {
    for (int i=1; i<=n; i++){
        spf[i] = i;
    }
    for (int p=2; p*p<=n; p++) {
        if (spf[p] == p) {
            for (int i=p*p; i<=n; i += p) 
                if (spf[i]==i) spf[i]=p; 
        }
    } 
} 
void solve(){
    int x; see(x);
    int ans=1;
    while (x!=1){
        int y = spf[x];
        int c=1;
        while(x%y==0){
            c++; x/=y;
        }
        ans*=c;
    }
    put(ans);
}    
signed main(){
    int t=1;
    cin>>t;
    sievespf(1000000);
    while(t--){
        solve();
        cout<<'\n';
    }
    return 0;
}