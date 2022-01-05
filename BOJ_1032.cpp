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

    vector<char> cnt_str;

    int n, N, str_size;

    cin >> n;
    N = n;
    while(n)
    {
        string str_;

        cin >> str_;

        for(int i=0; i < str_.size(); i++)
        {
            cnt_str.push_back(str_[i]);
        }

        str_size = str_.size();

        n--;
    }

    vector<char> result_str;
    int cnt;

    for(int i=0; i < str_size; i++)
    {
        cnt = 1;
        for(int j = 1; j < N; j++)
        {
            if(cnt_str[i] == cnt_str[i + (j*str_size)])
            {
                cnt++;
            }
        }

        if(cnt == N)
        {
            result_str.push_back(cnt_str[i]);
        }

        else{
            result_str.push_back('?');
        }
    }
    

    for(auto &v: result_str)
    {
        cout << v;
    }

    return 0;
}