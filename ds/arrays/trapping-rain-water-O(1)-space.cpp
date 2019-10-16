#include <iostream>
#include <climits>
using namespace std;

int main() {
	int  t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int  i=0;i<n;i++)
	        cin>>a[i];
      int l=0,r=n-1;
      int leftMax = INT_MIN,rightMax = INT_MIN;
      int val = 0;
      while(l<=r)
      {
        if(a[l]<a[r])
        {
          if(a[l]>leftMax)
            leftMax = a[l];
          else
            val += leftMax - a[l];
          l++;
        }
        else
        {
          if(a[r]>rightMax)
            rightMax = a[r];
          else
            val+= rightMax - a[r];
          r--;
        }
      }
      cout<<val<<"\n";
  }
	return 0;
}
