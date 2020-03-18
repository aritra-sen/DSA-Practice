#i#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    unordered_set<string> m;
	    int n;
	    cin>>n;
	    for(int i=0;i<n;i++)
	    {
	        string x;
	        cin>>x;
	        m.insert(x);
	    }
	    string str;
	    cin>>str;
	    int len = str.size();
      int dp[len+1];
      memset(dp,-1,sizeof(dp));
      for(int i=1;i<=len;i++)
      {
          if((m.find(str.substr(0,i))!=m.end()))
              dp[i]=0;
          if(dp[i]!=-1)
          {
            for(int j=i+1;j<=len;j++)
            {
              if(m.find(str.substr(i,j-i))!=m.end())

								if(dp[j]!=-1)
									dp[j]=min(dp[j],dp[i]+1);
								else
									dp[j] = dp[i] + 1;
            }
          }
      }
      cout<<dp[len]<<"\n";
	}
	return 0;
}
