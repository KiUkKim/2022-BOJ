#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    fastio;

    int dice_cnt[81] = {0,};
    int S1, S2, S3;
    int sum = 0;

    cin >> S1 >> S2 >> S3;

    for(int i=1; i <= S1; i++)
    {
        for(int j=1; j <= S2; j++)
        {
            for(int k = 1; k <= S3; k++)
            {
                sum += (i + j + k);
                dice_cnt[sum] += 1;
                sum = 0;
            }
        }
    }

    int max_idx;
    int max = 1;
    for(int i = 1; i < (S1 + S2 + S3); i++)
    {
        if(max < dice_cnt[i])
        {
            max = dice_cnt[i];
            max_idx = i;
        }
    }
    
    cout << max_idx << '\n';

    return 0;
}