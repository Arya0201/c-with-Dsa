#include<iostream>
using namespace std;
class Queue{
private:    
int *arr;
int front;
int rear;
int size;
public:
Queue(int size)
{
    this->size=size;
    front=rear=0;
    arr= new int [size];
}
void push(int data)
{
    if(rear==size)
    {
        cout<<"queue is full"<<endl;
    }else{
        arr[rear]=data;
        rear++;
    }
}
void pop()
{
    if(rear==front)
    {
        cout<<"queue is empty()"<<endl;
    }else{
        arr[front]=-1;
        front++;
        if(rear==front)
        {
            front=rear=0;
        }
    }
}
int top()
{
    if(rear==front)
    {
        return -1;
    }else{
        return arr[front];
    }
}
bool isEmpty()
{
    if(rear==front)
    {
        return true;
    }else{
        return false;
    }
}
};

int main()
{   Queue q(5);
   q.push(1);
   q.push(2);
   q.push(3);
   q.pop();
   cout<<q.top();
    return 0;
}