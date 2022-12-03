#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t* Lps(string pattern){
    int len = pattern.size();
    int32_t* lps = new int32_t[len];

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

int32_t KmpSearch(string str, string pat){
    int lens = str.size();
    int lenp = pat.size();

    int32_t* lps = Lps(pat);
    int i=0, j=0, count=0;
    while(i<lens &&  j<lenp){
        if(str[i] == pat[j]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
        if(j==lenp){
            j=0;
            count++;
        }
    }
    return count;
    
}

int32_t main()
{
    string st, pat;
    cin >> st >> pat;
    cout << KmpSearch(st, pat) << endl;
    return 0;
}