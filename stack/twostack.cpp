#include <iostream>
using namespace std;
 class stack{
     public:
     int *arr;
     int size;
     int top1;
     int top2;
      stack(int size)
      {
          this->size=size;
          top1=-1;
          top2=size;
          arr =new int [size];
      }
     void push1(int element)
     {
         if(top2 - top1>1)
         {
             top1++;
             arr[top1]=element;
         }else{
             cout<<"stack overflow"<<endl;
         }
     }
     void push2(int element)
     {
         if(top2 - top1>1)
         {
             top2--;
             arr[top2]=element;
         }else{
             cout<<"stack overflow"<<endl;
         }
     }
    void pop1()
    {
        if(top1>=0)
        {
            top1--;
        }else{
            cout<<"stack underflow"<<endl;
        }
    }
    void pop2()
    {
       if(top2<size)
        {
            top2++;
        }else{
            cout<<"stack underflow"<<endl;
        } 
    }
    int peek1()
    {
        if(top1>=0)
        {
            return arr[top1];
        }else
        {
            return -1;
        }
    }
    int peek2()
    {
        if(top2<size)
        {
            return arr[top2];
        }else
        {
            return -1;
        }
    }
      
 };

 int main()
 {  stack s(5);
    s.push1(1);
    s.push2(4);
    cout<<s.peek2();
     return 0;
 }