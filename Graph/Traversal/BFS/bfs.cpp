#include <bits/stdc++.h>
using namespace std;
#define pb push_back
//bfs-1 Directed & 0-indexed * queue method . O(n+m)
const int MAX_N = 1e5 + 1 ;
int n , m ; 
vector<int> adj[MAX_N] ;
int dis[MAX_N] ;  
bool vis[MAX_N] ; 
void BFS(int v){
	queue<int> bfs; 
	bfs.push(v) ;
	vis[v] = 1 ;
	dis[v] = 0 ; 
	while(bfs.size()){
		int u = bfs.front() ; 
		bfs.pop() ; 
		for(auto i : adj[u]){
			if(!vis[i]){
				bfs.push(i) ;
				vis[i] = 1 ;
				dis[i] = dis[u]+1 ;
			}
		}
	}
	return ;
}
