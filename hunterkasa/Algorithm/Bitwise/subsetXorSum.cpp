int subsetXORSum(vector<int>& a) {
        int n = a.size();
        int ans = accumulate(a.begin(), a.end(), 0, bit_or<>() );
        return pow(2,n-1)*ans;
    }