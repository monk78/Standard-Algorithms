/**                    Author : Monk_
 *                     Topic : Mirror_Images                                                        **/
#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define _for(i,a,b) for(i=a;i<b;i++)

#define _rfor(i,a,b) for(i=a;i>=b;i--)

#define mp(a,b) make_pair(a,b)

void fast(){
 ios_base::sync_with_stdio(false);
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
void checkMirror(Tree *Lside,Tree *Rside,ll key,Tree *&temp){
    if(Lside==NULL||Rside==NULL)return;
    if(Lside->data==key){
        temp=Rside;
        return;
    }
    else if(Rside->data==key){

        temp=Lside;
        return;
    }
    checkMirror(Lside->left,Rside->right,key,temp);
    checkMirror(Lside->right,Rside->left,key,temp);
}
void Parent(Tree *root,ll baap,Tree **s){
if(root==NULL)return;
if(root->data==baap)(*s)=root;
Parent(root->left,baap,&s);
Parent(root->right,baap,&s);
}
Tree *insert(ll key){
Tree *temp=new Tree(key);
return temp;
}
int main(){
    fast();
    ll N,Q,baap,beta,key;
    char sign;
    cin>>N>>Q;
    Tree *root=NULL;
    root=insert(1);
    N-=1;
    while(N--){
        cin>>baap>>beta>>sign;
        Tree *s=NULL;
        Parent(root,baap,&s);
        if(s!=NULL){
        if(sign=='L')
            s->left=insert(beta);
        }
        else{
            s->right=insert(beta);

        }
        s=NULL;
    }
    while(Q--){
        cin>>key;
        if(key==1)cout<<"1"<<endl;
        else{
            Tree *temp=NULL;
            if(root)
                checkMirror(root->left,root->right,key,temp);
            if(temp==NULL)
                cout<<"-1"<<endl;
            else
                cout<<temp->data<<endl;

        }
    }
    return 0;
}
