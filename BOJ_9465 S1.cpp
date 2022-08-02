#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int stick[2][100001];
int maxA[2][100001];

int main()
{
    fastio;

    int T;

    cin >> T;

    while(T--)
    {
        int row;

        cin >> row;

        for(int i = 0 ; i < 2; i++)
        {
            for(int j = 0; j < row; j++)
            {
                cin >> stick[i][j];
            }
        }

        for(int i = 0; i < row; i++)
        {
            if(i==0)
            {
                for(int j = 0 ; j < 2; j++)
                {
                    maxA[j][i] = stick[j][i];
                }
            }
            
            else{
                for(int j = 0 ; j < 2; j++)
                {
                    maxA[j][i] = stick[j][i]+ max(maxA[j ^ 1][i - 1], maxA[j ^ 1][i - 2]);
                }
            }
        }
        
        cout << max(maxA[0][row-1], maxA[1][row-1]) << '\n';

    }

    return 0;
}