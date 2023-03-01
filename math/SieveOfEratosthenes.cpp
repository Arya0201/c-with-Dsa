  //Total prime numbers between 0 to n using Sieve of Eratosthenes
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,cnt=0;
    cin>>n;
 vector<bool> prime(n+1,true);
 prime[0]=prime[1]=false;
 for (int i = 2; i < n; i++)
 {  
     if(prime[i])
     {
         cnt++;
        for (int j = 2*i; j <n; j=j+i)
        {
            /* code */
            prime[j]=0;
        }
        
     }
 }
   
    return 0;
}