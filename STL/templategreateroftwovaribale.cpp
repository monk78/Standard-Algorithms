#include<iostream>
using namespace std;
class point{
    int x,y;
public:
    void get(){
        cin>>x>>y;
        cout<<endl;
    }
    void display(){
    cout<<x<<" "<<y<<endl;
    }
};
/*void swapp(point &p1,point &p2){
 int tempx,tempy;
 tempx=p1.x;
 tempy=p1.y;
 p1.x=p2.x;
 p1.y=p2.y;
 p2.x=tempx;
 p2.y=tempy;
}*/
int main(){
point p1,p2;
p1.get();
p2.get();
cout<<"before swapping:"<<endl;
p1.display();
p2.display();
//swapp(p1,p2);
cout<<"afrer swapping"<<endl;
p1.display();
p2.display();
return 0;
}
