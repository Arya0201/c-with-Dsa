#include<iostream>
using namespace std;
#include<vector>

void bubblesort(vector<int> &arr,int n){
  bool swapped=false;
  for (int  i = 0; i <n; i++)
  {
   for (int j = 0; j < n-i-1; j++)
   {
       if(arr[j]>arr[j+1])
       {
           swap(arr[j],arr[j+1]);
          swapped=true;
       }
   }
   if(swapped==false)
   {
       break;
   }
  }
}
int main()
{   vector<int> arr{10,1,7,6,14,9};
     bubblesort(arr,6);
     for (int i=0;i<6;i++)
     {
         /* code */
         cout<<arr[i]<<endl;
     }
     
    return 0;
}