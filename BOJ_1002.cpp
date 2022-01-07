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

    int n;
    int x1, y1, r1, x2, y2, r2;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int dist = ((x2-x1) * (x2-x1)) + ((y2-y1) * (y2-y1));

        int condist = ((r2-r1) * (r2-r1));
        int condist2 = ((r2 + r1) * (r2+r1));

        if(dist == 0)
        {
            if(condist == 0)
            {
                cout << "-1" << '\n';
            }
            else{
                cout << "0" << '\n';
            }
        }

        else if(dist == condist || dist == condist2)
        {
            cout << "1" << '\n';
        }
        else if(dist > condist && dist < condist2 )
        {
            cout << "2" << '\n';
        }
        else{
            cout << "0" << '\n';
        }
    }

    return 0;
}