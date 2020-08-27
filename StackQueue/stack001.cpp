#include<bits/stdc++.h>
using namespace std;
class Stack{
private:
    class Node{
        public:
            int data;
            Node *next;
    };
    Node* head;
    int sze;
public:
    Stack(){
        head=NULL;
        sze=0;
    }
    void push(int x)
    {
        Node* tmp = new Node(x);
        tmp->next = head;
        head = tmp;
        sze++;
    }
    void pop(int x){
        if(empty())
                return;
        Node *tmp=head;
        head=head=head->next;
        --sze;
        delete(temp);
    }
    bool empty(){
    return (head==NULL);
    }
    int top(){
        if(empty())
                return -1;
        return head->data;
    }
    int size(){
    return sze;
    }


};
int main(){
    int n,num;
    Stack s;
    cout<<"enter total numbers:";
    cin>>n;
    while(n--){
        cin>>num;
        s.push(num);
    }
    return 0;
}
