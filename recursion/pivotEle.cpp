#include<bits/stdc++.h>
using namespace std;
int findp(int arr[],int l,int r)
{
    //base
  int mid= l+ (r-l)/2;
    if(l>=r)
      return arr[mid];
    if(arr[mid]>=arr[0])
    {
       return  findp(arr,mid+1,r);
    }else{
        return findp(arr,l,mid);
    }
}
int main()
{  int arr[]={7,8,9,11,5};
      int ans=findp(arr,0,4);
      cout<<ans;
    return 0;
}