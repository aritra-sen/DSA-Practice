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

        int ans = 0;
        for(int i=0;i<32;i++)
        {
            int count = 0;
            for(int j=0;j<n;j++)
            {
                if(a[j] & (1<<i))
                    count++;
            }
            ans+=count*(n-count)*2;

        }
        cout<<ans<<"\n";
    }
	return 0;
}
