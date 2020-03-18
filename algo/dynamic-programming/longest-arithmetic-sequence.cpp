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
	    int dp[n][n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    if(n<=2)
	    {
	        cout<<n<<"\n";
	        continue;
	    }
	    int ans = 2;

	    for(int i=0;i<n-1;i++)
	        for(int j=i+1;j<n;j++)
	            dp[i][j]=2;

	    for(int i=0;i<n;i++)
	        dp[i][i]=1;

	    for(int i=n-2;i>=0;i--)
	    {
	        int l = i-1,r=i+1;
	        while(l>=0 && r<n)
	        {
	            if(a[l]+a[r]<2*a[i])
	                r++;
	            else if(a[l]+a[r]>2*a[i])
	            {
	                dp[l][i]=2;
	                l--;
	            }
	            else
	            {
	                dp[l][i]=dp[i][r]+1;
	                ans = max(ans,dp[l][i]);
	                l--;
	                r++;
	            }
	        }
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}
