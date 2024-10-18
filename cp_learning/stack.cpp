#include "..\custom.cpp"

template<class T>
class Stack {
    int size;
    T *arr;
    int top;
    public:
    Stack() {
        arr = new T[10];
        size=10;
        top=-1;
    }
    Stack(int size) {
        this->size = size;
        arr = new T[size];
        top=-1;
    }
    ~Stack() {
        delete[] arr;
    }
    void push(T x);
    T pop();
    T stacktop();
    T peek(int i);
    int stacksize();
    bool isEmpty();
    bool isFull();
    void display();
};

template<class T>
void Stack<T>::push(T x) {
    if(top==size-1) wr "Overflow\n";
    else {
        top++;
        arr[top] = x;
    }
}

template<class T>
T Stack<T>::pop() {
    if(top==-1) wr "Underflow\n";
    else {
        top--;
        return arr[top+1];
    }
}

template<class T>
T Stack<T>::stacktop() {
    return top==-1 ? -1 : arr[top];
}

template<class T>
T Stack<T>::peek(int i) {
    if(top-i<0) {wr "Invalid index\n"; return -1;}
    return arr[top-i];
}

template<class T>
int Stack<T>::stacksize() {
    return top+1;
}

template<class T>
bool Stack<T>::isFull() {
    return top==size-1;
}

template<class T>
bool Stack<T>::isEmpty() {
    return top==-1;
}

template<class T>
void Stack<T>::display() {
    for(int i=top; i>-1; i--) wr arr[i] << ' ';
    wr '\n';
}

code{
    Stack<int> check;
    wr check.isFull()<< " " <<check.isEmpty()<<'\n';
    check.push(1);
    check.push(2);
    check.push(3);
    check.push(4);
    check.push(5);
    check.pop();
    wr check.stacksize()<<'\n';
    check.display();
    wr check.isFull()<< " " <<check.isEmpty() << '\n';
    check.push(5);
    check.push(6);
    check.push(7);
    check.push(8);
    check.push(9);
    check.push(10);
    wr check.isFull()<< " " <<check.isEmpty();
}