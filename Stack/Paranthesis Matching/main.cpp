#include <bits/stdc++.h>
#include <string>

using namespace std;

class Node
{
public:
    char data;
    Node* next;
};

class Stack
{
    Node* top;
public:
    Stack(){top=NULL;}
    void push(char x);
    char pop();
    bool isEmpty();
    bool isFull();
    char stackTop();
    bool ParaMatching(string);
    bool MoreParaMatching(string);
};
bool Stack::isFull()
{
    Node* t= new Node;
    if(t==NULL){
        cout<<"Stack overflow."<<endl;
        return true;
    }else
        return false;
}
bool Stack::isEmpty()
{
    if(top != NULL)
        return false;
    else{
        cout<<"Stack underflow."<<endl;
        return true;
    }
}
void Stack::push(char x)
{
    if(isFull())
        return;
    else{
        Node* t=new Node;
        t->data = x;
        t->next=top;
        top=t;
    }
}
char Stack::pop()
{
    if(isEmpty())
        return -1;
    else{
        Node* p=top;
        top = top->next;
        int ele=p->data;
        delete(p);
        return ele;
    }
}

char Stack::stackTop()
{
    if(isEmpty())
        return -1;
    else
        return top->data;
}



bool Stack::ParaMatching(string s)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '('){
            this->push(s[i]);
           }
        if(s[i] == ')'){
            if(this->isEmpty())
                return false;
            this->pop();
        }
    }
    if(!isEmpty())
        return false;
    return true;
}

bool Stack::MoreParaMatching(string s)
{
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' ||s[i]=='[')
            this->push(s[i]);
        else if(s[i]==')' || s[i]=='}'||s[i]==']'){
            if(this->stackTop() == '(' && s[i]==')'){
                if(!this->isEmpty())
                    this->pop();
                else
                    return false;
            }
            else if(this->stackTop() == '{' && s[i]=='}'){
                if(!this->isEmpty())
                    this->pop();
                else
                    return false;
            }else if(this->stackTop() == '[' && s[i]==']' ){
                if(!this->isEmpty())
                    this->pop();
                else
                    return false;
            }
        }
    }
    if(!this->isEmpty())
        return false;
    else
        return true;
}


void solve()
{
    string s;
    cin>>s;
    Stack stk;
    if(stk.MoreParaMatching(s)){
        cout<<"Balanced Paranthesis."<<endl;
    }else{
        cout<<"Unbalanced Paranthesis."<<endl;
    }
}


int main()
{
    solve();
    return 0;
}
