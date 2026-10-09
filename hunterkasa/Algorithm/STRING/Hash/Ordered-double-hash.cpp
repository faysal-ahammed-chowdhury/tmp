#include <bits/stdc++.h>
typedef double          D;
typedef long long int   LL;
typedef long double     LD;
#define OR              ||
#define AND             &&
#define nl              '\n'
#define ff              first
#define ss              second
#define S               string
#define inf             INT_MAX
#define SQR(a)          (a) * (a)
#define pb              push_back
#define GCD(a, b)       __gcd(a, b)
#define PI              2.0*acos(0.0)
#define pii             pair<int,int>
#define pll             pair<long long,long long>
#define LCM(a, b)       (a * b) / GCD(a, b)
#define mem(a,b)        memset(a,b,sizeof(a))
#define srtv(v)         sort(v.begin(),v.end())
#define T               int t; cin>>t; while(t--)
#define Rep(i,a,b)      for(int i = a; i <= b; i++)
#define FOR(i,a)        for(int i=0;i<a;i++)
#define rep(i,a,b)      for(int i = a; i >= b; i--)
#define boost           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define inout           freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)

#define si(x)           scanf("%d",&x)
#define pi(x)           printf("%d",x)
#define sss(str)         scanf("%s",str)
#define pl(x)           printf("%lld",x)
#define sl(x)           scanf("%lld",&x)
#define sii(x,y)        scanf("%d %d",&x,&y)
#define sll(x,y)        scanf("%lld %lld",&x,&y)
#define siii(x,y,z)     scanf("%d %d %d",&x,&y,&z)
#define slll(x,y,z)     scanf("%lld %lld %lld",&x,&y,&z)
using namespace std;


#define ll long long

const int MAXN = 1000456;
namespace DoubleHash{
    ll P[2][MAXN];
    ll H[2][MAXN];
    ll R[2][MAXN];
    ll base[2];
    ll mod[2];
    void gen(){
        base[0] = 1949313259ll;
        base[1] = 1997293877ll;
        mod[0]  = 2091573227ll;
        mod[1]  = 2117566807ll;
        for ( int j = 0; j < 2; j++ ){
            for ( int i = 0; i < MAXN; i++ ){
                H[j][i]=R[j][i] = 0ll;
                P[j][i] = 1ll;
            }
        }
        for(int j=0;j<2;j++){
            for(int i=1;i<MAXN;i++){
                P[j][i] = (P[j][i-1] * base[j])%mod[j];
            }
        }
    }
    void make_hash(char *arr){
        int len = strlen(arr);//arr.size();
        for ( int j = 0; j < 2; j++ ){
            for (ll i = 1; i <= len; i++) H[j][i] = (H[j][i - 1] * base[j] + arr[i - 1] + 1007) % mod[j];
            for (ll i = len; i >= 1; i--) R[j][i] = (R[j][i + 1] * base[j] + arr[i - 1] + 1007) % mod[j];
        }
    }
    inline ll range_hash(int l,int r,int idx){
        ll hashval = H[idx][r + 1] - ((long long)P[idx][r - l + 1] * H[idx][l] % mod[idx]);
        return (hashval < 0 ? hashval + mod[idx] : hashval);
    }
    inline ll reverse_hash(int l,int r,int idx){
        ll hashval = R[idx][l + 1] - ((long long)P[idx][r - l + 1] * R[idx][r + 2] % mod[idx]);
        return (hashval < 0 ? hashval + mod[idx] : hashval);
    }
    inline ll range_dhash(int l,int r){
        ll x = range_hash(l,r,0);
        return (x<<32)^range_hash(l,r,1);
    }
    inline ll reverse_dhash(int l,int r){
        ll x = reverse_hash(l,r,0);
        return (x<<32)^reverse_hash(l,r,1);
    }
}


char str1[MAXN],str2[MAXN];

int main()
{
    //boost;
    int t;
    si(t);

    int test=0;
    DoubleHash::gen();

    while(t--)
    {
        scanf("%s",str1);
        scanf("%s",str2);

        //DoubleHash::gen();

        DoubleHash::make_hash(str2);

        LL sz=strlen(str2);
        LL b=DoubleHash::range_dhash(0,sz-1);

        LL ans=0;


        LL sz2=strlen(str1);

        LL a;
        //DoubleHash::gen();
        DoubleHash::make_hash(str1);

        if(sz2>=sz)
        {
            for(LL i=0;i<sz2;i++)
            {
                if(i+sz-1>=sz2)
                    break;
                a=DoubleHash::range_dhash(i,i+sz-1);

                if(a==b)
                    ans++;
            }
        }

        printf("Case %d: %lld\n",++test,ans);



    }


    return 0;
}






#define ll long long
const int MAXN=1000006;
namespace DoubleHash{
    ll P[2][MAXN];
    ll H[2][MAXN];
    ll R[2][MAXN];
    ll base[2];
    ll mod[2];
    void gen(){
        base[0] = 1949313259ll;
        base[1] = 1997293877ll;
        mod[0]  = 2091573227ll;
        mod[1]  = 2117566807ll;
        for(int j=0;j<2;j++){
            for(int i=0;i<MAXN;i++){
                H[j][i]=R[j][i] = 0ll;
                P[j][i] = 1ll;
            }
        }
        for(int j=0;j<2;j++){
            for(int i=1;i<MAXN;i++){
                P[j][i] = (P[j][i-1] * base[j])%mod[j];
            }
        }
    }
    void make_hash(string &arr){
        int len = arr.size();
        for(int j=0;j<2;j++){
            for (ll i = 1; i <= len; i++)H[j][i] = (H[j][i - 1] * base[j] + arr[i - 1] + 1007) % mod[j];
            for (ll i = len; i >= 1; i--)R[j][i] = (R[j][i + 1] * base[j] + arr[i - 1] + 1007) % mod[j];
        }
    }
    inline ll range_hash(int l,int r,int idx){
        ll hashval = H[idx][r + 1] - ((long long)P[idx][r - l + 1] * H[idx][l] % mod[idx]);
        return (hashval < 0 ? hashval + mod[idx] : hashval);
    }
    inline ll reverse_hash(int l,int r,int idx){
        ll hashval = R[idx][l + 1] - ((long long)P[idx][r - l + 1] * R[idx][r + 2] % mod[idx]);
        return (hashval < 0 ? hashval + mod[idx] : hashval);
    }
    inline ll range_dhash(int l,int r){
        ll x = range_hash(l,r,0);
        return (x<<32)^range_hash(l,r,1);
    }
    inline ll reverse_dhash(int l,int r){
        ll x = reverse_hash(l,r,0);
        return (x<<32)^reverse_hash(l,r,1);
    }
}
char str1[MAXN];
