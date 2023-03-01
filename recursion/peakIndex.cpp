#include<bits/stdc++.h>
using namespace std;
int bsearch(int arr[],int l,int r)
{
   //if(l>=r)
   //return -1;

 int mid=l+(r-l)/2;
   if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
   {
       return arr[mid];
   }else if(arr[mid]>arr[mid-1])
   {
       bsearch(arr,mid+1,r);
   }else{
       bsearch(arr,l,mid);
   }
}

int main()
{   int arr[]={1,10,5,2};
      int ans=bsearch(arr,0,3);
       cout<<ans;
    return 0;
}