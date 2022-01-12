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

    int player, Kim, Lim;

    cin >> player >> Kim >> Lim;

    int cnt = 1;
    while(true)
    {
        if(player < 1 )
        {
            cout << -1 << '\n';
            break;
        }

        player += 1;
        Kim += 1, Lim += 1;

        if(Kim / 2 == Lim / 2)
        {
            cout << cnt << '\n';
            break;
        }

        player /= 2, Kim /= 2; Lim /= 2;
        cnt++;
    }

    return 0;
}