#include<bits/stdc++.h>
using namespace  std;
int pow(int n)
{
    if(n==0)
    return 1;

    return 2*pow(n-1);
}
int main()
{ int n; 
   cin>>n;
 int ans= pow(n);
 cout<<ans;
 
    return 0;
}