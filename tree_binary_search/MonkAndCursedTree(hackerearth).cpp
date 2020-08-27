

    /**                    Author:Monk_
     *                     Topic:Monk and Cursed Tree                                                         **/
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
    };

    Tree *insert(Tree *root,ll key){
     if(root==NULL)return new Tree(key);
     if(key<root->data) root->left=insert(root->left,key);
     if(key>root->data) root->right=insert(root->right,key);
     return root;
    }

    void bfs(Tree *root){
    queue<Tree*>q;
    q.push(root);
    while(!q.empty()){
        Tree *temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
     }
    }

    Tree *LCA(Tree *root,ll num1,ll num2){
      if(root==NULL)return 0;
      if(root->data>num1&&root->data>num2)
            return LCA(root->left,num1,num2);
      if(root->data<num1&&root->data<num2)
            return LCA(root->right,num1,num2);
       return root;
    }
    void maxvl(Tree *root,ll num1,ll &maxl){
        if(root==NULL)return;
        if(root->data>num1){
                maxl=max(maxl,root->data);
             maxvl(root->left,num1,maxl);
        }
      if(root->data<num1){
            maxl=max(maxl,root->data);
             maxvl(root->right,num1,maxl);
      }
      maxl=max(maxl,root->data);
    }

    int main(){
        fast();
        Tree *root=NULL;
        ll i,N,one,two,num;
        cin>>N;
        cin>>num;
        root=insert(root,num);
        _for(i,1,N){
            cin>>num;
            insert(root,num);
        }
        cin>>one>>two;
        Tree *lca=LCA(root,one,two);
        ll maxl=-1,maxr=-1;
       //maxv(lca,one,two)<<endl;
        maxvl(lca,min(one,two),maxl);
        maxvl(lca,max(one,two),maxr);
        cout<<max(maxl,maxr)<<endl;
        return 0;
    }
