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

    vector<int> v;

    int arr[11];
    int N;

    cin >> N;

    for(int i=0; i <N; i++)
    {
        cin >> arr[i];
    }

    for(int i=N-1; i>=0; i--)
    {
        vector<int>::iterator iter = v.begin();

        for(int j=0; j < arr[i]; j++)
        {
            iter++;
        }

        v.insert(iter, i+1);
    }

    for(auto &v : v)
    {
        cout << v << ' ';
    }

    return 0;
}