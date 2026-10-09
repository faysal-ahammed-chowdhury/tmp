namespace Rawaha_AHO_Corasik{
    const int maxn=5e6+5;
    int link[maxn];
    vector<int>patternEndsHere[maxn];
    vector<int> linktree[maxn];
    map<char,int>Next[maxn];
    bool leaf[maxn];
    int cnt[maxn];
    int nodeCount,root;
    int T[1002][1002],dp[1002][1002];
    string str,str1;
    void makenode(int idx)
    {
        Next[idx].clear();
        cnt[idx]=0;
        leaf[idx]=0;
        patternEndsHere[idx].clear();
        linktree[idx].clear();
    }
    void init()   ///We have to call init
    {
        root=0,nodeCount=0;
        makenode(root);
    }
    void insrt(const string &s,int idx=-1) /// We have to insert the patterns
    {
        int node=root;
        for(char c:s){
            if(!Next[node].count(c)){
                nodeCount++;
                makenode(nodeCount);
                Next[node][c]=nodeCount;
            }
            node=Next[node][c];
        }
        if(idx!=-1)
            patternEndsHere[node].push_back(idx);
        leaf[node]=1;
        cnt[node]+=1;
    }
    void build(bool tree=false) ///If tree==true, then link tree will be created
    {
        queue<int>q;
        q.push(root);
        link[root]=-1;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto nxt:Next[u]){
                char c=nxt.first;
                int v=nxt.second;
                int fail=link[u];
                while(fail!=-1 && !Next[fail].count(c))
                    fail=link[fail];
                if(fail==-1)
                    link[v]=root;
                else
                    link[v]=Next[fail][c];
                cnt[v]+=cnt[link[v]];
                q.push(v);
                if(tree)
                    linktree[link[v]].push_back(v);
            }
        }
    }
    inline int transition(int node,char c)
    {
        while(node!=-1 && !Next[node].count(c))
            node=link[node];
        if(node==-1)
            return root;
        return Next[node][c];
    }
    void buildtable() /// For every node, where should we go
    {
        for(int i=0;i<=nodeCount;i++){
            for(int j=0;j<=25;j++){
                T[i][j]=transition(i,char('a'+j));
            }
        }
    }
    int vis[maxn]; /// It will check if a pattern occured or not
    int ans[maxn];
    void traverse(const string &s) /// Just to check if the given patterns occured or not
    {

        int node=root;
        for(char c:s){
            node=transition(node,c);
            vis[node]++; /// to count the number of occurance of the patterns->vis[node]++;
        }
    }
    void dfs(int u,int p) /// For counting the number of occurances of the pattern strings
    {
        for(int i:linktree[u]){
            if(i!=p){
                dfs(i,u);
                vis[u]+=vis[i];
            }
        }
        if(vis[u]){
            for(auto j:patternEndsHere[u]){
                ans[j]=vis[u];
            }
        }
    }
}
///We have to insert pattern strings using insrt(pattern,id) id is pattern number
///For link trees we have to call build(true), else call only build()
///We have to traverse the given string
///