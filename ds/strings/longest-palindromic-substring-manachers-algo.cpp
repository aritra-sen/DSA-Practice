#include<iostream>
using namespace std;

int getLPS(string x)
{
  int n = x.size();
  if(n==0)
    return 0;
  n = 2*n + 1;
  int lps[n]={0};
  lps[0]=0;
  lps[1]=1;
  int center = 1; // center
  int r = 2; // Centered Right
  int i = 0; //Current Right
  int iMirror = 0; //current Left
  int expand = -1;
  int diff = -1;
  int maxLPS = 0;
  int maxLPSCenter = 0;
  int start = -1;
  int end = -1;
  for(int i=2;i<n;i++)
  {
    iMirror = center - (i - center);
    expand = 0;
    diff = r - i; // distance from Centered Right
    if(diff>0)
    {
      if(lps[iMirror]<diff)
        lps[i] = lps[iMirror];
      else if(lps[iMirror]==diff&& i==n-1)
        lps[i] = lps[iMirror];
      else if(lps[iMirror]==diff&& i<n-1)
      {
        expand = 1;
        lps[i] = lps[iMirror];
      }
      else if(lps[iMirror]>diff)
      {
        lps[i] = diff;
        expand = 1;
      }
    }
    else
    {
      lps[i]=0;
      expand = 1;
    }
    if(expand)
    {
      while(i+lps[i]<n && i-lps[i]>=0 && (((i + lps[i] + 1) % 2 == 0) || (x[(i+lps[i]+1)/2]==x[(i-L[i]-1)/2]) ))
        lps[i]++;
    }
    if(lps[i]>maxLPS)
    {
      maxLPS = lps[i];
      maxLPSCenter = i;
    }
    if(i + lps[i]>r)
    {
      r = i + lps[i];
      center = i;
    }
  }
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string x;
    cin>>x;
    cout<<getLPS(x)<<"\n";
  }
  return 0;
}
