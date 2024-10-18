#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
};

class LinkedList {
    private:
    Node *MAIN;
    
    public:
    LinkedList(){MAIN=0;}
    LinkedList(int A[], int n);
    ~LinkedList();
    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Size();
};

LinkedList::LinkedList(int A[], int size) {
    if(size<1) {return;}
    Node *t, *last;
    MAIN = new Node();
    last = MAIN;
    MAIN->data = A[0];
    last = MAIN;
    for(int i=1;i<size;i++){
        t = new Node();
        t->data = A[i];
        t->next = 0;
        last->next = t;
        last = last->next;
    }
}

LinkedList::~LinkedList() {
    Node *p=MAIN;
    while (p)
    {
        MAIN=MAIN->next;
        delete p;
        p=MAIN;
    }
}

void LinkedList::Display() {
    Node *p=MAIN;
    while(p) {
        cout<<p->data<<' ';
        p=p->next;
    }
    cout<<'\n';
}

int LinkedList::Size() {
    int sz = 0;
    Node *p=MAIN;
    while(p) {
        sz++;
        p=p->next;
    }
    return sz;
}

void LinkedList::Insert(int x, int index = -1) {
    Node *p=MAIN, *n=new Node();
    n->data = x;
    if(index == -1) {
        while(p->next) p=p->next;
        p->next=n;
        return;
    }
    if(index == 0) {
        n->next=p;
        MAIN=n;
        return;
    }
    while(p && --index) {
        p=p->next;
    }
    if(index) return;
    n->next=p->next;
    p->next=n;
}

int LinkedList::Delete(int index) {
    if(index<0 || index>Size()-1) return -1;
    int x = -1;

    Node *p=MAIN;

    if(!index) {
        x=MAIN->data;
        MAIN=MAIN->next;
        delete p;
    }
    else {
        while (--index) p=p->next;
        Node *t = p->next;
        x=t->data;
        p->next=p->next->next;
        delete t;
    }
    return x;
}