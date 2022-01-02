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

    // N : 운동을 하는 시간
    // m : 최소 맥박
    // M : 최대 맥박
    // T : 맥박 증가
    // R : 휴식 후 맥박 감소
    int N, m, M, T, R;

    cin >> N >> m >> M >> T >> R;

    int start = m;
    int start_cnt = 0;
    int min_time = 0;

    while(1)
    {
        if(start + T > M && start - R < m && start_cnt == 0)
        {
            min_time = -1;
            break;
        }
        else if(start + T <= M)
        {
            start += T;
            start_cnt ++;
            min_time++;
        }
        else if(start - R >= m){
            start -= R;
            min_time++;
        }
        else{
            start = m;
            min_time++;
        }

        
        if(start_cnt == N)
        {
            break;
        }

    }

    
    cout << min_time << '\n';

    return 0;
}