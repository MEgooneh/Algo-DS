#include <bits/stdc++.h>
using namespace std;
#define pb push_back
//dfs-1 Directed & 0-indexed * recursive method . O(n+m)
const int MAX_N = 1e5 + 1 ;
int n , m ; 
vector<int> adj[MAX_N] ;
int starting_time[MAX_N] , finishing_time[MAX_N] , dfs_time = 0;  
bool vis[MAX_N] ; 

void dfs(int v){
	vis[v] = 1 ;
	starting_time[v] = ++dfs_time ; 
	for(int u : adj[v]){
		if(!vis[u])dfs(u) ; 
	}
	finishing_time[v] = ++dfs_time ; 
	return ;
}
