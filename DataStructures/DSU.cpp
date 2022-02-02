#include <bits/stdc++.h>
using namespace std;
//DSU : O(*lg n)
const int N = 3e5 + 1 ;
struct dSU{
	vector<int> p , sz , mx , mn ; 
	dSU(int n){
		p = vector<int>(n+1) , sz = vector<int>(n+1 , 1) , mx = vector<int>(n+1 , 0) , mn = vector<int>(n+1 , N) ;
		iota(p.begin() , p.end() , 0) ;  
	} 
	int get(int a){ return p[a] = (p[a] == a ? a : get(p[a])) ; }
	int size(int a){
		return sz[get(a)] ; 
	}
	int maxi(int a){ return max(mx[get(a)] , a) ; }
	int mini(int a){ return min(mn[get(a)] , a) ; }
	bool same(int a , int b){return bool(get(a) == get(b)) ; } 
	void unite(int a , int b){
		a = get(a) , b = get(b) ;
		if(a == b)return ;  
		if(sz[a] > sz[b])swap(a , b) ; 
		sz[b] += sz[a] ; 
		p[a] = b ; 
		mn[b] = min({mn[b] , mn[a] , b , a}) ; 
		mx[b] = max({mx[b] , mx[a] , b , a}) ; 
	}
};
