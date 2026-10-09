// smallest power of 2
// greater than or equal to n
#include <bits/stdc++.h>
using namespace std;

long long nearestPowerOf2(long long N)
{
	long long a = log2(N);

	if (pow(2, a) == N)
		return N;

	return pow(2, a + 1);
}

// Driver Code
int main()
{
	unsigned int n = 5;
	cout << nearestPowerOf2(n);
	return 0;
}

// This code is contributed by hkdass001
