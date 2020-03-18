#include <iostream>
#include <stack>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string x;
	    cin>>x;
	    stack<int> s;
	    s.push(-1);
	    int ans = 0;
	    for(int i=0;x[i];i++)
	    {
	        if(x[i]=='(')
	            s.push(i);
	        else
	        {
	            s.pop();
	            if(!s.empty())
	                ans = max(ans,i - s.top());
	            else
	                s.push(i);
	        }
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}
