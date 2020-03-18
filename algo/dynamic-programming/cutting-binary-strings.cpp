#include <iostream>
#include <cstring>
using namespace std;

bool isValid(string x)
{
    long long rem = 0;
    bool flag = false;
    if(x[0]=='0')
        return false;
    for(int i=0;x[i];i++)
    {
        int num = x[i]-'0';
        if(num)
            flag = true;
        rem = (rem*2 + num);
    }
    if(!flag)
        return false;
    while(rem>1)
    {
        if(rem%5)
            return false;
        rem/=5;
    }
    return true;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string x;
	    cin>>x;
	    int n = x.size();
	    int dp[n+1];
	    dp[0]=0;
	    memset(dp,-1,sizeof(dp));
	    for(int i=1;i<=n;i++)
	    {
	        if(isValid(x.substr(0,i)))
	            dp[i] = 1;
	        if(dp[i]!=-1)
	            for(int j=i;j<n;j++)
	                if(isValid(x.substr(i,j-i+1)))
	                    dp[j+1] = dp[j+1]!=-1?min(dp[j+1],dp[i]+1):dp[i]+1;
	    }
	    cout<<dp[n]<<"\n";
	}
	return 0;
}
