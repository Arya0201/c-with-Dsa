#include<iostream>
#include<vector>
using namespace std;
void insertionsort(vector<int>&arr,int n)
{
    for (int  i = 1; i < n; i++)
    {
        int temp= arr[i];
        int j = i-1;
        for (; j >=0; j--)
        {
            /* code */
            if(arr[j]>temp)
            {
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        
         arr[j+1]=temp;
    }
    
}
int main()
{ vector<int> arr{1,7,4,8,2,11};
     insertionsort(arr,6);
     for (int i = 0; i < 6; i++)
     {
         cout<<arr[i]<<endl;
     }
     
    return 0;
}