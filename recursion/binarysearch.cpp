#include<bits/stdc++.h>
using namespace std;
int bsearch(int arr[],int l,int r,int key)
{
   int mid=l+(r-l)/2;
   if(l>r)
     return -1;

     if(key==arr[mid]){
        return mid;
     }else if(key>arr[mid])
     {
         bsearch(arr,mid+1,r,key);
     }else{
         bsearch(arr,l,mid-1,key);
     }
}

int main()
{   int arr[]={1,3,4,7,11,14,15,19,21};
      int ans=bsearch(arr,0,8,12);
       cout<<ans;
    return 0;
}