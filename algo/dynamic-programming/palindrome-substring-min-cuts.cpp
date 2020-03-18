#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string x;
	    cin>>x;
	    int n = x.size();
	    bool isPal[n][n];
	    for(int i=0;i<n;i++)
	        isPal[i][i]=true;
	    for(int i=0;i<n-1;i++)
	        if(x[i]==x[i+1])
	            isPal[i][i+1]=true;
	        else
	            isPal[i][i+1]=false;

	    for(int d=3;d<=n;d++)
	    {
	        for(int i=0;i<=n-d;i++)
	        {
	            int j=i+d-1;
	            if(x[i]==x[j] && isPal[i+1][j-1])
	                isPal[i][j]=true;
	            else
	                isPal[i][j]=false;
	        }
	    }
	    int slice[n];
	    slice[0]=0;
	    for(int i=1;i<n;i++)
	    {
	        if(isPal[0][i])
	            slice[i]=0;
	        else
	        {
	            slice[i]=1+slice[i-1];
	            for(int j=0;j<i;j++)
	                if(isPal[j+1][i] && (slice[j]+1)<slice[i])
	                    slice[i]=1+slice[j];
	        }
	    }
	    cout<<slice[n-1]<<"\n";
	}
	return 0;
}
