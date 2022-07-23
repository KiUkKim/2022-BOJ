#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int T[16] = {0, };
int P[16] = {0, };
int cnt[16] = {0, };
int N;

int MAX(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    fastio;

    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        cin >> T[i] >> P[i];
    }

    int date;

    for(int i = N; i > 0; i--)
    {
        date = i + T[i];

        if(date > N+1)
        {
            cnt[i] = cnt[i+1];
        }
        
        else{
            cnt[i] = MAX(cnt[i+1], cnt[date] + P[i]);
        }
    }

    cout << cnt[1] << '\n';

    return 0;
}