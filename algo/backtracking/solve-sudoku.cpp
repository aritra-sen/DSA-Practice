#include <iostream>
using namespace std;

int sudoku[9][9];

bool isSafe(int r,int c,int val)
{
    for(int i=0;i<9;i++)
        if(sudoku[i][c]==val)
            return false;
    for(int i=0;i<9;i++)
        if(sudoku[r][i]==val)
            return false;
    int br = r/3;
    int bc = c/3;
    for(int i=br*3;i<(br+1)*3;i++)
        for(int j=bc*3;j<(bc+1)*3;j++)
            if(sudoku[i][j]==val)
                return false;
    return true;
}

bool solve()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(sudoku[i][j]==0)
            {
                for(int num=1;num<=9;num++)
                {
                    if(isSafe(i,j,num))
                    {
                        sudoku[i][j]=num;
                        if(solve())
                            return true;
                        else
                            sudoku[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
	int t;
	cin>>t;
	while(t--)
    {
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                cin>>sudoku[i][j];
        solve();
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
                cout<<sudoku[i][j]<<" ";
            cout<<"\n";
        }
        cout<<"\n";
    }
	return 0;
}
