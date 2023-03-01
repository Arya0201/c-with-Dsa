#include<bits/stdc++.h>
using namespace std;
int bsearch(int arr[],int l,int r,int key)
{ static  int ans=-1;
   int mid=l+(r-l)/2;
   if(l>r)
     return -1;

     if(key==arr[mid]){
          ans =mid;
         bsearch(arr,l,mid-1,key);
     }else if(key>arr[mid])
     {
         bsearch(arr,mid+1,r,key);
     }else{
         bsearch(arr,l,mid-1,key);
     }
     return ans;
}

int main()
{   int arr[]={1,3,3,3,11,14,15,19,21};
      int ans=bsearch(arr,0,8,21);
       cout<<ans;
    return 0;
}