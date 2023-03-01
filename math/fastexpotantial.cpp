#include<iostream>
using namespace std;
int modularExpo(int x,int n,int m)
{
    int res=1;
    while(n>0)
    {
        if(n&1==1)
        {
            res=res*x;
        }
        x=x*x;
        n=n>>1;
    }
}
int main(){
    int x,n,m;
    cin>>x>>n>>m;
    int ans=modularExpo(x,n,m);
    cout<<ans;
    return 0;
}