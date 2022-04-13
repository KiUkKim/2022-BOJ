#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int INF = 987654321;

int main()
{
    fastio;

    int floyd_washall[51][51];


    int N;

    cin >> N;

    // 입력에따른 가중치 삽입
    for(int i=0; i < N; i++)
    {
        string check;
        cin >> check;

        for(int j = 0; j < N; j++)
        {
            if(check[j] == 'Y')
            {
                floyd_washall[i][j] = 1;
            }
            else
            {
                floyd_washall[i][j] = INF;
            }

            if(i == j)
            {
                floyd_washall[i][j] = 0;
            }
        }
    }

    for(int k = 0 ; k < N; k++)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(floyd_washall[i][j] > (floyd_washall[i][k] + floyd_washall[k][j]) )
                {
                    floyd_washall[i][j] = floyd_washall[i][k] + floyd_washall[k][j];
                }
            }
        }
    }

    // 모든 정점에서 모든 정점으로의 최단 거리 계산, 2이하인 경우 판단
    // 둘이 친구이거나, 특정 사람의 관계로 친구가 될 수 있으므로 최대 가중치 2
    int res = 0;
    for(int i = 0; i < N; i++)
    {
        int cnt = 0;
        for(int j = 0; j < N; j++)
        {
            // 0일 경우 자신의 노드 -> 제외
            if(i == j) 
            {
                continue;
            }
            if(floyd_washall[i][j] <= 2)
            {
                cnt++;
            }
        }
        if(res < cnt)
        {
            res = cnt;
        }
    }

    cout << res << '\n';
    


    return 0;
}