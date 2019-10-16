// Logic being NGE of Root is Right Subtree.. and After that element No element should be greater than Root
// Implemented Using stack for NGE
// if a[x] is NGE of a[y] then for the subtree rooted at y is index of starting of Right subtree

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
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int root = 0;
    stack<int> st;
    bool flag = true;
    for(int i=0;i<n;i++)
    {
      if(a[i]<a[root])
      {
        flag = false;
        break;
      }
      while(!st.empty() && a[st.top()]<a[i])
      {
        root = i;
        st.pop();
      }
      st.push(a[i]);
    }
    cout<<flag<<"\n";
  }
  return 0;
}
