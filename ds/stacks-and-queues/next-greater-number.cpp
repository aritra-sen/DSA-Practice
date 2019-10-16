#include<iostream>
#include<stack>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int nge[n];
    stack<int> st;
    for(int i=0;i<n;i++)
    {
      while(!st.empty() && a[i]>a[st.top()])
      {
        nge[st.top()]=i;
        st.pop();
      }
      st.push(i);
    }
    while(!st.empty())
    {
      nge[st.top()]=-1;
      st.pop();
    }
    for(int i=0;i<n;i++)
      cout<<((nge[i]!=-1)?a[nge[i]]:-1)<<" ";
    cout<<"\n";
  }
  return 0;
}
