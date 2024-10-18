#include "../custom.cpp"

class Node {
    public:
    int data = -1;
    Node *prv;
    Node *next;
}*first;

void create(int A[], int size) {
    Node *p;
    first = new Node();
    p=first;
    first->data=A[0];
    first->next=0;
    first->prv=0;
    For_(i,1,size) {
        Node *t = new Node();
        t->data = A[i];
        p->next=t;
        t->prv=p;
        t->next=0;
        p=p->next;
    }
}

int Size(Node *p) {
    int s = 0;
    while(p) {
        s++;
        p=p->next;
    }
    return s;
}

void Display(Node *p, int x = 0) {
    while(p) {
        if(!x) wr p->data<<' ';
        else wr (p->prv ? p->prv->data : 0)<<' '<<p->data<<' '<<(p->next ? p->next->data : 0)<<'\n';
        p=p->next;
    }
    wr '\n';
}

void Insert(int data, int index) {
    if(index<0 || index>Size(first)) return;
    Node *t = new Node();
    t->data = data;
    if(index==0) {
        t->next = first;
        first->prv = t;
        t->prv = 0;
        first = t;
        return;
    }
    Node *p = first, *q;
    while(--index) p=p->next;
    q=p->next;
    p->next = t;
    t->prv = p;
    t->next = 0;
    if(q) {
        t->next = q;
        q->prv = t;
    }
}

int Deletee(int index) {
    if(index<0 || index>Size(first)-1) return -1;
    int x = -1;
    Node *p = first;
    if(index==0) {
        x=first->data;
        first=first->next;
        delete p;
        if(first) first->prv=0;
    }
    else {
        while (index--) p = p->next;
        p->prv->next=p->next;
        if(p->next) p->next->prv=p->prv;
        x=p->data;
        delete p;
    }
    return x;
}

void Reverse(Node *p) {
    Node *temp;
    while(p) {
        temp=p->next;
        p->next = p->prv;
        p->prv = temp;
        if(!p->prv) first=p;
        p=p->prv;
    }
}

code{
    int arr[] = {10,20,30,40,50};
    create(arr,5);
    Reverse(first);
    Display(first);
    wr '\n';
    wr Size(first);
}