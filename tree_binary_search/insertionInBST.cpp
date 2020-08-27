
/**                    Author:Monk_
 *                     Topic:Insertion in binary search Tree:                                                         **/
#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define _for(i,a,b) for(i=a;i<b;i=i++)

#define _rfor(i,a,b) for(i=a;i>=b;i--)

#define mp(a,b) make_pair(a,b)

void fast(){
 ios_base::sync_with_stdio(false);
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
    int d;
    cin>>d;
    if(d==-1)return 0;
    Node *root=new Node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
void preorder(Node *root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void insertt(Node *root,int key){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        if(!temp->left){
            temp->left=new Node(key);
            break;
        }
        else{
            q.push(temp->left);
        }
        if(!temp->right){
            temp->right=new Node(key);
            break;
        }
        else{
            q.push(temp->right);
        }
    }
}
int main(){
    //fast();
    int key;
    Node *root=buildTree();
    cout<<"before insertion tree is:"<<" ";
    preorder(root);
    cout<<"enter the key u want to enter:";
    cin>>key;
    insertt(root,key);
    cout<<endl;
    preorder(root);
    return 0;
}
