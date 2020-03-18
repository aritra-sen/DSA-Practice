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
	    int j = 0;
	    for(int i=0;i<n;i++)
	    {
	        if(x[i]!='a' && x[i]!='b')
	            x[j++] = x[i];
	        else if(x[i]=='a')
	        {
	            if(i==n-1 || x[i+1]!='c')
	                x[j++] = x[i];
	             else
	                i++;
	        }
	    }
	    x = x.substr(0,j);
	    cout<<x<<"\n";
	}
	return 0;
}
