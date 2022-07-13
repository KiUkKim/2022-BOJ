#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v;

vector<int> rnt;

int N, K;

int main()
{
    fastio;

    cin >> N >> K;

    if(K >= N)
    {
        cout << '0' << '\n';
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        int location;

        cin >> location;

        v.push_back(location);
    }

    // 오름 차순으로 정렬
    sort(v.begin(), v.end());

    // 각 차이 계산해서 넣어주기
    for (int i = 0; i < N - 1; i++)
    {
        int sub = v[i + 1] - v[i];
        rnt.push_back(sub);
    }

    v.clear();

    // 차이 오름차순으로 정렬
    sort(rnt.begin(), rnt.end());

    // 오름차순에서 연결고리 끊기
    for (int i = 0; i < K - 1; i++)
    {
        rnt.pop_back();
    }

    int sum = 0;

    for (auto &v : rnt)
    {
        sum += v;
    }

    cout << sum << '\n';

    return 0;
}