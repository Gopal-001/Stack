#include <iostream>
#define size=10
using namespace std;

class Stack
{
    int size;
    int top;
    int *s;
public:
    Stack(){
        //size = 10;
        top = -1;
        s=new int[size];
    }

    Stack(int a,int *c);
    void Display();
    bool isEmpty();
    bool isFull();
    void Push(int x);
    int Pop();
    int Peek(int ind);
    int Stack_Length();
    int Stack_Top();


};

Stack::Stack(int a,int *c)
{
    s = new int[a];
    size = a;
    top = -1;
    for(int i=0;i<size;i++)
    {
        *(s+i)=*(c+i);
        top++;
    }
}
//display the elements in the stack
void Stack::Display()
{
    for(int i=top;i>=0;i--){
        cout<<*(s+i)<<" ";
    }
    cout<<endl;
}
//inserts an element in a stack
void Stack::Push(int x)
{
    if(!isFull()){
        top++;
        *(s+top) = x;
    }else{
        cout<<"Stack is Full!"<<endl;
    }
}
//deletes the topost element in a stack
int Stack::Pop()
{
    if(!isEmpty())
    {
        int x=*(s+top);
        top--;
        return x;
    }else
    {
        cout<<"Stack is Empty!"<<endl;
        return -1;
    }
}
//prints teh topmost element in a stack
int Stack::Peek(int ind)
{
    if(ind >=1 && ind <= top+1)
        return *(s + top - ind + 1);
    else
        cout<<"Invalid index value."<<endl;
}
//returns the length of stack
int Stack::Stack_Length()
{
    return top+1;
}
//returns if the stack is empty
bool Stack::isEmpty()
{
    return (top== -1)?true:false;
}

bool Stack::isFull()
{
    return (top == size-1)?true:false;
}

int Stack::Stack_Top()
{
    if(top == -1)
        return -1;
    else
        return *(s+top);
}


int main()
{
    int a[]={2,3,4,5,6,7};
    Stack s(6,a), p;
    cout<<s.Peek(1)<<" is the first element!!"<<endl;

    return 0;
}
