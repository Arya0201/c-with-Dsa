#include<iostream>
using namespace std;
#include<vector>

int main()
{ //it is dynamice 
  vector<int> a(5,1);// all 5 are assigned 1 value
  for (int i:a)
  {
      /* code */
      cout<<i<<ends;

  }
  cout<<endl;
  //copy  one  vector into another vector
     vector<int> paste(a);

    vector<int> v; // it will auto increse size doubly
    cout<<"capacity:"<<v.capacity();
    v.push_back(1);
    cout<<endl<<"capacity:"<<v.capacity();
    v.push_back(2);
     cout<<endl<<"capacity:"<<v.capacity();
     v.push_back(3);
     cout<<endl<<"capacity:"<<v.capacity()<<endl;
     cout<<"size:"<<v.size()<<endl;
     cout<<"AT 2nd index:"<<v.at(2)<<endl;
     cout<<"front:"<<v.front()<<endl;
     cout<<"back:"<<v.back();
     cout<<endl<<"Before pop:"<<endl;
     for(int i:v)
     {
         cout<<i<<ends;
     }cout<<endl;
     v.pop_back();
     cout<<"after pop:"<<endl;
     for (int i:v)
     {
         /* code */
         cout<<i<<ends;
     }cout<<endl;

     //clear size
     v.clear();
     cout<<v.size();


    return 0;
}