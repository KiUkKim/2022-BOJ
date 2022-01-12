#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

string square[51];

int main()
{
    fastio;

    int N, M;

    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        cin >> square[i];
    }

    int result = 1;

    for(int i = 0; i < N - 1; i++)
    {
        for(int j = 0; j < M - 1; j++)
        {
            int start = square[i][j] - '0';
            for(int k = 1;; k++)
            {
                // 범위 넘어 가면 무시
                if(k + i >= N || k + j >= M)
                {
                    break;
                }

                int right = square[i][j+k] - '0';
                int left = square[i+k][j] - '0';
                int diagonal = square[i+k][j+k] - '0';

                if(start == right && right == left && left == diagonal)
                {
                    result = max(result, (k+1) * (k+1));
                }
            }
        }
    }

    cout << result << '\n';

    return 0;
}