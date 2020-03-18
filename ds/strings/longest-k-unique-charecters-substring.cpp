#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int k;
	    string x;
	    cin>>x>>k;
	    int hash[26]={0};
	    int n = x.size();
	    int l=0,r=-1;
	    int ans = -1;
	    int curr = 0;
	    if(k<=0)
	    {
	        cout<<"-1\n";
	        continue;
	    }
	    while(r<n)
	    {
	        if(curr<=k)
	        {
	            if(curr==k)
	                ans = max(ans,r-l+1);
	            r++;
	            if(hash[x[r]-'a']==0)
	                curr++;
	            hash[x[r]-'a']++;
            }
	        else
	        {
	            hash[x[l]-'a']--;
	            if(hash[x[l]-'a']==0)
	                curr--;
	            l++;
	        }

	    }
	    cout<<ans<<"\n";
	}
	return 0;
}
