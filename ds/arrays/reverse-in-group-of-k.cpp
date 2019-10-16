#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    for(int i=0;i<n;i+=k)
	    {
	        int s=i,e=min(n-1,i+k-1);
	        while(s<=e)
	            swap(a[s++],a[e--]);
	    }
	    for(int i=0;i<n;i++)
	        cout<<a[i]<<" ";
	    cout<<"\n";
	}
	return 0;
}
