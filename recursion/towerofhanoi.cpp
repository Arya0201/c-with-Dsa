#include<bits/stdc++.h>
using namespace std;
void TOH(char a,char b,char c,int n);
int main()
{   int n;
    cin>>n;
    TOH('A','B','C',n);
    return 0;
}
void TOH(char a,char b,char c,int n)
{
    if(n==1)
    {
        cout<<n<<" from "<<a<<" to "<<c<<endl;
        return ;
    }
    TOH(a,c,b,n-1);
    cout<<n<<" from"<<a<<" to "<<c<<endl;
    TOH(b,a,c,n-1);
}