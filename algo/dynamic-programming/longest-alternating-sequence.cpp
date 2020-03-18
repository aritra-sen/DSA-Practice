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
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    int las[n][2];
	    int ans = 1;
	    for(int i=0;i<n;i++)
	    {
	        las[i][0]=las[i][1]=1;
	        for(int j=0;j<i;j++)
	        {
	            if(a[j]<a[i] && las[j][0]+1>las[i][1])
	                las[i][1] = las[j][0] + 1;
	            if(a[j]>a[i] && las[j][1]+1>las[i][0])
	                las[i][0] = las[j][1] + 1;
            }
            ans = max(ans,max(las[i][0],las[i][1]));

	    }
	    cout<<ans<<"\n";
	}
	return 0;
}
