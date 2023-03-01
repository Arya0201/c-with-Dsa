#include<iostream>
using namespace std;
int main()
{
    int arr[]={5,2,4,1,0};
     int n=5;
    for (int  i = 0; i <n-1; i++)
    { int minindex=i;
        for (int j = i+1; j <n; j++)
        {
            /* code */
            if (arr[j]<arr[minindex])
            {
                minindex=j;
            }
            
        }
        swap(arr[minindex],arr[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout<<arr[i]<<" ";
    }
    
}