const int MAX = 1e6+10;
namespace prm {
    bitset<MAX> flag;
    int p = 0, prime[78777];
    const unsigned long long base[] = {4230279247111683200ULL, 14694767155120705706ULL, 16641139526367750375ULL};

    void Sieve() {
        flag[2] = true;
        for (int i = 3; i < MAX; i += 2) flag[i] = true;
        for (int i = 3; i * i < MAX; i += 2) {
            if (flag[i]) {
                for (int j = i * i, x = i << 1; j < MAX; j += x) {
                    flag[j] = false;
                }
            }
        }
        for (int i = 2; i < MAX; i++) {
            if (flag[i]) prime[p++] = i;
        }
    }

    void init() {
        if (!flag[2]) Sieve();
    }

    inline int expo(long long x, int n, int m) {
        long long res = 1;
        while (n) {
            if (n & 1) res = (res * x) % m;
            x = (x * x) % m;
            n >>= 1;
        }
        return res % m;
    }

    inline bool miller_rabin(int p) {
        if (p < MAX) return flag[p];
        if ((p + 1) & 1) return false;
        for (int i = 1; i < 9; i++) {
            if (!(p % prime[i])) return false;
        }
        int a, m, x, s = p - 1, y = p - 1;
        s >>= __builtin_ctz(s);
        for (int i = 0; i < 3; i++) {
            x = s, a = (base[i] % y) + 1;
            m = expo(a, x, p);
            while ((x != y) && (m != 1) && (m != y)) {
                m = ((long long) m * m) % p;
                x <<= 1;
            }
            if ((m != y) && !(x & 1)) return false;
        }
        return true;
    }
}