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

    int T;
    int sx, sy, ex, ey;
    int px, py, pr;

    cin >> T;

    while(T--)
    {
        int cnt = 0;

        cin >> sx >> sy >> ex >> ey;

        int n;
        cin >> n;
        
        while(n--)
        {
            int dist;
            bool indist1, indist2;
            cin >> px >> py >> pr;

            // 카운팅 조건
            // 1. 둘 다 같은 원 안에 있을 경우 -> 이탈/진입 필요 x 따라서 cnt 증가 x
            // 2. 둘 다 원 밖에 있을 경우 -> 해당 원 에서는 이탈/진입이 필요하지 않다, 따라서 cnt 증가 x
            // 3. 둘 중 하나 만 원 안에 있을 경우 -> 해당 원 에서 이탈/진입이 최소 1번이 필요하기 떄문에 cnt 1 증가.

            // 시작점에 관련하여 거리
            dist = (px - sx) * (px-sx) + (py - sy) * (py - sy);
            
            // 원 교차 공식에 관련, d > r보다 멀 경우 해당 원에 교차되는 점 없음 -> 해당 원에 속하지 않는다.
            indist1 = dist > pr * pr ? false : true;
            
            // 도착점에 관련하여 거리
            dist = (px - ex) * (px - ex) + (py - ey) * (py - ey);
            
            indist2 = dist > pr * pr ? false : true;

            if(indist1 != indist2)
            {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}