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

    int N;

    cin >> N;

    int result = 0;

    for(int i = 0; i <= N; i++)
    {
        // 자리수가 한 자리 수 일 때,
        if(i > 0 && i < 10)
        {
            result += 1;
        }

        // 자리수가 두 자리 수 일 때,
        if(i > 9 && i < 100)
        {
            result += 1;
        }

        // 자리수가 세 자리 수 일 때,
        // 1. 등차 수열이 같을 때 
        if(i > 99 && i < 1000)
        {
            int num = i;

            int n1 = num / 100;
            num -= n1 * 100;

            int n2 = num / 10;
            num -= n2 * 10;

            if( (n2 - n1) == (num - n2) )
            {
                result += 1;
            } 
            
        }
    }

    cout << result << '\n';

    return 0;
}