#include <iostream>
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
        int dp[len+1]={0};
        for(int i=1;i<=len;i++)
        {
            if(!dp[i] && (m.find(str.substr(0,i))!=m.end()))
                dp[i]=true;
            if(dp[i])
            {
                for(int j=i+1;j<=len;j++)
                {
                    if(!dp[j] && (m.find(str.substr(i,j-i))!=m.end()))
                        dp[j]=true;
                }
            }
        }
        cout<<dp[len]<<"\n";
	}
	return 0;
}
