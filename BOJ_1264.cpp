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

    string A;
    int cnt = 0;

    while(true)
    {
        getline(cin, A);

        for(int i=0; i < A.size(); i++)
        {
            if(A[i] == 'a'|| A[i] == 'a' - 32 || A[i] == 'e'|| A[i] == 'e' - 32 || A[i] == 'o' || A[i] == 'o' - 32 || A[i] == 'u' || A[i] == 'u'-32 || A[i] == 'i' || A[i] == 'i'-32 )
            {
                cnt++;
            }
        }

        if(A[0] == '#')
        {
            break;
        }
        
        
        cout << cnt << '\n';
        cnt = 0;
    }
    return 0;
}