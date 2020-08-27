/**                    Author:Monk_
 *                     Topic:checking_two_tree_identical_Or_Not                                                         **/
#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define _for(i,a,b) for(i=a;i<b;i=i++)

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
	 Node *left;
	 Node *right;
	 Node(int d){
	 	data=d;
	 	left=NULL;
	 	right=NULL;
	 }
};
Node *buildTree(){
	int d=0;
	cin>>d;
	if(d==-1)return NULL;
	Node *root=new Node(d);
	root->left=buildTree();
	root->right=buildTree();
	return root;
}
bool identicalTree(Node *root1,Node *root2){
if(root1==NULL&&root2==NULL) return 1;
if(root1!=NULL&&root2!=NULL) return (root1->data==root2->data)&&identicalTree(root1->left,root2->left)&&identicalTree(root1->right,root2->right);
}
int main(){
    fast();
    cout<<"enter tree 1:"<<endl;
    Node *root1=buildTree();
    cout<<"enter tree 2:"<<endl;
    Node *root2=buildTree();
    if(identicalTree(root1,root2))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
