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
Tree *insert(Tree *root,ll key){
    if(root==NULL)return new Tree(key);
    if(key<root->data)
        root->left=insert(root->left,key);
    else if(key>root->data)
        root->right=insert(root->right,key);
}
void check0(Tree *r,ll X,ll &countt){
    Tree *root=r;
   if(root==NULL)return;
   if(X==root->data)
       ++countt;
    if(X<root->data)++countt;

      check0(root->right,X,countt);
    check0(root->left,X,countt);

}
void check1(Tree *r,ll X,ll &countt){
    Tree *root=r;
   if(root==NULL)return;
   if(X<root->data)
       ++countt;

     check1(root->right,X,countt);
    check1(root->left,X,countt);

}
/*void checkGreater(Tree *root,ll key,ll &countt){
   if(root==NULL)return;
   if(key<root->data){

      checkGreater(root->left,key,countt);
   }
   else if(key>root->data){
       ++countt;
    checkGreater(root->right,key,countt);
   }
}
*/
int main(){
    fast();
    int i,num;
    Tree *root=NULL;
    ll N,Q;
    cin>>N;
    cin>>num;
    root=insert(root,num);
    _for(i,1,N){
        cin>>num;
        insert(root,num);
    }
    cin>>Q;
    ll a,key;
    while(Q--){
            ll countt=0;
        cin>>a>>key;
        if(a==0){
            check0(root,key,countt);
            cout<<countt<<endl;
            countt=0;
        }
        else if(a==1){
            check1(root,key,countt);
        cout<<countt<<endl;
        countt=0;
        }

    }
    return 0;
}
