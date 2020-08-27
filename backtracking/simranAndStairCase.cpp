    #include<iostream>
    using namespace std;
    int countt(int stair,int step){
        if(step<stair)return countt(stair,step+1)+countt(stair,step+2)+countt(stair,step+3);
        else if(step==stair)return 1;
        else return 0;
    }
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int stair;
        cin>>stair;
        cout<<countt(stair,0)<<endl;
        return 0;
    }
