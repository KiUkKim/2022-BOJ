#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int step[301];
int n;
int DP[100];

int main()
{
    fastio;

    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> step[i];
    }

    DP[0] = step[0];
    DP[1] = step[0] + step[1];
    DP[2] = max(step[0]+step[2],step[1]+step[2]);

    for(int i=3; i<=n; i++){
        DP[i] = step[i] + max(DP[i-2],DP[i-3]+step[i-1]);
    }

    cout << DP[n-1] << '\n';

    return 0;
}