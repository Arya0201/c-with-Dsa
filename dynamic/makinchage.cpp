#include<bits/stdc++.h>
using namespace std;
int main()
{   
    vector<int> nums={1,2,5};
    int x;
    cin>>x;
    vector<int> dp(x+1,INT_MAX);
    dp[0]=0;

    for (int i = 1; i <=x; i++)
    {
        for (int j = 0; j <nums.size() ; j++)
        {
            if(i-nums[j]>=0 && dp[i-nums[j]]!=INT_MAX)
            dp[i]=min(dp[i],1+dp[i-nums[j]]);
        }
    }
     
    cout<<dp[x];
    return 0;
}