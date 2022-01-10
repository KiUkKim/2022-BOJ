#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

int main()
{
    fastio;

    int N, M;
    pair<int, int> price[50];
    int pack, not_pack;
    int min_result = 0;

    cin >> N >> M; 

    for(int i = 0; i < M; i++)
    {
        cin >> price[i].first >> price[i].second;
    }


    sort(price, price+M);

    pack = price[0].first;

    sort(price, price+M, compare);

    not_pack = price[0].second;

    while(N > 0)
    {
        // 6개 이상 구매해야 할 때,
        if(N >= 6)
        {
            // 개별 구입이 패키지 구입보다 값이 쌀 때
            if(pack > ( not_pack * 6 ) )
            {
                min_result += not_pack * N;
                N -= N;
            }
            else{
                min_result += pack;
                N -= 6;
            }
        }

        // 6개 이하일 때,
        else{
            // 팩으로 구입하는게 n개 개별로 구입할 때 보다 쌀 경우
            if(pack < (not_pack * N))
            {
                min_result += pack;
                N -= 6;
            }
            else{
                min_result += not_pack * N;
                N -= N;
            }
        }
    }

    cout << min_result << '\n';

    return 0;
}