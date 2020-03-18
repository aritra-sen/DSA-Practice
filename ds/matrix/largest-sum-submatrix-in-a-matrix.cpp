#include<iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int m,n;
    cin>>m>>n;
    int mat[m][n];
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        cin>>mat[i][j];

    int ans = mat[0][0];
    for(int left_c = 0; left_c < n; left_c++)
    {
      int temp[m] = {0};
      for(int right_c = left_c; right_c < n; right_c++)
      {
        for(int i=0;i<m;i++)
          temp[i] +=mat[i][right_c];

        int max_so_far = temp[0],curr_max = temp[0];
        for(int i=1;i<m;i++)
        {
          max_so_far = max(temp[i],temp[i]+max_so_far);
          curr_max = max(curr_max,max_so_far);
        }
        ans = max(ans,curr_max);
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}
