#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int len,k;
	    cin>>len>>k;
	    string x;
	    cin>>x;
	    if(k>=len-1)
	    {
	        cout<<"1\n";
	        continue;
	    }
	    int lps[len][len];
	    for(int i=0;i<len;i++)
	        lps[i][i]=1;
	    for(int i=1;i<len;i++)
	        lps[i-1][i]=x[i-1]==x[i]?2:1;
	    for(int d=3;d<=len;d++)
	    {
	        for(int i=0;i<=len-d;i++)
	        {
	            int j = i+d-1;
	            if(x[i]==x[j])
	                lps[i][j]=2+lps[i+1][j-1];
	            else
	                lps[i][j]=max(lps[i+1][j],lps[i][j-1]);
	        }
	    }
	    cout<<(k>=(len - lps[0][len-1]))<<"\n";
	}
	return 0;
}
