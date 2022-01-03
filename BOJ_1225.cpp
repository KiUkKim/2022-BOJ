#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main()
{
    fastio;

    string A, B;
    ll sum = 0;

    cin >> A >> B;

    for(int i = 0; i < A.size(); i++)
    {
        for(int j = 0; j < B.size(); j++)
        {
            sum += (A[i] - '0') * (B[j] - '0');
        }
    }

    cout << sum << '\n';

    return 0;
}