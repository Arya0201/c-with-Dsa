
#include<bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	int n;
    cin>>n;
	int a[n];

	for(int i=0;i<n;i++)
	{   cin>>a[i]; 
	}

  bool swapped=false;
  for (int  i = 0; i <n; i++)
  {
   for (int j = 0; j < n-i; j++)
   {
       if(a[j]>a[j+1])
       {
           swap(a[j],a[j+1]);
          swapped=true;
       }
   }
   if(swapped==false)
   {
       break;
   }
  }
	
 
   	for(int i=0;i<n;i++)
	{    int temp=a[i];
	    for(int j=i;j<n;j++)
        {
            a[j]=a[j]-temp;
            cout<<a[j]<<" ";
        }
	   cout<<endl;
	}
	
	return 0;
}