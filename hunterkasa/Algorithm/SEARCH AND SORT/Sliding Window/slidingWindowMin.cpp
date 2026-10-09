struct MinWindow {
    deque<pair<int, int>> s;
    int time = 0;
    int k = <set me in the constructor or whatever>;

    void push(int x){
        //remove older elements that are >= x
        while(!s.empty() && s.back().first >= x) s.pop_back();
        // note that s is increasing after this emplace_back
        s.emplace_back(x, time);
        time++;
    }

    int get() {
        //remove elements older than k <- this can be maintained in push as well
        while(s.front().second < time - k) {
            s.pop_front();
        }
        return s.front().first;
    }
};