#include <iostream>
using namespace std;
class queue{
    public:
    int *arr;
    int rear;
    int qfront;
    int size;

    queue(int size)
    { 
           this->size=size;
           qfront=rear=0;
           arr= new int [size];
    }  
    void enqueue(int data)
    {   
        if(rear==size)
        {
            cout<<"Queue is full"<<endl;
        }else{
               arr[rear]= data;
               rear++;
        }
    }
    void dqueue(){
        if(qfront==rear)
        {
            cout<<"Queue is empty"<<endl;
        }else{
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear)
            {
                qfront=0;
                rear=0;
            }
        }
    }
    int front()
    {
        if(qfront==rear)
        {
            return -1;
        }else{
            return arr[qfront];
        }
    }
    bool isEmpty()
    {
        if(qfront==rear)
        {
            return true;
        }else{
            return false;
        }
    }
};
int main()
{   queue q(1);
      q.enqueue(1);
      q.enqueue(2);
    return 0;
}