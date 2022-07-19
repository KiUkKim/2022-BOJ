#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

bool check;

void binary(string input, int startIdx, int endIdx)
{
    int left = startIdx;
    int right = endIdx;
    int mid = (left + right) / 2;
    
    if(!check || left > right)
    {
        return;
    }

    for(int ll = mid-1, rr= mid+1; ll >= startIdx; ll--, rr++)
    {
        if(input[ll] == input[rr])
        {
            check = false;
            return;
        }
    }

    // 왼쪽 분할
    binary(input, left, mid-1);

    // 오른쪽 분할
    binary(input, mid+1, right);


}

int main()
{
    fastio;

    string S;

    int T;

    cin >> T;

    while(T--)
    {
        cin >> S;

        if(S.length() % 2 == 0)
        {
            cout << "NO\n";
            continue;
        }
        check = true;
        
        binary(S, 0, S.length() - 1);

        if(check)
        {
            cout << "YES\n";
        }
        
        else{
            cout << "NO\n";
        }
    }

    return 0;
}