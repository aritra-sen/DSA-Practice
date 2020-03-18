#include <iostream>
using namespace std;

int main() {
	int dp[76];
	for(int i=0;i<=6;i++)
	    dp[i]=i;
	for(int i=7;i<=75;i++)
	{
	    dp[i] = 0;
	    for(int last_cut_copy_paste = i-3 ; last_cut_copy_paste>=1 ; last_cut_copy_paste--)
	        dp[i] = max(dp[i],(i - last_cut_copy_paste - 1)*dp[last_cut_copy_paste]);
	}
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<dp[n]<<"\n";
    }
	return 0;
}
