#include<iostream>
using namespace std;
#include<queue>;
int main()
{   queue<string> q;
     q.push("love");
  q.push("arya");
  q.push("neel");
  cout<<"first:"<<q.front();
  q.pop();

    return 0;
}