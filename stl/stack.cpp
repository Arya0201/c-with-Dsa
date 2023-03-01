#include<iostream>
#include<stack>
using namespace std;
int main()
{   stack<string> s;
  s.push("love");
  s.push("arya");
  s.push("neel");
  cout<<"first:"<<s.top();
  s.pop();
  cout<<"size:"<<s.size();
  cout<<endl<<"empty or not:"<<s.empty();  
    return 0;
}