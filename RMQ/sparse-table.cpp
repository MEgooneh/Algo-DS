#include <bits/stdc++.h>
using namespace std ;
// Range minimum queries - sparse table * in O(n*lg(n) + Q*n)
int main(){
	int n , q ; 
	cin >> n >> q ;
	int lg_n = __lg(n) ; 
	int arr[n] , minq[n][lg_n + 1] ; // minimum element in the query which starts from i, with 2^j length
	//pre-processing's strarting 
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i] ;
		minq[i][0] = arr[i] ; 
	}
	for(int j = 1 ; j <= lg_n ; j++){
		for(int i = 0 ; i <= n-(1<<j) ; i++){
			minq[i][j] = min(minq[i][j-1] , minq[i+(1<<j)][j-1]) ; 
		}
	}
	//pre-processing's end

	//queries
	while(q--){
		int l , r ;//0-indexed
		cin >> l >> r ;
		int lg_q = __lg(r-l+1) ; 
		cout << min(minq[l][lg_q] , minq[r-(1<<lg_q)+1][lg_q]) << '\n' ; 
	}
	return 0 ;
}