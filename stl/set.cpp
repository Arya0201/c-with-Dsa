#include<iostream>
using namespace std;
#include<set>
int main()
{   //it will store unique element
     //modification is not allowed
     //sorted order ma print thay
     set<int> s;
     s.insert(5);
     s.insert(5);
     s.insert(5);
     s.insert(1);
     s.insert(6);
     s.insert(0);

    /*
    set<int>::iterator itr;
    for (itr=s.begin();itr!=s.end();itr++)
    {
        
        cout<<*itr<<" ";
    } */
    for(auto i:s)
    {
        cout<<i<<ends;
    }
     cout<<endl;
  s.erase(s.begin());// it will erase 1st index
  for(auto i:s)
    {
        cout<<i<<ends;
    }
     cout<<endl;
   cout<<"5 is present or not:"<<s.count(5);//it will check 5 is present or not
   

    return 0;
}