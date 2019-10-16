#include<iostream>
#include<vector>
using namespace std;

//O(N^2) soln --> Brute Force
int solveBrute(int arr[],int n,int m)
{
  int ans = 0;
  for(int i=0;i<n;i++)
  {
    int c=0;
    for(int j=i;j<n;j++)
    {
      if(arr[j]==0)
        c++;
      if(c<=m)
        ans = max(ans,c);
    }
  }
  return ans;
}

//O(N) soln --> Efficient with O(N) space
int solveEfficient(int a[],int n,int m)
{
  int left[n]={0},right[n]={0};
  int c=0;
  vector<int> z;
  for(int i=0;i<n;i++)
  {
    if(a[i]==0)
    {
      z.push_back(i);
      left[i]=c;
      c=0;
    }
    else
      c++;
  }
  c=0;
  for(int i=n-1;i>=0;i--)
  {
    if(a[i]==0)
    {
      right[i]=c;
      c=0;
    }
    else
      c++;
  }
  int ans = 0;
  for(int i=0;i<m && i<z.size();i++)
    ans+=right[z[i]]+1;
  ans += z.size()>0?left[z[0]]:-0;
  int curr = ans;
  for(int i=m;i<z.size();i++)
  {
    curr-=left[i-m]+1;
    curr+=right[i]+1;
    ans = max(ans,curr);
  }
  return ans;
}

//O(n) soln --> O(1) space implementation
int solve_efficient(int a[],int n,int m)
{
  int wL = 0,wR = 0;
  int bestL = 0, bestWindow = 0;
  int curr_zeros = 0;
  while(wR<n)
  {
    if(curr_zeros <=m)
    {
      if(a[wR]==0)
        curr_zeros++;
      if(wR-wL+1 > bestWindow && curr_zeros<=m)
      {
        bestL = wL;
        bestWindow = wR-wL+1;
      }
      wR++;
    }
    else
    {
      if(a[wL]==0)
        curr_zeros--;
      wL++;
    }
  }
  return bestWindow;
}


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;  // m -> zero flips allowed
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int ans = solve_efficient(a,n,m);
    cout<<ans<<"\n";
  }
  return 0;
}
