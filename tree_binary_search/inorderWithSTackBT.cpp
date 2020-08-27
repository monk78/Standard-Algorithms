/**                    Author:Monk_
 *                     Topic:inroder and predecessor                                                         **/
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
      Tree *left,*right;
      Tree(ll data){
        this->data=data;
        left=NULL;
        right=NULL;
      }
      Tree(){
        data=0;
        left=NULL;
        right=NULL;
      }
};
void InWS(Tree *root){
    stack<Tree *>st;
    Tree *curr=root;
    while(curr!=NULL||(!st.empty())){
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
          }
      curr=st.top();
      st.pop();
      cout<<curr->data<<" ";
      curr=curr->right;
    }
}
Tree *insert(Tree *root,ll key,ll pos){
    if(root==NULL)return new Tree(key);
    if(pos%2==0){
        root->left=new Tree(key);
    }
    else
        root->right=new Tree(key);
}
int main(){
    fast();
    ll N,num,i;
    Tree *root=NULL;
    cin>>N;
    cin>>num;
    root=new Tree(num);
    _for(i,2,N+1){
      cin>>num;
      insert(root,num,i);
    }
    InWS(root);
    return 0;
}

