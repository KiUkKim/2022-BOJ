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

    int wood_len = 64;
    int X;
    int cnt = 0;

    cin >> X;

    while(true)
    {
        if(X == wood_len)
        {
            cnt +=1;
            break;
        }

        if( (X / wood_len) )
        {
            cnt += 1;
            X -= wood_len;
            wood_len /= 2;
        }
        else if( (X/wood_len) == 0)
        {
            wood_len /= 2;
        }

    }

    cout << cnt << '\n';

    return 0;
}