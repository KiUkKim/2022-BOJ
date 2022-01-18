#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

bool compare(pair<int, string> p1, pair<int, string> p2)
{
    return p1.first < p2.first;
}

int main()
{
    fastio;

    pair<int, string> p[50];
    string tmp;
    int N;

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> tmp;

        p[i] = make_pair(tmp.size() , tmp);
    }

    sort(p, p+N, compare);

    int result = N;

    for(int i = 0; i < N-1; i++)
    {
        for(int j = i + 1; j < N ; j++)
        {
            int cnt = 0;
            for(int k = 0; k < p[i].first ; k++)
            {
                if(p[i].second[k] == p[j].second[k])
                {
                    cnt ++;
                }
            }

            if(cnt == p[i].first)
            {
                result -= 1;
                break;
            }
        }
    }

    cout << result << '\n';

    return 0;
}