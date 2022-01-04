#include <bits/stdc++.h>
using namespace std;
#define pb push_back
//dfs-2 Directed & 0-indexed * iterative method . O(n+m)
const int MAX_N = 1e5 + 1 ;
int n , m ; 
vector<int> adj[MAX_N] ;
int starting_time[MAX_N] , finishing_time[MAX_N] , dfs_time = 0;  
bool vis[MAX_N] ; 

void DFS(int v){
	vector<int> dfs ; 
	dfs.pb(v) ; 
	while(!dfs.empty()){
		int u = dfs.back() ; 
		if(vis[u]){
			finishing_time[u] = ++dfs_time ; 
			dfs.pop_back() ; 
			continue ;
		}
		starting_time[u] = ++dfs_time ; 
		for(auto i : adj[u]){
			if(!vis[i]){
				dfs.pb(i) ; 
			} 
		}
		vis[u] = 1 ;
	}
}
