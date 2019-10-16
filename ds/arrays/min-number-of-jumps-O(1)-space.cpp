#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
      int jump = 0;
      int step = 1;
      int maxReachable = 0;
      for(int i=0;i<n-1;i++)
      {
        maxReachable = max(maxReachable,i+a[i]);
        step--;
        if(step==0)
        {
          jump++;
          if(i>=maxReachable)
            break;
          step = maxReachable - i;
        }
      }
      if(maxReachable>=n-1)
        cout<<jump<<"\n";
      else
        cout<<"-1\n";
	}
	return 0;
}
