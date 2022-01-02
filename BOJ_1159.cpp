#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    fastio;

    int n; // 테스트 케이스 수
    string team_name; // 선수 이름
    vector<char> first_name; // 선수 명단의 성 첫 글자 저장.
    vector<char> ava_team; // 가능한 선수 성

    cin >> n;

    while(n)
    {
            cin >> team_name;

            char first = team_name[0];

            first_name.push_back(first);

            n--;
    }

    sort(first_name.begin(), first_name.end());

    char start = first_name[0];
    int cnt = 1;
    for(int i = 1 ; i < first_name.size(); i++)
    {
        if(start == first_name[i])
        {
            cnt++;

            if(i == first_name.size()-1 && cnt >= 5)
            {
                ava_team.push_back(start);
                break;
            }
        }
        else{
            if(cnt >= 5)
            {
                ava_team.push_back(start);
            }
            
            start = first_name[i];
            cnt = 1;
        }
    }

    if(ava_team.empty())
    {
        cout << "PREDAJA" << '\n';
    }
    else{
        for(auto &k : ava_team)
        {
            cout << k;
        }
    }

    return 0;
}