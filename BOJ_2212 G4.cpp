#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v;

int N, K;

bool compare(int i, int j)
{
    return i > j;
}

int main()
{
    fastio;

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        int location;

        cin >> location;

        v.push_back(location);
    }

    // 오름 차순으로 정렬
    sort(v.begin(), v.end());

    // // 연결 고리 나누기 위해서 내림차순으로 정렬
    // sort(v.begin(), v.end(), compare);

    for (int i = 0; i < K - 1; i++)
    {
        v.pop_back();
    }

    int result = 0;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
        result += v[i];
    }

    cout << result << '\n';

    return 0;
}