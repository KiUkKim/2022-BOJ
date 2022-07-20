#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair <int, int>> square;
vector<int> result;

bool compare(pair<int, int> a, pair<int,int> b)
{
    if(a.first == b.first)
    {
        return a.second < b.second;
    }

    return a.first < b.first;
}

int main()
{
    fastio;

    int T;
    cin >> T;
    int N = 4;

    while(T--)
    {
        for(int i = 0; i < 4; i++)
        {
            int first, second;

            cin >> first >> second;

            square.push_back({first, second});
        }

        for(int i = 0 ; i < 4; i++)
        {
            for(int j = i+1; j < 4; j++)
            {
                result.push_back( (square[i].first- square[j].first) * ( square[i].first- square[j].first) + (square[i].second - square[j].second) * (square[i].second - square[j].second)); 
            }
        }

        sort(result.begin() , result.end());

        if(result[0] == result[1] && result[1] == result[2] && result[2] == result[3] && result[4] == result[5])
        {
            cout << "1\n";
        }
        else{
            cout << "0\n";
        }

        result.clear();
        square.clear();
    }

    return 0;
}