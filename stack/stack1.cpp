#include <iostream>
using namespace std;
class stack{
    private:
    int *arr;
    int size;
    int top;
    public:
    stack(int size)
    {
        this->size=size;
        arr= new int[size];
        top=-1;
    }
    void push(int d)
    {
        if(size-top>1)
        {
            top++;
            arr[top]=d;
        }else{
            cout<<"stck is overflow"<<endl;
        }
    }
    void pop()
    {
        if(top>=0)
        {
            top--;
        }else{
            cout<<"stack underflow"<<endl;
        }
    }
    int peek()
    {
        if(top>=0)
        {
            return arr[top];
        }else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }
    bool isempty()
    {
        if(top>=0)
        {
            return false;
        }else{
            return true;
        }
    }
};
int main()
{  stack s(5);
     
    return 0;
}