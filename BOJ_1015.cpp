#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    fastio;

    pair<int, int> A_P[50];
    int size, B[50];

    cin >> size;

    for(int i=0; i < size; i++)
    {
        cin >> A_P[i].first;

        A_P[i].second = i;
    }

    sort(A_P, A_P + size);

    for(int i = 0 ; i < size; i++)
    {
        B[A_P[i].second] = i;
    }

    for(int i = 0; i < size; i++)
    {
        cout << B[i] << ' ';
    }

    return 0;
}