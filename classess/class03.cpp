#include<bits/stdc++.h>
using namespace std;
class String{
 char *name;
 int len;
 public:
     String(){
      len=0;
      name=new char[len+1];
     }
     String(char *s){
      len=strlen(s);
      name=new char[len+1];
      strcpy(name,s);
     }
     void display(){
      cout<<name<<endl;
     }
     void join(String,String );
};
void String::join(String a,String b){
  len=a.len+b.len;
  delete name;
  name=new char[len+1];
  strcpy(name,a.name);
  strcat(name,b.name);
}
int main(){
  char *first="Joseph";
  String name1(first),name2("Louis"),name3("Lagrange"),s1,s2;
  s1.join(name1,name2);
  s2.join(s1,name3);
  s1.display();
  cout<<"\ns2"<<endl;
  s2.display();
return 0;
}
