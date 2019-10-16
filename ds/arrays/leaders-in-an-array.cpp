#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        bool vis[n]={false};
        for(int i=0;i<n;i++) cin>>arr[i];
        int max=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]>=max)
            {
                max=arr[i];
                vis[i]=true;
            }
        }
        for(int i=0;i<n;i++)
            if(vis[i])
                cout<<arr[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
