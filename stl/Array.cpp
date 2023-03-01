#include<iostream>
using namespace std;
#include<array>
int main()
{
int basic[3]={1,2,3};

array<int,4> a={1,2,3,4}; //it is also static array
int size=a.size();
for (int i = 0; i < size; i++)
{
    /* code */
    cout<<a[i]<<endl;
}
cout<< "empty or not:"<<a.empty()<<endl;
cout<<"first and last:"<<a.front()<<a.end();


}