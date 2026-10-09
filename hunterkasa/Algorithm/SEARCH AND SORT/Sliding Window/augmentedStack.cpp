struct AggStack {
    // Each element is stored as (value, current_min)
    stack<pair<int, int>> st;
    
    // Push a new number; compute the new min.
    void push(int x) {
        int cur = st.empty() ? x : min(st.top().second, x); //////aggque also change here 
        st.push({x, cur});
    }
    
    // Pop the top element.
    void pop() {
        st.pop();
    }
    
    // Return the current minimum.
    int agg() const {
        return st.top().second;
    }
};

struct AggQueue {
    AggStack in, out;
    
    // Push a new number into the queue.
    void push(int x) {
        in.push(x);
    }
    
    // Pop the oldest number.
    void pop() {
        if (out.st.empty()) {
            while (!in.st.empty()) {
                int v = in.st.top().first;
                in.pop();
                out.push(v);
            }
        }
        out.pop();
    }
    
    // Query the current minimum.
    int query() const {
        if (in.st.empty()) return out.agg();
        if (out.st.empty()) return in.agg();
        return min(in.agg(), out.agg()); ///////change here min to max gcd etc also change aggstack
    }
};
vector<int> slideMin(const vector<int>& a, int K) {
    int n = a.size();
    vector<int> ans;
    AggQueue mq;  // Our aggregated queue maintains the minimum
    
    // Build the initial window of size K.
    for (int i = 0; i < K; i++) {
        mq.push(a[i]);
    }
    ans.push_back(mq.query());
    
    // Slide the window: add a new element and remove the oldest.
    for (int i = K; i < n; i++) {
        mq.push(a[i]);   // add new element
        mq.pop();        // remove element that's left the window
        ans.push_back(mq.query());
    }
    
    return ans;
}
