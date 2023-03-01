#include<iostream>
using namespace std;
#include<deque>
int main()
{  deque<int> d;
    d.push_back(1);
    d.push_front(2);
    d.push_front(3);
    cout<<"at index:"<<d.at(1)<<endl;
    cout<<"first element:"<<d.front()<<endl;
    cout<<"last element:"<<d.back()<<endl;
     for (int i:d)
     {
         /* code */
         cout<<i<<ends;
     }
     cout<<endl;
     d.pop_back();
     d.pop_front();
     for(int i:d)
     {
         cout<<i;
     }
     cout<<endl;
      cout<<"empty or not:" <<d.empty()<<endl;
      d.push_back(4);
      //how we erase
      d.erase(d.begin(),d.begin()+1);
        for(int i:d)
     {
         cout<<i;
     }
     cout<<endl;
     
    return 0;
}