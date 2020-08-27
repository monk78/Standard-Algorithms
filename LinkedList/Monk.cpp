#include<bits/stdc++.h>
using namespace std;
void showq(deque < pair<int,int> > q){
while(!q.empty()){
    pair< int, int >p=q.front();
    cout<<p.first<<" "<<p.second<<endl;
    q.pop_front();
}
}
int serchx(deque < pair<int,int> >q,int sch){
    int count=0;
    while(!q.empty()){
        pair< int, int >p=q.front();
        if(p.first!=sch){
            q.pop_front();
            count++;}
        else
            return (count+1);

    }
    return 0;
}
int main(){
deque < pair <int,int> > q;
int t;
cin>>t;
while(t--){
char type;
cin>>type;
if(type=='E'){
    int sch,roll;
    cin>>sch>>roll;
    if(q.empty())
        q.push_back(make_pair(sch,roll));
    else{
        int op=serchx(q,sch);
        if(op==0)
            q.push_back(make_pair(sch,roll));
        else{
                deque < pair<int,int> >t;
                for(int i=0;i<op;i++){
                    pair< int,int >s=q.front();
                    t.push_front(s);
                    q.pop_front();
                }
                q.push_front(make_pair(sch,roll));
                for(int i=0;i<op;i++){
                    pair< int,int >s2=t.front();
                    q.push_front(s2);
                    t.pop_front();
                }
            }

        }
    }
else{
     pair< int, int >p=q.front();
     cout<<p.first<<" "<<p.second<<endl;
     q.pop_front();
}
}
return 0;

}
