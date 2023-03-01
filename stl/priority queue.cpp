#include<iostream>
#include<queue>
using namespace std;
int main()
{   //max heap
     priority_queue<int> maxi;
     //min heap
     priority_queue<int,vector<int>,greater<int>> mini;
     maxi.push(1);
     maxi.push(3);
     maxi.push(2);
     maxi.push(0);
  int size=maxi.size();
  //it will print 3,2,1,0
  for (int i = 0; i < size; i++)
  {
      /* code */\
      cout<<maxi.top()<<ends;
      maxi.pop();
  }
  cout<<endl;
  mini.push(1);
  mini.push(8);
  mini.push(2);
  mini.push(5);
  //it will print 1,2,5,8
  int size1=mini.size();
  for (int i = 0; i < size1; i++)
  {
      /* code */\
      cout<<mini.top()<<ends;
      maxi.pop();
  }
  cout<<endl;  
    return 0;
}