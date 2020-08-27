#include<iostream>
using namespace std;
class base{
  public:
      void  virtual display(){
        cout<<"base display"<<endl;
      }
      void  virtual show(){
        cout<<"base show :"<<endl;
      }
};
class derived:public base{
  public:
      void display(){
        cout<<"derived display:"<<endl;
      }
      void show(){
        cout<<"derived show"<<endl;
      }
};
int main(){
  base b;
  derived d;
  base *bptr;
  cout<<"pointing to base:"<<endl;
  bptr=&b;
  bptr->display();
  bptr->show();
  cout<<"poinitng to derived:"<<endl;
  bptr=&d;
  bptr->display();
  bptr->show();
return 0;
}
