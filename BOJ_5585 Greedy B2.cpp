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

    int total = 1000;

    int money[6] = {500, 100, 50, 10,  5 , 1};

    int idx = 0, ans = 0, curM;

    cin >> curM;

    total -= curM;

    while(idx < 6)
    {
        if(money[idx] <= total)
        {
            total -= money[idx];
            ans++;
            continue;
        }

        idx++;
    }

    cout << ans << '\n';


    return 0;
}