#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string a[n];
	    int minLen = 10001;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        minLen = (minLen<a[i].length())?minLen:a[i].length();
	    }
	    string res="";
	    for(int i=0;i<minLen;i++)
	    {

	        char curr = a[0][i];
	        bool flag = true;
	        for(int j=1;j<n;j++)
	        {
	           if(curr != a[j][i])
	           {
	                flag =false;
	                break;
	           }
	        }
	        if(flag)
	            res+=curr;
	        else
	            break;
	    }
	    if(res.length()>0)
	        cout<<res<<"\n";
	    else
	        cout<<"-1\n";
	}
	return 0;
}
