vector<int> adj[N];
int cnt[N], dp[N], ans[N];
multiset<int> s[N];

void addChild(int node, int child) {
	// cnt[node] += cnt[child];
	// dp[node] += dp[child] + cnt[child];

	s[node].insert(dp[child] + 1);
	dp[node] = *s[node].rbegin();
}

void removeChild(int node, int child) {
	// dp[node] -= dp[child] + cnt[child];
	// cnt[node] -= cnt[child];

	auto it = s[node].find(dp[child] + 1);
	if (it != s[node].end())s[node].erase(it);
	dp[node] = *s[node].rbegin();
}

void changeRoot(int node, int child) {
	removeChild(node, child);
	addChild(child, node);
}

void dfs(int node, int parent) {
	//cnt[node] = 1;
	//dp[node] = 0;

	s[node].insert(0);
	dp[node] = 0;
	for (int child : adj[node]) {
		if (child == parent) continue;
		dfs(child, node);
		addChild(node, child);
	}
}

void reroot(int node, int parent) {
	ans[node] = dp[node];
	for (int child : adj[node]) {
		if (child == parent) continue;
		changeRoot(node, child);
		reroot(child, node);
		changeRoot(child, node);
	}
}
