#include "../custom.cpp"

class Node {
    public:
    int data;
    Node *next;
}*Head;

void Create(int A[], int size) {
    Node *t, *p;
    Head = new Node();
    p=Head;
    Head->data = A[0];
    Head->next=Head;
    For_(i,1,size) {
        t = new Node();
        t->data = A[i];
        t->next = Head;
        p->next=t;
        p=p->next;
    }
}

void Display(Node *p) {
    do {
        cout<<p->data<<' ';
        p=p->next;
    }
    while(p!=Head);
    cout<<'\n';
}

void Display_R(Node *p) {
    static bool flag = 0;
    static Node *l = p;
    if(p!=l || !flag) {
        flag = 1;
        cout<<p->data<<' ';
        Display(p->next);
    }
    flag = 0;
    l=0;
}

int Size(Node *p) {
    int s = 0;
    if(p) do {
        s++;
        p=p->next;
    }while (p!=Head);
    return s;
}

void Insert(Node *p, int index, int x) {
    if(index<0 || Size(p)<index) return;
    Node *t = new Node();
    t->data = x;
    if(index==0) {
        if(Head) {
            do{
                p=p->next;
            }while(p->next!=Head);
            p->next=t;
            t->next=Head;
            Head=t;
        }
        else{
            Head=t;
            t->next=Head;
        }
    }
    if(index==1) {
        t->next = Head->next;
        Head->next = t;
    }
    if(index<2) return;
    while(--index) p=p->next;
    cout<<p->data<<" "<<p->next->data<<'\n';
    t->next=p->next;
    p->next=t;
    cout<<p->data<<" "<<p->next->data<<'\n';
}

int Deletee(Node *p, int index) {
    if(index<0 || index>=Size(Head)) return -1;
    int x = -1;
    if(index==0) {
        while (p->next!=Head) p=p->next;
        x=Head->data;
        p->next=Head->next;
        p=Head;
        Head=Head->next;
        delete p;
    }
    else if(index == 1) {
        x=Head->next->data;
        p=Head->next;
        Head->next=p->next;
        delete p;
    }
    else{
        while(--index) p=p->next;
        Node *q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
    }
    return x;
}

code {
    int arr[] = {1,2,3,4,5};
    Create(arr,5);
    Deletee(Head,1);
    Display_R(Head);
    Deletee(Head,2);
    Display(Head);
    Deletee(Head,0);
    Display(Head);
    //wr '\n';
    wr Size(Head);
}