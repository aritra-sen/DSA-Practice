#include <iostream>
#include <stack>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string x;
        cin>>x;
        int curr_max = 0;
        int last_entry = 0;
        string decrypt="";
        int n = x.size();
        for(int i=0;i<n;i++)
        {
            int no_of_D = 0;
            if(x[i]=='I')
            {
                int j = i + 1;
                while(j<n && x[j++]=='D')
                    no_of_D++;

                if(i==0)
                {
                    decrypt+=to_string(1);
                    last_entry = 1;
                    curr_max = 1;
                }

                curr_max = no_of_D + curr_max + 1;
                decrypt+=to_string(curr_max);
                last_entry = curr_max;

                while(no_of_D--)
                {
                    decrypt+=to_string(--last_entry);
                    i++;
                }
            }
            else
            {
                if(i==0)
                {
                    int j = i;
                    while(j<n && x[j++]=='D')
                        no_of_D++;
                    decrypt+=to_string(no_of_D + 1);
                    decrypt+=to_string(no_of_D);
                    last_entry = no_of_D;
                    curr_max = no_of_D + 1;
                }
                else
                {
                    decrypt+=to_string(--last_entry);
                }
            }
        }
        cout<<decrypt<<"\n";

    }
    return 0;
}
