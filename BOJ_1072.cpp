#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
typedef long long ll;

using namespace std;

const int MAX = 1500000000;

int main()
{

    ll x, y;

    int z;

    cin >> x >> y;

    while(true)
    {
        ll left = 0, right = MAX;

        z = 100 * (y/x);

        if(z >= 99)
        {
            left = -1;
            cout << left << '\n';
            break;
        }

        else{
            while(left <= right)
            {
                ll middle = (right + left) / 2;
                ll cal = 100 * (y+middle) / (x+middle);

                if(cal <= z)
                {
                    left = middle + 1;
                }
                else{
                    right = middle - 1;
                }
            }
        }
        cout << left << '\n';
        break;
    }

    return 0;
}