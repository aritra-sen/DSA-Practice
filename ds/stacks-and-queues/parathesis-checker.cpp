#include <iostream>
#include <stack>
using namespace std;

bool check_match(char y,char x)
{
    if(x=='[' && y==']')
        return true;
    if(x=='{' && y=='}')
        return true;
    if(x=='(' && y==')')
        return true;
    return false;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string x;
	    cin>>x;
	    stack<char> st;
	    bool flag = true;
	    for(int i=0;x[i];i++)
	    {
	        if(x[i]=='('||x[i]=='{'||x[i]=='[')
	            st.push(x[i]);
	        else
	        {

	            if(!st.empty() && check_match(x[i],st.top()))
	                st.pop();
	            else
	            {
	                flag = false;
	                break;
	            }
	        }
	    }
	    if(!st.empty())
	        flag = false;
	    if(flag)
	        cout<<"balanced\n";
	    else
	        cout<<"not balanced\n";
	}
	return 0;
}
