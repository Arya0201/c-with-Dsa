#include <iostream>
using namespace std;
class queue{
    public:
    int *arr;
    int front,rear;
    int size;
    queue(int size)
    {
          this->size=size;
          front=rear=-1;
          arr = new int [size];
    }
    void enqueue(int data)
    {   //to check whether queue is full
        if(((front== 0) && rear==size-1) || ( rear==(front-1)%(size-1)))
        {
            cout<<"circular queue is full"<<endl;
        }
        else if(front==-1){   // first element to push
               front=rear=0;
               arr[rear]=data;
        }
        else if(rear==size-1 && front!=0){
              rear=0;   //to maintain cyclic nature
              arr[rear]=data;
        }
        else{
            rear++;
            arr[rear]=data;
        }
    }
    void dequeue()
    {
        if(front==-1)// to check queue is empty 
        {
            cout<<"circular queue is empty"<<endl;
        }
        else if(front==rear) //single element is present 
        {
            front=rear=-1;
        }
        else if(front==size-1)
        {
            front=0; //to maintain cyclic nature
        }
        else{
            front++;
        }
    }
};
int main()
{     queue q (5);
          q.enqueue(1);
          q.enqueue(2);
          q.dequeue();
    return 0;
} 