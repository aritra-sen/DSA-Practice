#include <iostream>
#include <algorithm>
using namespace std;

string add(string x,string y)
{
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    int c = 0;
    string ans = "";
    for(int i = 0;i<min(x.size(),y.size());i++)
    {
        int val = (x[i] -'0') + (y[i] - '0') + c;
        c = val/10;
        val = val%10;
        ans.push_back(val + '0');
    }
    for(int i = min(x.size(),y.size());i<max(x.size(),y.size());i++)
    {
        int val;
        if(x.size()<y.size())
            val = (y[i] - '0') + c;
        else
            val = (x[i] - '0') + c;
        c = val/10;
        val = val%10;
        ans.push_back(val + '0');
    }
    if(c>0)
    {
        ans+=to_string(c);
    }
    reverse(ans.begin(),ans.end());
    int nz_i = 0;
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]=='0')
            continue;
        else
        {
            nz_i = i;
            break;
        }
    }
    return ans.substr(nz_i);
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    string n1="",n2="";
	    for(int i=0;i<n;i++) cin>>a[i];
	    sort(a,a+n);
	    for(int i=0;i<n;i++)
	    {
	        if(i & 1)
	            n1.push_back('0'+a[i]);
	        else
	            n2.push_back('0'+a[i]);
	    }
	    cout<<add(n1,n2)<<"\n";
	}
	return 0;
}
