#include<iostream>
#include<stack>
using namespace std;

bool checkDuplicate(string x)
{
  stack<char> st;
  int n = x.size();
  for(int i=0;i<n;i++)
  {
    if(x[i]!=')')
      st.push(x[i]);
    else
    {
      if(st.top()=='(')
        return true;
      while(st.top()!='(')
        st.pop();
      st.pop();
    }
  }
  return false;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string x;
    cin>>x;
    bool ans = checkDuplicate(x);
    if(ans)
      cout<<"Duplicate Found\n";
    else
      cout<<"Duplicate Not Found\n";
  }
  return 0;
}
