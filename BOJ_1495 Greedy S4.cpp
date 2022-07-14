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

    long long X,Y;
    int W,S;

    cin >> X >> Y >> W >> S;

    // W 2번을 이용한 것이 S를 1번 이용한 효과랑 같다.
    // 둘 중 더 빠른 것을 택한다.
    if ( 2 * W < S)
    {
        cout << (X+Y)*W << '\n';
    }

    else{
        // 대각선으로 갈 수 있는 위치 파악
        long long small = min(X,Y);

        // 대각선으로 갈 수 있는 구간
        long long locat = small * S;

        // 대각선으로 구하고 수평, 수직으로 가야할 방향
        long long XYabs = abs(X-Y);

        // W1번이 S보다 클 경우, 대각으로 최대한 가는게 유리하다.
        if(W > S)
        {
            // 기존의 대각선으로 간 구간에서 수평, 수직 이동
            if( XYabs % 2 == 0)
            {
                locat += XYabs * S;
            }

            else{
                locat += (XYabs - 1) * S + W;
            }
        }

        else{
            locat += XYabs * W;
        }

        cout << locat << '\n';
    }


    return 0;
}