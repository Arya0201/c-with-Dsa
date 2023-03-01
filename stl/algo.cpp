#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
int main()
{ 
    vector<int> v;
   v.push_back(1);
   v.push_back(17);
   v.push_back(5);
   v.push_back(26);
   v.push_back(15);
   cout<<"finding:"<<binary_search(v.begin(),v.end(),5)<<endl;
   cout<<"uperbound:"<<upper_bound(v.begin(),v.end(),17)-v.begin()<<endl;
   cout<<"lowerbound:"<<lower_bound(v.begin(),v.end(),17)-v.begin()<<endl;
  
  string name="abcde";
  reverse(name.begin(),name.end());
  cout<<name<<endl;
   cout<<"after rotate :"<<endl;
   rotate(v.begin(),v.begin()+1,v.end());
   for(int i:v)
   {
       cout<<i<<ends;
   }
   cout<<endl;
    return 0;
}