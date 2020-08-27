#include<iostream>
using namespace std;
template<class T>
void fun(T a){

cout<<"the main template function:"<<a<<endl;

}
template<>
void fun(int a){
cout<<"speccialized function for int:"<<a+2<<endl;
}
template<>
void fun(char x){
cout<<"specailized for char:"<<x<<endl;
}
int main(){
fun<char>('a');
fun<int>(10);
fun<float>(12.23);
return 0;
}
