/**                    Author:Monk_
 *                     Topic:maximum difference between ancestor and its node:                                                         **/
#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define _for(i,a,b) for(i=a;i<b;i++)

#define _rfor(i,a,b) for(i=a;i>=b;i--)

#define m_p(a,b) make_pair(a,b)

void fast(){
 std::ios_base::sync_with_stdio(false);
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
int maxans(Node *root,int *res){
    if(root==NULL)return INT_MAX;
    if(root->left==NULL && root->right==NULL)return root->data;
    int val=min(maxans(root->left,res),maxans(root->right,res));
    *res=max(*res,root->data-val);
    return min(val,root->data);
}
int maxdiff(Node *root){
  int res=INT_MIN;
  maxans(root,&res);
  return res;
}
int main(){
    fast();
    Node *child;
    int test,n,n1,n2;
    char ch;
    cin>>test;
    while(test--){
        map<int,Node*>m;
        cin>>n;
        Node *root=NULL;
        while(n--){
          Node *parent;
          cin>>n1>>n2>>ch;
            if(m.find(n1)==m.end()){
                parent=new Node(n1);
                m[n1]=parent;
                if(root==NULL)
                    root=parent;
            }
            else{
              parent=m[n1];
              child=new Node(n2);
              if(ch=='L') parent->left=child;
              if(ch=='R')parent->right=child;
              m[n2]=child;
            }
        }
        cout<<maxdiff(root)<<endl;
    }
    return 0;
}
