#include <bits/stdc++.h>
using namespace std;
#define pb push_back
//Binary search tree - insert : O(h) - delete : O(h) - find : O(h) - print: O(n)
//in best case , the tree is balanced and h is lg(n)

struct Node{
	int val  ;
	Node* left = NULL , *right = NULL ; 
};

Node* Insert(Node* root , int x){
	if(root == NULL){
		root = new Node;  
		root->val = x ;
	}
	else if(x >= root->val){
		root->right = Insert(root->right , x) ;
	}
	else{
		root->left = Insert(root->left , x) ; 
	}
	return root ; 
}
void Print_inorder(Node* root){
	if(root == NULL)return ; 
	Print_inorder(root->left) ; 
	cout << root->val << ' ' ;
	Print_inorder(root->right) ; 
	return ; 
}

Node* Find(Node* root , int x){
	if(root == NULL || root->val == x){
		return root ;
	}
	if(x > root->val){
		return Find(root->right , x) ;
	}
	else{
		return Find(root->left , x) ; 
	}
}

Node* Min(Node* root){
	while(root->left != NULL){
		root = root->left ; 
	}
	return root ; 
}

Node* Max(Node* root){
	while(root->right != NULL){
		root = root->right ; 
	}
	return root ; 
}

Node* Upper_bound(Node* root , int x){
	// Node* up ; 
	// while(root->)
}

Node* Lower_bound(Node* root , int x){

}

int main(){
	Node root ; 
	Insert(&root , 5) ; 
	Insert(&root , 3) ; 
	Insert(&root , 1) ; 
	Insert(&root , 53) ;
	Insert(&root , -3 ) ;
	Print_inorder(&root) ; 
	cout << Min(&root)->val ;
	cout << '\n' ; 

}
