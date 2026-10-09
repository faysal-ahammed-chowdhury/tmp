// by rank :- https://www.youtube.com/watch?v=3gbO7FDYNFQ&t=196s&ab_channel=takeUforward


// https://www.youtube.com/watch?v=xDrLSOxaFrA&ab_channel=Luv
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int parent[N];
int Size[N];

void make(int v){
    parent[v] = v;
    Size[v] = 1;
}

int find( int v ){
    if ( v == parent[v] )   return v;
    return parent[v] = find(parent[v]);
}

void Union( int a, int b ){
    a = find(a);
    b = find(b);

    if ( a != b ){
        if ( Size[a] < Size[b] )    
            swap(a,b);
        parent[b] = a;
        Size[a] += Size[b];
    }
}

int main(){
	int n, m;	cin >> n >> m;
	vector<pair<int, pair<int,int>>> edges;
	for ( int i = 0; i < m; i++ ){
		int u, v, wt;	cin >> u >> v >> wt;
		edges.push_back({wt,{u,v}});
	}
	sort(edges.begin(), edges.end());

	for ( int i = 1; i <= n; i++ ){
		make(i);
	}
	
	int total_cost = 0;
	for ( auto &edg : edges ){
		int wt = edg.first;
		int u = edg.second.first;
		int v = edg.second.second;

		if ( find(u) == find(v) )	
			continue; // this also means that there is a cycle in this tree
			
		Union(u,v);
		total_cost += wt;
		cout << u << " " << v << endl;
	}
	cout << total_cost << endl;
}