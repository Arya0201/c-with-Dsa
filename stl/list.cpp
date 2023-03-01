#include<iostream>
using namespace std;
#include<list>
int main()
{ list<int> l;
   l.push_back(2);
   l.push_front(1);
   //a copy list into another list
   list<int> a(l);
   list<int> v(5,100);//5 element assigned 100 values
   for (int i:l)
   {
       /* code */
       cout<<i<<ends;
   }
   cout<<endl;
   l.erase(l.begin());
   cout<<"after erase:\n";
   for (int i:l)
   {
       /* code */
       cout<<i<<ends;
   }
   cout<<"size of list:"<<l.size();

   
    return 0;
}