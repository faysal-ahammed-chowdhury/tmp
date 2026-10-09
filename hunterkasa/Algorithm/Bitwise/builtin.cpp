// __builtin_popcount(x): Counts the number of one’s(set bits) in an integer(long/long long)
// If x is of long type,we can use __builtin_popcountl(x) If x is of long long type,we can use __builtin_popcountll(x)


// __builtin_parity(x): Checks the Parity of a number.Returns true(1) if the number has odd parity(odd number of set bits) else it returns false(0) for even parity(even number of set bits).
// Ex- int x=5;
//     cout<<__builtin_parity(x)<<endl;   //returns 0.
// If x is of long type,we can use __builtin_parityl(x) If x is of long long type,we can use __builtin_parityll(x)

// __builtin_clz(x): Counts the leading number of zeros of the integer(long/long long).
// If x is of long type,we can use __builtin_clzl(x) If x is of long long type,we can use __builtin_clzll(x)

// __builtin_ctz(x): Counts the trailing number of zeros of the integer(long/long long).
// If x is of long type,we can use __builtin_ctzl(x) If x is of long long type,we can use __builtin_ctzll(x)

// __builtin_ffs(x) (Find First Set) which returns (the index of the least significant bits of x) + 1

// __lg(x)
// It's helper to compute the 2-based logarithm of integer number, i.e. it return the index of highest set bit in the number (or -1 for 0).
// I.e. for 1 it will return 0, for 16 it will return 4, for 1024 it will return 10, etc.

