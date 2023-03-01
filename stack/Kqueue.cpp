//implement k queue in arr
#include<iostream>
using namespace std;
class Queue{
    private:
    int *arr;
    int *front;
    int *rear;
    int *next;
    int k;
    int size;
    int freespace;
    public:
    Queue(int n,int k)
    {   this->size=n;
        this->k=k;
        arr=new int[n];
        front= new int [k];
        rear= new int[k];
        for(int i=0;i<k;i++)
        {
            front[i]=rear[i]=-1;
        }
        next= new int[n];
        for(int i=0;i<n;i++)
        {
            next[i]=i+1;
        }
        next[n-1]=-1;
        freespace=0;
    }
 void enqueue(int value ,int k)
 {
    if(freespace==-1)
    {
        cout<<"queue is full"<<endl;
        return ;
    }
    int index=freespace;
    freespace=next[index];

    if(front[k-1]==-1)// for first element
    {
        front[k-1]=index;
    }else{
        next[rear[k-1]]=index;
    } 
    rear[k-1]=index;
    next[index]=-1;
    arr[index]=value;
 }
 int dequeue(int k)
 {
   if(front[k-1]==-1)
   {
    cout<<"queue is empty"<<endl;
    return -1;
   }
  int index=front[k-1];
  front[k-1]=next[index];
  next[index]=freespace;
  freespace=index;
  return arr[index];
 }
};
int main() {

    Queue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15,1);
    q.enqueue(20, 2);
    q.enqueue(25,1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    cout << q.dequeue(1) << endl;

    return 0;
}