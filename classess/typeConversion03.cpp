//-> conversion:---
# include<iostream>
using namespace std;
class parent{
  public:
      int a;
      parent(int x){
        a=x;
      }
      parent * operator->(){
        return this;
      }
};
int main(){
   parent p(6);
   parent *ptr;
   ptr=&p;
   cout<<ptr->a<<endl;
   cout<<p->a<<endl;

return 0;
}
