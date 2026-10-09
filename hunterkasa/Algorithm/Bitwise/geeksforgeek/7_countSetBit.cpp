// Function to calculate the number of set bits.
int countBits(int n)
{
	// Initialising a variable count to 0.
	int count = 0;
	while (n) {
		// If the last bit is 1, count will be incremented
		// by 1 in this step.
		count += n & 1;

		// Using the right shift operator.
		// The bits will be shifted one position to the
		// right.
		n >>= 1;
	}
	return count;
}
