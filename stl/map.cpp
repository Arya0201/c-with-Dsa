#include<iostream>
using namespace std;
#include<map>
int main()
{   //it will store key and value
//key will unique but value can be same
//print sorted order
   map<int,string> m;
   m[1]="love";
   m[13]="kumar";
   m[2]="babbar";
    m.insert({3,"arya"});
    cout<<"before erase:"<<endl;
 for(auto i:m)
 {
     cout<<i.first <<" "<<i.second<<endl;
 }
 cout<<"finding 13:"<<m.count(13);
 cout<<endl<<"after erase:"<<endl;
 m.erase(13);
 for(auto i:m)
 {
     cout<<i.first <<" "<<i.second<<endl;
 }

    return 0;
}