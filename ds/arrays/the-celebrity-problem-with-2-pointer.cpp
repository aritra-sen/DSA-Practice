/*
 * You are in a party of N people,where only one person is known to everyone. Such a person may be present in the party
 * if yes, (s)he doesn’t know anyone in the party. Your task is to find the stranger (celebrity) in party.
 */


 #include<bits/stdc++.h>
 using namespace std;
 #define MAX 501
 int getId(int M[MAX][MAX],int n);
 int main()
 {
     int T;
     cin>>T;
     int M[MAX][MAX];
     while(T--)
     {
         int N;
         cin>>N;
         memset(M,0,sizeof M);
         for(int i=0;i<N;i++)
         {
             for(int j=0;j<N;j++)
             {
                 cin>>M[i][j];
             }
         }
         cout<<getId(M,N)<<endl;
     }
 }

 /*This is a function problem.You only need to complete the function given below*/
 // The task is to complete this function
 // M[][]: input matrix
 // n: size of matrix (n*n)
 int getId(int m[MAX][MAX], int n)
 {
   int l = 0,r = n-1;
    while(l<r)
    {
        if(m[l][r])
            l++;
        else
            r--;
   }

   int ans = l;
   for(int i=0;i<n;i++)
   {
        if(i!=ans && (!m[i][ans] || m[ans][i]))
            return -1;
   }
   return ans;
 }
