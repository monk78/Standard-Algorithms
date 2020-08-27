/**                    Author:Monk_
 *                     Topic:building Binary Search Tree[]                                                         **/
#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define _for(i,a,b) for(i=a;i<b;i++)

#define _rfor(i,a,b) for(i=a;i>=b;i--)

#define mp(a,b) make_pair(a,b)

void fast(){
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
}
class Node{
    public:
    int data;
    Node *left,*right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
/*
Node *buildTree(){
    int d;
    cin>>d;
    if(d==-1)return NULL;
    Node *root=new Node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
*/
void preorder(Node *root){
 if(root==NULL)return;
 cout<<root->data<<" ";
 preorder(root->left);
 preorder(root->right);
}

Node *ATB(ll arr[],ll start,ll end){
    if(start>end)return NULL;
    int mid=(start+end)/2;
    Node *root=new Node(arr[mid]);
    root->left=ATB(arr,start,mid-1);
    root->right=ATB(arr,mid+1,end);
    return root;
}
int main(){
    fast();
    ll n,i,test;
    cin>>test;
    while(test--){
    cin>>n;
    ll arr[n];
    _for(i,0,n)cin>>arr[i];
    Node *root=ATB(arr,0,n-1);
    preorder(root);
    }
    return 0;
}
