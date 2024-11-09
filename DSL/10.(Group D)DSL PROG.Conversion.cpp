/*Implement C++ program for expression conversion as infix to
postfix and its evaluation using stack based on given conditions:
1. Operands and operator, both must be single character.
2. Input Postfix expression must be in a desired format.
Only '+','-','*','/'operators are expected.*/

#include<iostream>
using namespace std;

class stacks
{
    private:
        char Stack[100];
        int top;

    public:
        stacks()
        {
            top=-1;
        }

        int isEmpty();
        int isFull();
        void push(char x);
        char pop();
        char getTop();
};

int stacks::isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    return 0;
}

int stacks::isFull()
{
    if(top==99)
    {
        return 1;
    }
    return 0;
}

void stacks:: push(char ch)
{
    if(!isFull())
    {
        top++;
        Stack[top]=ch;
    }
}

char stacks::pop()
{
    char ch;
    if(!isEmpty())
    {
        ch=Stack[top];
        top--;
    }
    return ch;
}

char stacks::getTop()
{
    char ch;
    if(!isEmpty())
    {
        ch=Stack[top];
    }
    return ch;
}

int isp(char ch)
{
    switch(ch)
    {
        case '+':
        case '-': 
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        case '(':
            return 0;
        case '#':
            return -2;    
    }
}

int icp(char ch)
{
    switch(ch)
    {
        case '+':
        case '-': 
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        case '(':
            return 4;    
    }
}

string intopost(stacks & s, string infix)
{
    int i;
    char x,ch;
    s.push('#');
    string postfix;

    for(i=0;i<infix.length();i++)
    {
        ch=infix[i];
        if(ch>='a' && ch<='z')
        {
            postfix+=ch;
        }

        else if(ch=='(')
        {
            s.push(ch);
        }

        else if(ch==')')
        {
            while(s.getTop()!='(')
            {
                x=s.pop();
                postfix+=x;
            }
            x=s.pop();
        }
        else
        {
            while(isp(s.getTop())>=icp(ch))
            {
                x=s.pop();
                postfix+=x;
            }
            s.push(ch);
        }
    }

    while(!s.isEmpty())
    {
        x=s.pop();
        if(x!='#')
        {
            postfix+=x;
        }
    }
    return postfix;
}

int main()
{
    stacks s;
    string infix,post;
    cout<<"Enter an expression in infix form :";
    cin>>infix;
    post=intopost(s,infix);
    cout<<"PostFix of the expression is :"<<post<<endl;
    return 0;
}

//Output
/*
Enter an expression in infix form :((a*b)+c)
PostFix of the expression is :ab*c+
*/

