#include<bits/stdc++.h>
using namespace std;
bool search(int arr[],int size,int key)
{ //base case 
    if(size==0)
    {
        return false;
    }
   if(key==arr[0])
   {
       return true;
   }else{
       search(arr+1,size-1,key);
   }

}
int main()
{   int arr[]={1,4,2,88,12,5,9};
    bool ans=search(arr,7,9);
    if(ans)
      cout<<"found";
    else 
    cout<<"no";  
    return 0;
}