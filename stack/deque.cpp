#include<iostream>
using namespace std;
class Deque{
    private:
    int *arr;
    int size;
    int front,rear;
    public:
     Deque(int size)
     {
        this->size=size;
        arr =new int [size];
        front=rear=-1;
     }
     void pushFront(int data)
     {  // deque is empty or not
        if((front==0 && rear==size-1) || (rear==(front-1)%(size-1)))
        {
             cout<<"deque is full"<<endl;
        }else if(front==-1){  // insert first element
            front=rear=0;
        }else if(front==0){ // maintain cycle
          front=size-1;
        }else{
         front--;
        }
        arr[front]=data;
     }
     void pushRear(int data)
     {
        //is full or not 
        if((front==0 && rear==size-1) || (rear==(front-1)%(size-1)))
        {
            cout<<"deque is full"<<endl;
        }else if(rear==-1)
        {
            front=rear=0;
        }else if(rear==size-1 && front!=0)
        {
            rear=0;
        }else{
            rear++;
        }
        arr[rear]=data;
     }

     void popRear()
     {
        //check deque is empty or not
        if(front==-1)
        {
            cout<<"deque if empty"<<endl;
            return;
        }
         if(front==rear)
        {
            front=rear=-1;
        }else if(rear==0){
            rear=size-1;
        }else{
            rear--;
        }
     }
     void popFront()
     {
        if(front==-1)
        {
            cout<<"deque is empty"<<endl;
            return;
        }
        if(front==rear)
        {
            front=rear=-1;
        }else if(front==size-1)
        {
            front=0;
        }else{
            front++;
        }
     }
};
int main()
{
    return 0;
}