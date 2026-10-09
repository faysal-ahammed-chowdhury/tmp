#include<bits/stdc++.h>
using namespace std;

string totalXOR(string s, int n){
    vector<int> occurrence;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            occurrence.push_back(i + 1);
        else
            occurrence.push_back(0);
    }
    int sums = accumulate(occurrence.begin(), occurrence.end(), 0);
    string ans = "";
    for (int i = 0; i < n; i++) {
        // Checking if the total occurrences
        // are odd
        if (sums % 2 == 1)
            ans = "1" + ans;
        else
            ans = "0" + ans;
        sums -= occurrence.back();
        occurrence.pop_back();
    }
    return ans;
}