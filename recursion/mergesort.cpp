#include<bits/stdc++.h>
using namespace std;
void merge(int *arr,int s,int e)
{ 
     int mid=s+(e-s)/2;
     int len1=mid-s+1;
     int len2=e-mid;
     int *first =new int [len1];
     int *second=new int [len2];
     int mainIndex=s;
     for (int i = 0; i < len1; i++)
     {
         first[i]=arr[mainIndex++];
     }
       mainIndex=mid+1;
     for (int i = 0; i < len2; i++)
     {
         second[i]=arr[mainIndex++];
     }
     int index1=0,index2=0;
     mainIndex=s;
     while(index1<len1 && index2<len2)
     {
        if(first[index1]<=second[index2])
        {
          arr[mainIndex++]=first[index1++];
        }else{
         
          arr[mainIndex++]=second[index2++];
        }
     }
     while(index1<len1)
     {
       arr[mainIndex++]=first[index1++];
     }
     while(index2<len2)
     {
       arr[mainIndex++]=second[index2++];
     }
     delete []first;
     delete []second;
}
void mergesort(int *arr,int s,int e)
{
      if(s>=e)
       return ;
        int mid=s+(e-s)/2;
       mergesort(arr,s,mid);
       mergesort(arr,mid+1,e);

       merge(arr,s,e);
}

int main()
{  int arr[]={1, 20, 6, 4, 5};
    mergesort(arr,0,4);
   

    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<endl;
    }
    
    return 0;
}