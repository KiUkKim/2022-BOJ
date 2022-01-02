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

    string name;
    int n;    
    int count_name[26] = {0,};

    cin >> n;
    
    while(n)
    {
        cin >> name;
        
        count_name[name[0] - 'a']++;

        n--;
    }

    int PREDAJA = 1;

    for(int i=0; i <26; i++)
    {
        if(count_name[i] >= 5)
        {
            cout << char(i + 'a');
            PREDAJA++;
        }
    }

    if(PREDAJA == 1)
    {
        cout << "PREDAJA" << '\n';
    }

    return 0;
}