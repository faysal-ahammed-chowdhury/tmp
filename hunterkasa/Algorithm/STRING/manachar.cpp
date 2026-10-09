#include <bits/stdc++.h>
using namespace std;

vector<int>manachar(string str){
    int i,j,k,l=str.size(),n=l<<1;
    vector<int>pal(n);
    for(int i=0,j=0,k=0;i<n;j=max(0,j-k),i+=k){
        while(j<=i&&(i+j+1)<n&&str[(i-j)>>1]==str[(i+j+1)>>1])j++;
        for(k=1,pal[i]=j;k<=i&&k<=pal[i]&&(pal[i]-k)!=pal[i-k];k++){
            pal[i+k]=min(pal[i-k],pal[i]-k);
        }
    }
    pal.pop_back();
    return pal;
}
