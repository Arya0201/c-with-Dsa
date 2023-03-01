#include<bits/stdc++.h>
using namespace std;
int sum(int arr[],int size)
{
     //base case
     if(size==0)
     {
         return 0;
     }
     int ans= arr[0] + sum(arr+1,size-1);
}
int main()
{
    int arr[]={6,1,2,4,34,2};
    cout<<sum(arr,1);
}