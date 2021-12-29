#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    fastio;

    int N, F;
    
    cin >> N >> F;

    int temp = N;

    int temp_i = temp / 100;

    temp -= temp_i * 100;

    N -= temp;

    if(N % F == 0)
    {
        cout << "00" << '\n';
    }
    else{
        int result = F - (N%F);
        if(result / 10 == 0)
        {
            cout << '0' << result << '\n';
        }
        else{
            cout << result << '\n';
        }
    }

    return 0;
}