/**                    Author:Monk_
 *                     Topic:                                                         **/
#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define _for(i,a,b) for(i=a;i<b;i++)

#define _rfor(i,a,b) for(i=a;i>=b;i--)

#define mp(a,b) make_pair(a,b)

void fast(){
 std::ios_base::sync_with_stdio(false);
 cout.tie(NULL);
}
class Tree{
public:
    ll data;
    Tree *left,*right,*parent;
    Tree(int data){
    this->data=0;
    left=NULL;
     right=NULL;
      parent=NULL;
    }
};
Tree  *insert(Tree *root,ll key){
    if(root==NULL)return new Tree(key);
    if(key<=root->data){
        root->left=insert(root->left,key);
        root->parent=root;
    }
    else{
         root->right=insert(root->right,key);
        root->parent=root;
    }
    return root;
}
Tree *minvalue(Tree *node);
Tree *IS(Tree *root,Tree *node){
    if(node->right!=NULL)return minvalue(node->right);
    Tree *p=node->parent;
    while(p!=NULL && node==p->right){

        node=p;
        p=p->parent;
    }
  return p;
}
Tree *minvalue(Tree *node){
 Tree *current=node;
 while(current->left!=NULL)
    current=current->left;
 return current;
}
int main(){
    fast();

    return 0;
}
