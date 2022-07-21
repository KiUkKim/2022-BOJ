#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int N, M;
vector <pair <int,int>> house;
vector <pair <int,int>> chicken;
vector <int> selected;
int minDistance = INT_MAX;

void calculate()
{
    int Distance = 0;
    for(int i = 0; i < house.size(); i++)
    {
        // 집에서 치킨 집까지의 최소 거리를 위함.
        int minHouse = INT_MAX;
        for(int j = 0; j < chicken.size(); j++)
        {
            // 조합 중 선택된 곳이라면
            if(selected[j] == 1)
            {
                int houseDistance = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
                if(houseDistance < minHouse)
                {
                    minHouse = houseDistance;
                }
            }
        }
        Distance += minHouse;
    }

    if(Distance < minDistance)
    {
        minDistance = Distance;
    }
}

void selectChickenStore()
{
    for(int i = 0; i < chicken.size() - M; i++){ selected.push_back(0);}
    for(int i = 0; i < M; i++){selected.push_back(1);}

    do{
        calculate();
    }
    while(next_permutation(selected.begin(), selected.end()));
}

int main()
{
    fastio;

    cin >> N >> M;

    int check;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> check;
            if(check == 1)
            {
                house.push_back({i, j});
            }
            else if(check == 2)
            {
                chicken.push_back({i, j});
            }
        }
    }

    selectChickenStore();
    cout << minDistance << '\n';

    return 0;
}