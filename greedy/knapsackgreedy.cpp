#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2)
{
    double v1=(double)p1.first/(double)p1.second;
    double v2=(double)p2.first/(double)p2.second;
    
    return v1>v2;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    vector<pair<int,int>> v1(n);
    int weight;
    
    for(int i=0;i<n;i++)
    {   int a,b;
        cin>>a>>b;
        v1[i].first=a;
        v1[i].second=b;
    }
    
    cin>>weight;
    
    sort(v1.begin(),v1.end(),compare);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(weight>=v1[i].second)
        {
          weight=weight-v1[i].second;
         ans+=v1[i].first;
            continue;
        }
        
         double vw=(double)v1[i].first/(double)v1[i].second;
        ans+=vw*weight;
        weight=0;
        break;
    }
    cout<<ans;
    return 0;
}
