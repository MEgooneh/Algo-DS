#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define X first
#define Y second 
//Dijkstra

const int MAX_N = 1e5 + 1 ;
int n , m , par[MAX_N] ; 
vector<pair<int , long long>> adj[MAX_N] ;
bool vis[MAX_N] ; 
long long dis[MAX_N] ;

void shortest_path_from_s(int s){
	set<pair<long long , int>> dismin ;  
	vector<long long> dis(n+1 , __builtin_inf()) ; 
	dis[s] = 0 ;
	dismin.insert({0 , s}) ; 
	while(!dismin.empty()){
		pair<long long , int> u = *dismin.begin() ; 
		dismin.erase(dismin.begin()) ; 
		if(vis[u.Y])continue ; 
		vis[u.Y] = 1; 
		for(auto i : adj[u.Y]){
			if(vis[i.X])continue ; 
			if(dis[i.X] > dis[u.Y] + i.Y){
				dis[i.X] = dis[u.Y] + i.Y ; 
				par[i.X] = u.Y ; 
			}
			dismin.insert({dis[i.X] , i.X}) ;  
		}
	}
}
