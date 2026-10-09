const int MAXN = 1e6+100;
namespace SingleHash{
    ll P[MAXN];
    ll H[MAXN];
    ll R[MAXN];
    ll base[1];
    ll mod[1];
    void gen(){
        base[0] = 1949313259ll;
        mod[0]  = 2091573227ll;
        for ( int i = 0; i < MAXN; i++ ){
            H[i] = R[i] = 0ll;
            P[i] = 1ll;
        }
        for(int i=1;i<MAXN;i++){
            P[i] = (P[i-1] * base[0])%mod[0];
        }
    }
    void make_hash( string &arr ){
        int len = arr.size();
        for (ll i = 1; i <= len; i++) H[i] = (H[i - 1] * base[0] + arr[i - 1] + 1007) % mod[0];
        for (ll i = len; i >= 1; i--) R[i] = (R[i + 1] * base[0] + arr[i - 1] + 1007) % mod[0];
    }
    inline ll range_hash(int l,int r){
        ll hashval = H[r + 1] - ((long long)P[r - l + 1] * H[l] % mod[0]);
        return (hashval < 0 ? hashval + mod[0] : hashval);
    }
    inline ll reverse_hash(int l,int r){
        ll hashval = R[l + 1] - ((long long)P[r - l + 1] * R[r + 2] % mod[0]);
        return (hashval < 0 ? hashval + mod[0] : hashval);
    }
}