#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node *next;
};

class Stack {
    node *TOP;
    int size=0;
    public:
    Stack() {TOP=0;}
    Stack(int x) {
        TOP=new node();
        TOP->data=x;
    }
    int Size() {return size;}
    int stackTop() {
        if(!TOP) {cout<<"empty!\n"; return -1;}
        return TOP->data;
    }
    int peek(int z) {
        if(z>=size || z<0) {return -1;}
        node *p=TOP;
        while(z--) p=p->next;
        return p->data;
    }
    void push(int x) {
        node *p=new node();
        if(!p) {
            cout<<"Overflow\n";
            return;
        }
        p->data=x;
        p->next=TOP;
        TOP=p;
        size++;
    }
    int pop() {
        if(!TOP){
            cout<<"Empty!\n";
            return -1;
        }
        node *p=TOP;
        int x=p->data;
        TOP=TOP->next;
        size--;
        delete p;
        return x;
    }
    void display(){
        node *p=TOP;
        while(p) {
            cout<<p->data<<' ';
            p=p->next;
        }
    }
};

int main() {
    Stack abc;
    abc.push(1);
    abc.push(2);
    abc.push(3);
    abc.push(4);
    abc.push(5);
    cout<<"Removing: "<<abc.pop()<<"  "<<abc.Size()<<'\n';
    abc.display();
    cout<<abc.stackTop()<<" "<<'\n';
    for(int i=0;i<abc.Size();i++) {
        cout<<abc.peek(i)<<' ';
    }
}