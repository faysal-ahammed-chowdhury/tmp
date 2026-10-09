#include<bits/stdc++.h>
using namespace std;

bool prime[500000 + 10];
void SieveOfEratosthenes(){
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = 0;
    for (int p = 2; p * p <= 500000; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= 500000; i += p)
                prime[i] = false;
        }
    }
}