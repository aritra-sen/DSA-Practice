#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,sum;
	    cin>>n>>sum;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    unordered_map<int,vector<pair<int,int>>> val;
	    int k=0;
	    for(int i=0;i<n-1;i++)
	        for(int j=i+1;j<n;j++)
	            if(a[i]+a[j]<=sum)
	                val[a[i]+a[j]].push_back({i,j});

	    bool flag = false;

	    set<vector<int>> res;
	    for(const auto &x : val)
	    {
	        const auto &it = val.find(sum-x.first);
	        if(it!=val.end())
	        {
	            for(const auto &z : it->second)
	            {
	                for(const auto &v : x.second)
	                {
	                    set<int> ans;
	                    ans.insert(z.first);
	                    ans.insert(v.first);
	                    ans.insert(z.second);
	                    ans.insert(v.second);
	                    if(ans.size() == 4)
	                    {
	                        vector<int> zzz;
	                        for(const auto &c : ans)
	                            zzz.push_back(a[c]);
	                        sort(zzz.begin(),zzz.end());
	                        res.insert(zzz);
	                    }
	                }
	            }
	        }
	    }
	    for(const auto &answer : res)
	    {
	        for(const auto &values : answer)
	            cout<<values<<" ";
	        cout<<"$";
	    }
	    if(res.size()==0)
	        cout<<"-1";
	    cout<<"\n";
	}
	return 0;
}
