#include "../custom.cpp"

class LIST{
    public:
    int data;
    LIST *next;
} * first, *second, *last;

void INSERTL(LIST *L, int data);

void create(LIST *L, int A[], int n) {
    For(i,n) INSERTL(L,A[i]);
}

void display(LIST *p) {
    while(p) {
        wr p->data << ' ';
        p=p->next;
    }
}

void displayRe(LIST *p) {
    if(p) {
        cout<<p->data<<' ';
        displayRe(p->next);
    }
}

int count(LIST *p) {
    int x=0;
    while(p){
        x++;
        p=p->next;
    }
    return x;
}

int countReNeg(LIST *p) {
    if(!p) return 0;
    return countReNeg(p->next) + 1;
}

int countRePos(LIST *p) {
    if(p) return countRePos(p->next) + 1;
    return 0;
}

int sum(LIST *p) {
    int s=0;
    while(p) {
        s+=p->data;
        p=p->next;
    }
    return s;
}

int sumR(LIST *p){
    if(p) return p->data+sumR(p->next);
    return 0;
}

int MAX(LIST *p) {
    int m=INT_MIN;
    while(p) {
        m=max(m,p->data);
        p=p->next;
    }
    return m;
}

int MAXR(LIST *p) {
    if(!p) return INT_MIN;
    return max(MAXR(p->next),p->data);
}

LIST* SEARCH(LIST *p, int data) {
    while(p) {
        if(p->data==data) return p;
        p=p->next;
    }
    return p;
}

LIST* SEARCHR(LIST *p, int data, int i=0) {
    if(!p) return 0;
    if(p->data == data) return p;
    else return SEARCHR(p->next,data);
}

LIST* SEARCH_LB(LIST *p, int data) {
    LIST *f, *n;
    while(p) {
        if(p->data==data) {
            n=p;
            f->next=p->next;
            n->next=first;
            first=n;
            return n;
        }
        f=p;
        p=p->next;
    }
    return 0;
}

void INSERT(LIST *p, int pos, int data) {
    LIST *k=new LIST();
    k->data=data;

    if(pos==0) {
        k->next=p;
        first=k;
        return;
    }

    pos--;
    while(pos--) {
        if(!p) return;
        p=p->next;
    }

    k->next=p->next;
    p->next=k;
}

void INSERTL(LIST* l, int data) {
    LIST * t = new LIST();
    t->data=data;
    t->next=0;
    if(!l->next){l->data=data; last=l;l->next=new LIST();}
    else{
        last->next=t;
        last=t;
    }
}

void INSERTiS(LIST *p, int data) {
    LIST *i=new LIST(),*q=0;
    i->data=data;
    i->next=0;
    while(p && p->data<data) {
        q=p;
        p=p->next;
    }

    if(!q) {
        i->next = p;
        first=i;
        return;
    }
    q->next = i;
    i->next=p;
}

int DELETE(int pos) {
    LIST *p=first, *q=0;
    int x=-1;
    if(pos<0) return x;
    if(pos==0) {
        first=first->next;
        x=p->data;
    }
    else{
        while(pos--) {
            if(!p) return x;
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
    }
    delete p;
    return x;
}

bool IS_SORTED(LIST *p) {
    int x=INT_MIN;
    while(p) {
        if(p->data<x) {return false;}
        x=p->data;
        p=p->next;
    }
    return true;
}

bool IS_SORTEDR(LIST *p) {
    if(!p->next) return true;
    if(p->data>p->next->data) return false;
    return IS_SORTEDR(p->next);
}

void REMOVE_DUPLICATE_WITHOUT_DELETATION(LIST *p) {
    LIST *q;

    while(p) {
        q=p->next;
        while(q && p->data==q->data){q=q->next;}
        p->next = q;
        p=p->next;
    }
}

void REMOVE_DUPLICATE(LIST *p) {
    LIST *q=p->next;
    while(q) {
        if(p->data != q->data) {
            p=q;
        }
        else{
            p->next=q->next;
            delete q;
        }
        q=p->next;
    }
}

void REVERSE(LIST *p) {
    LIST *r=0,*q=0;

    while(p){
        r=q;
        q=p;
        p=p->next;

        q->next=r;
    }
    first=q;
}//3 pointer (slider)

void REVERSER(LIST *q, LIST *p) {
    if(p) {
        REVERSER(p,p->next);
        p->next=q;
    }
    else {
        first=q;
    }
}//recursion
//2 reverse again later

LIST *CONCAT(LIST *A, LIST *B) {
    LIST *N , *cur;
    if(A) {N = new LIST(); cur=N; N->data=A->data;A=A->next;}
    else if(B) {N = new LIST(); cur=N; N->data=B->data;B=B->next;}
    while(A) {
        LIST *T = new LIST();
        T->data=A->data;
        cur->next=T;
        cur=cur->next;
        A=A->next;
    }
    while(B) {
        LIST *T = new LIST();
        T->data=B->data;
        cur->next=T;
        cur=cur->next;
        B=B->next;
    }
    return N;
}

LIST *MERGE(LIST *A, LIST *B) {
    LIST *THIRD, *LAST;
    if(A->data<B->data) {
        THIRD=LAST=A;
        A=A->next;
        LAST->next=0;
    }
    else {
        THIRD=LAST=B;
        B=B->next;
        LAST->next=0;
    }
    while(A && B) {
        if(A->data<B->data) {
            LAST->next=A;
            LAST=A;
            A=A->next;
            //LAST->next=0;
        }
        else {
            LAST->next=B;
            LAST=B;
            B=B->next;
            //LAST->next=0;
        }
    }
    if(A) LAST->next=A;
    if(B) LAST->next=B;
    return THIRD;
}

bool isLoop(LIST *L) {
    LIST *B, *A;
    B=A=L;
    do {
        B=B->next;
        A=A->next;
        A=A?A->next : A;
        if(A==B) {return true;}
    } while(A && B);
    return false;
}

bool isLoop_CHECK_AND_ADD(LIST *L) {
    set<LIST *> check;
    while(L) {
        if(check.count(L)==1) return 1;
        check.insert(L);
        L=L->next;
    }
    return 0;
}

//circular
void DisplayC(LIST* l) {
    LIST* p=l;
    do{
        cout<<p->data<<' ';
        p=p->next;
    }while(p!=l);
    cout<<'\n';
}

void DisplayC_R(LIST *l) {
    static int flag = 0;
    static LIST * p = l;
    if (p!=l || flag==0)
    {
        flag=1;
        cout<<l->data<<' ';
        DisplayC_R(l->next);
    }
    flag=0;
    p=0;
}


code{
    wr "----------------------\n";
    first = new LIST();
    int arr[] = {1,2,3,4,5,6,7};
    create(first,arr,7);
    LIST *p = first, *ans=p;
    while (p)
    {
        if(p->next && p->next->next) {
            ans = ans->next;
        }
        else break;
        p=p->next->next;
    }
    wr ans->data<<'\n';
    display(first);
}