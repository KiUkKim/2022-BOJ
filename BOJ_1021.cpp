#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
    fastio;

    deque<int> que;
    int cnt = 0;

    int N, M;

    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        que.push_back(i);
    }

    cin >> M;

    while(M)
    {
        int num;
        int left, right;

        cin >> num;

        for(int i = 0; i < que.size(); i++)
        {
            if(que[i] == num)
            {
                // 오른쪽 이동 시 값 카운팅
                right = que.size() - i;
                // 좌로 이동 시 값 카운팅
                left = i;
                break;
            }
        }

        // 좌로 이동 시, 더 효율적일 경우
        if(left < right)
        {
            while(true)
            {
                if(que.front() == num)
                {
                    break;
                }

                que.push_back(que.front());
                que.pop_front();
                cnt++;
            }
            que.pop_front();
        }

        // 우로 이동 시, 더 효율적일 경우
        else{
            while(true)
            {
                if(que.front() == num)
                {
                    break;
                }

                que.push_front(que.back());
                que.pop_back();
                cnt++;
            }
            que.pop_front();
        }
        M--;
    }

    cout << cnt << '\n';

    return 0;
}