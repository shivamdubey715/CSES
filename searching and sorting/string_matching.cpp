#include<bits/stdc++.h>
using namespace std;

vector<int> prefix(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void searchString(string txt, string pattern){
    string str = pattern + "$" + txt;
    long long n = str.size(), patSize = pattern.size();
    vector<int> Z = prefix(str);
    long long count=0;
    for(long long i=0;i<n;i++){
        // cout<<Z[i]<<" ";
        if(Z[i] == patSize){
            count++;
        }
    }
    cout<<count<<endl;
}

int main(){
    string txt;
    string pattern;
    cin>>txt>>pattern;
    // cout<<pattern.length()<<endl;
    searchString(txt, pattern);
    return 0;
}