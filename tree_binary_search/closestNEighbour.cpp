/**                    Author:Monk_
 *                     Topic:u have to find closest neighbour in a Tree                                                         **/
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
        Tree *left,*right;
        int data;
        Tree(){
           left=NULL;
           right=NULL;
           data=0;
        }
};
Tree *insert(Tree *root,ll key){
  if(root==NULL)return new Tree(key);
  if(key<root->data)root->left=insert(root->left,key);
  if(key>root->data)root->right=insert(root->right,key);
}
int main(){
    fast();


    return 0;
}
