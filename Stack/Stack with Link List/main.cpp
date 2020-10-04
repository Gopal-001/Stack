#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class Stack
{

    Node* top;
public:
    Stack(){top = NULL; }
    int length();
    bool isEmpty();
    bool isFull();
    void push(int x);
    int pop();
    int peek(int ind);
    void Display();
    int StackTop();
    ~Stack();

};

int Stack::length()
{
    Node* p=top;
    int c=0;
    while(p){
        c++;
        p=p->next;
    }
    return c;
}
bool Stack::isEmpty()
{
    if(top==NULL){
        cout<<"Stack underflow!"<<endl;
        return true;
    }else{
    return false;
    }
}

bool Stack::isFull()
{
    Node* t= new Node;
    if(t==NULL){
        cout<<"Stack Overflow!"<<endl;
        delete(t);
        return true;
    }else
        delete(t);
        return false;
}

void Stack::push(int x)
{
    if(isFull())
        return;
    Node* p=new Node;
    p->data = x;
    p->next = top;
    top = p;
}

int Stack::pop()
{
    if(isEmpty())
        return -1;
    Node* p=top;
    int ele = p->data;
    delete(p);
    top = top->next;
    return ele;
}

int Stack::peek(int ind)
{
    Node* p=top;
    int c = length();
    int x=-1;
    if(ind < 1 || ind > c)
        return x;
    else{
        for(int i=0;i<ind;i++)
            p=p->next;
        x=p->data;
        return x;
    }
}

int Stack::StackTop()
{
    int x = -1 ;
    if(isEmpty())
        return x;
    else{
        x = top->data;
        return x;
    }
}

void Stack::Display()
{
    Node* p=top;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
Stack::~Stack()
{
    Node* p=top;
    while(top){
        top=top->next;
        delete(p);
        p=top;
    }
}


bool isOperand(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'||c=='('||c==')')
        return false;
    else
        return true;
}
int OutPre(char c){
    if(c=='+'||c=='-')
        return 1;
    if(c=='*'||c=='/')
        return 3;
    if(c=='^')
        return 6;
    if(c=='(')
        return 7;
    return 0;
}
int InPre(char c){
    if(c=='+'||c=='-')
        return 2;
    if(c=='*'||c=='/')
        return 4;
    if(c=='^')
        return 5;
    if(c=='(')
        return 0;
    return 0;
}

char* InToPost(string s)
{
    Stack st;
    char *p = new char[s.length()];
    int i=0,j=0;
    while(s[i]!='\0'){
        if(isOperand(s[i]))
            *(p+ j++)=s[i++];
        else{
            if(OutPre(s[i]) > InPre(st.StackTop()))
                st.push(s[i++]);
            else if(OutPre(s[i]) < InPre(st.StackTop()))
                *(p+ j++)=st.pop();
            else{
                st.pop();
                i++;
            }
        }
    }
    while(!st.isEmpty())
        *(p+ j++)=st.pop();

    cout<<endl;
    return p;
}
int Evaluation(char* c)
{
    Stack s;
    int i=0;
    while(*(c+i)!='\0'){
        if(isOperand(*(c+i)))
            s.push(*(c+ i++)-'0');
        else{
                int a=s.pop();
                int b=s.pop();
            switch(*(c+ i++)){
                case '-':s.push(b-a);break;
                case '+':s.push(a+b);break;
                case '*':s.push(a*b);break;
                case '/':s.push(b/a);break;
                case '^':s.push(pow(b,a));break;
            }
        }
    }
    return s.pop();
}


int main()
{
    string a;
    cout<<"Enter the string of expressions: "<<endl;
    cin>>a;
    char* c=new char[a.length()];
    c=InToPost(a);
    for(int i=0;*(c+i)!='\0';i++)
        cout<<*(c+i);
    cout<<endl;
    int x=Evaluation(c);
    cout<<x<<endl;
    delete[] c;
    cout<<endl;
    return 0;
}
