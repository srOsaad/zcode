#include "custom.cpp"

class Diagonal {
    private:
    int n;
    int *A;
    
    public:
    Diagonal();
    Diagonal(int n);
    ~Diagonal();
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};

Diagonal :: Diagonal(){
    n=2;
    A = new int[n];
}
Diagonal :: Diagonal(int n){
    this->n = n;
    A = new int[n];
}

Diagonal :: ~Diagonal(){
    delete[] A;
}

void Diagonal :: set(int i, int j, int x){ if(i==j) A[i-1]=x; }

int Diagonal :: get(int i, int j){ return A[i-1]; }

void Diagonal :: display(){ For(i,n) { For(j,n) wr (i==j ? A[i] : 0)<<' '; wr '\n'; }}

code {
    Diagonal matrix(5);
    matrix.set(1,1,5);
    matrix.set(2,2,2);
    matrix.set(3,3,7);
    matrix.set(4,4,1);
    matrix.set(5,5,9);

    wr matrix.get(3,3)<<" "<<matrix.get(1,3) <<'\n';

    matrix.display();

   // clearTerminal;
}