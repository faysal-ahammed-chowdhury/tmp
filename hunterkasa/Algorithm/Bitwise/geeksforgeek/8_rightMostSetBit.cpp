// Returns the position of the rightmost set bit of `n`
int positionOfRightmostSetBit(int n)
{
	// if the number is odd, return 1
	if (n & 1) {
		return 1;
	}

	// unset rightmost bit and xor with the number itself
	n = n ^ (n & (n - 1));

	// find the position of the only set bit in the result;
	// we can directly return `log2(n) + 1` from the
	// function
	int pos = 0;
	while (n) {
		n = n >> 1;
		pos++;
	}
	return pos;
}
