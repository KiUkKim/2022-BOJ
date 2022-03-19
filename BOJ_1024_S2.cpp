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

    int N, L;

    cin >> N >> L;

    // (x + 1) ~ (x + L) 까지 출력
    for(int i = L; i <= 100; i++)
    {
        int Lx = N - (i * ( i + 1) ) / 2;

        if(Lx % i == 0)
        {
            int x = Lx / i + 1;

            if(x >= 0)
            {
                for(int j = 0; j < i; j++)
                {
                    cout << x + j << ' ';
                }
                cout << '\n';
                return 0;
            }
        }
    }

    cout << "-1" << '\n';
    return 0;
}