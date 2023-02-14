
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct suffix
{
    int index;
    string suff;
};

int *buildSuffixArray(string txt, int n)
{
    struct suffix suffixes[n];
    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].suff = txt.substr(i);
        // cout<<txt.substr(i)<<endl;
    }
    int *suffixArr = new int[n];
    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;

    return  suffixArr;
}

void printArr(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void search(string pat, string txt, int *suffArr, int n)
{
    int m = pat.size(); // get length of pattern, needed for strncmp()

    // Do simple binary search for the pat in txt using the
    // built suffix array
    int l = 0, r = n-1;  // Initilize left and right indexes
    while (l <= r)
    {
        // Compare pat with the middle suffix in suffix array
        int mid = l + (r - l)/2;
        int res = strncmp(pat.c_str(), txt.substr(suffArr[mid]).c_str(), m);
        cout<<txt.substr(suffArr[mid], pat.size()).c_str()<<endl;
        // If match found at the middle, print it and return
        if (res == 0)
        {
            cout << "YES"<<endl;;
            return;
        }

        // Move to left half if pattern is alphabtically less than
        // the mid suffix
        if (res < 0) r = mid - 1;

        // Otherwise move to right half
        else l = mid + 1;
    }

    // We reach here if return statement in loop is not executed
    cout << "NO"<<endl;;
}

int main()
{
    string txt;   // pattern to be searched in text
    cin>>txt;
    int k;
    cin>>k;
    while(k--){
        string str;
        cin>>str;
        int n = txt.size();
        int *suffArr = buildSuffixArray(txt, n);
        search(str, txt, suffArr, n);
    }
    return 0;
}
