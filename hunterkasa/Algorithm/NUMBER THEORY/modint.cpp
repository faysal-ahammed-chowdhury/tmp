/* 
const int mod = 1e9+7;
struct mint
{
    ll x;
    mint(ll y = 0){if(y < 0 || y >= mod) y = (y%mod+mod)%mod; x = y;}
    mint(const mint &ope) {x = ope.x;}
    mint operator-(){return mint(-x);}
    mint operator+(const mint &ope){return mint(x) += ope;}
    mint operator-(const mint &ope){return mint(x) -= ope;}
    mint operator*(const mint &ope){return mint(x) *= ope;}
    mint operator/(const mint &ope){return mint(x) /= ope;}
    mint& operator+=(const mint &ope){x += ope.x; if(x >= mod) x -= mod; return *this;}
    mint& operator-=(const mint &ope){x += mod - ope.x; if(x >= mod) x -= mod; return *this;}
    mint& operator*=(const mint &ope){ll tmp = x; tmp *= ope.x, tmp %= mod; x = tmp; return *this;}
    mint& operator/=(const mint &ope){ll n = mod-2; mint mul = ope;while(n){if(n & 1) *this *= mul; mul *= mul; n >>= 1;}return *this;}
    mint inverse(){return mint(1) / *this;}
    bool operator ==(const mint &ope){return x == ope.x;}
    bool operator !=(const mint &ope){return x != ope.x;}
    bool operator <(const mint &ope)const{return x < ope.x;}
}; */


template<uint64_t mod, typename F = false_type>
struct modnum {
    using S = conditional_t<F::value, uint64_t, uint32_t>;
    using L = conditional_t<F::value, __uint128_t, uint64_t>;
 
    S x;
 
    modnum() : x(0) {}
    modnum(int64_t _x) {
        _x %= mod;
        if (_x < 0) _x += mod;
        x = _x;
    }
 
    modnum pow(int64_t n) const {
        modnum res = 1;
        modnum cur = *this;
        while (n > 0) {
            if (n & 1) res *= cur;
            cur *= cur;
            n /= 2;
        }
        return res;
    }
    modnum inv() const { return (*this).pow(mod-2); }
    
    modnum& operator+=(const modnum& a){
        x += a.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    modnum& operator-=(const modnum& a){
        if (x < a.x) x += mod;
        x -= a.x;
        return *this;
    }
    modnum& operator*=(const modnum& a){
        x = static_cast<L>(x) * a.x % mod;
        return *this;
    }
    modnum& operator/=(const modnum& a){ return *this *= a.inv(); }
    
    friend modnum operator+(const modnum& a, const modnum& b){ return modnum(a) += b; }
    friend modnum operator-(const modnum& a, const modnum& b){ return modnum(a) -= b; }
    friend modnum operator*(const modnum& a, const modnum& b){ return modnum(a) *= b; }
    friend modnum operator/(const modnum& a, const modnum& b){ return modnum(a) /= b; }
    
    friend bool operator==(const modnum& a, const modnum& b){ return a.x == b.x; }
    friend bool operator!=(const modnum& a, const modnum& b){ return a.x != b.x; }
    friend bool operator<(const modnum& a, const modnum& b){ return a.x < b.x; }
 
    friend ostream& operator<<(ostream& os, const modnum& a){ os << a.x; return os; }
    friend istream& operator>>(istream& is, modnum& a) { int64_t x; is >> x; a = modnum(x); return is; }
};
 
using mint = modnum<1'000'000'007>; // modnum<998'244'353>; // modnum<1'000'000'000'000'000'003, true_type>;