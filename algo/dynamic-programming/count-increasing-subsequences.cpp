#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    long long dp[n];
	    dp[0] = 1;
	    for(int i=1;i<n;i++)
	    {
	        dp[i] = 1;
	        for(int j = 0;j<i;j++)
	        {
	            if(a[j]<a[i])
	                dp[i]+=dp[j];
	        }
	    }
	    for(int i = 1;i<n;i++)
	        dp[i] += dp[i-1];
	    cout<<dp[n-1]<<"\n";
	}
	return 0;
}
