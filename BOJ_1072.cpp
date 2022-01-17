#define MAX 1000000000 
#include <iostream> 
using namespace std; 
typedef long long ll;

int main() 
{ 
    ll X, Y, Z;

    cin >> X >> Y;

    Z = (Y * 100/X);

    while(true)
    {
        ll left = 1;
        ll right = MAX;

        if(Z >= 99)
        {
            cout << -1 << '\n';
            break;
        }

        else{
            while(left <= right)
            {
                ll mid = (left + right) / 2;

                ll tmp = (100 * (Y + mid) / (X + mid));

                if(tmp <= Z)
                {
                    left = mid + 1;
                }

                else{
                    right = mid - 1;
                }
            }
        }

        cout << left << '\n';
        break;
    }

    return 0;
}
