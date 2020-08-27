//runtime polymorphism
#include<bits/stdc++.h>
using namespace std;
class media{
   protected:
       char title[50];
       float price;
   public:
    media(char *a,float b){
      strcpy(title,a);
      price=b;
    }
  virtual void display(){
    cout<<title<<" "<<price<<endl;
  };
};
class book:public media{
 int pages;
 public:
     book(char *s,float a,int p):media(s,a){
       pages=p;
     }
     void display(){
       cout<<title<<" "<<price<<" "<<pages<<endl;
     }
};
class tape:public media{
  float time;
  public:
      tape(char *s,float a,float t):media(s,a){
       time=t;
      }
      void display(){
        cout<<title<<" "<<price<<" "<<time<<endl;
      }
} ;
int main(){
  char *title=new char[30];
  float price,time;
  int pages;
  //book detail:
  cout<<"enter book detail:title,price,pages=>"<<endl;
  cin>>title>>price>>pages;
  book b1(title,price,pages);
  //tape detail:
  cout<<"enter tape details:title,price,time=>"<<endl;
  cin>>title>>price>>time;
  tape t1(title,price,time);
  media m1("rohit",334.56);
 m1.display();
  media *l[2];
  l[0]=&b1;
  l[1]=&t1;
  l[0]->display();
  l[1]->display();
return 0;
}
