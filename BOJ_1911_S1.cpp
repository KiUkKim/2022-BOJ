#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> hole;

int N, L;

int main()
{
    fastio;

    cin >> N >> L;

    for (int i = 0; i < N; i++)
    {
        int start, end;
        cin >> start >> end;
        hole.push_back({start, end});
    }

    sort(hole.begin(), hole.end());

    int cnt = 0;

    int scope = 0;

    for (int i = 0; i < hole.size(); i++)
    {
        if (scope < hole[i].first)
        {
            scope = hole[i].first;
        }

        while (scope < hole[i].second)
        {
            scope += L;
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}