const int MAXN = 1000456;
struct DoubleHash{
    ll P[2][MAXN];
    ll H[2][MAXN];
    ll R[2][MAXN];
    ll base[2];
    ll mod[2];
    void gen(){
        base[0] = 1949313259LL;
        base[1] = 1997293877LL;
        mod[0]  = 2091573227LL;
        mod[1]  = 2117566807LL;
        for ( int j = 0; j < 2; j++ ){
            for ( int i = 0; i < MAXN; i++ ){
                H[j][i]=R[j][i] = 0LL;
                P[j][i] = 1LL;
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
}h1;