#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

// 처리해야 될 것 : c^ -> c=, c` -> c-, dz -> dz=, d -> d-, lj -> lj, nj -> nj, s->s=, z -> z=

int main()
{
    fastio;

    string str;

    cin >> str;

    int cnt = 0;

    for(int i=0; i < str.length(); i++)
    {
        if(str[i] == 'c'){
            if(str[i+1] == '=' || str[i+1] == '-')
            {
                i += 1;
            }
        }

        else if(str[i] == 'd')
        {
            if(str[i+1] == 'z')
            {
                if(str[i+2] == '=')
                {
                    i += 2;
                }
            }

            else if(str[i+1] == '-')
            {
                i += 1;
            }
            
        }

        else if(str[i] == 'l')
        {
            if(str[i+1] == 'j')
            {
                i += 1;
            }
        }

        else if(str[i] == 'n')
        {
            if(str[i+1] == 'j')
            {
                i +=1;
            }
        }

        else if(str[i] == 's')
        {
            if(str[i+1] == '=')
            {
                i += 1;
            }
        }

        else if(str[i] == 'z')
        {
            if(str[i+1] == '=')
            {
                i += 1;
            }
        }


        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}