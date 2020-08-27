#include<iostream>
using namespace std;
#define max 100
class Stack{
   private:
    int top;
   public:
       int arr[max];
       Stack(){
        top=-1;
       }
       bool isEmpty();
       int pop();
       bool push(int x);
       int peek();
       void show(int n);
};
bool Stack::push(int x){
    if(top>=max)
        return false;
    else{
        arr[++top]=x;
        return true;
    }
}
bool Stack::isEmpty(){
    return (top<0);
}
void Stack::show(int n){
 //   cout<<"the opeartions:";
    while(top!=-1){
        cout<<arr[top]<<" ";
        top--;
    }
}
int main(){
    int n,num;
    class Stack s;
    cout<<"enter total numbers:";
    cin>>n;
    cout<<"enter total elements:";
    while(n--){
        cin>>num;
        s.push(num);
    }
    s.show(n);
    //cout<<"popped elemets"
    return 0;
}
