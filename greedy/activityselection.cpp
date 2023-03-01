#include<bits/stdc++.h>
using namespace std;

int main()
{   
    int n;
    cin>>n;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        /* code */
        int start,end;
        cin>>start>>end;
        v.push_back({start,end});
    }
    sort(v.begin(),v.end(),[&](vector<int> &v1,vector<int> &v2){
        return v1[1] < v2[1];
    });

    int take=1;
    int endtime=v[0][1];
    for (int i = 1; i < n; i++)
    {
        if(v[i][0]>=endtime)
        {  
            endtime=v[i][0];
            take++;
        }
    }
    cout<<take;
    return 0;
}