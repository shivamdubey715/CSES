#include<bits/stdc++.h>
using namespace std;

vector<int> Lps(string pattern){
    int len = pattern.size();
    vector<int> lps(len);

    lps[0] = 0;
    int i=1, j=0;

    while(i<len){
        if(pattern[i] == pattern[j]){
            lps[i] = j+1;
            j++;
            i++;
        }
        else{
            if(j!=0){
                j = lps[j-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
void findingBorders(string pat){

    vector<int> lps = Lps(pat);
    int n = lps.size();
    int j = lps[n-1];
    vector<int> ans;
    while(j>0){
        ans.push_back(j);
        j = lps[j-1];
    }
    sort(ans.begin(), ans.end());
    n = ans.size();
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    string pat;
    cin>>pat;
    findingBorders(pat);
    return 0;
}