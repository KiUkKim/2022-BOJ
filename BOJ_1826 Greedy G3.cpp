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

    int N,L,P;

    pair<int, int> station[10000];

    cin >> N;

    for(int i =0 ; i < N; i++)
    {
        cin >> station[i].first >> station[i].second;
    }

    cin >> L >> P;

    sort(station, station + N);

    priority_queue<int> pq;

    // cntL 목표지점, cntP 현재 갈 수 있는 거리

    int cntL = P, cntP = 0, ans=0;

    while(cntL < L){
        while(cntP < N && station[cntP].first <= cntL)
        {
            pq.push(station[cntP++].second);
        }

        if(pq.empty())
        {
            ans = -1;
            break;
        }

        cntL += pq.top();

        pq.pop();

        ans ++;
    }

    cout << ans << '\n';

    return 0;
}