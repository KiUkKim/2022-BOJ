#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

double xa, ya, xb, yb, xc, yc;

double square_dist(double X1, double Y1, double X2, double Y2)
{
    return sqrt( ( (X2-X1)*(X2-X1) ) + ( (Y2-Y1) * (Y2-Y1)) );
}

int main()
{
    fastio;

    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    double D1 = 987654321;
    double D2 = 987654321;

    if(xa != xb)
    {
        D1 = abs(yb-ya) / abs(xb-xa);
    }
    if(xb != xc)
    {
        D2 = abs(yc-yb) / abs(xc-xb);
    }

    // 세 개의 점이 같은 위치에 있을 경우 평행사변형을 만들 수 없는 경우
    if(D1 == D2)
    {
        cout << -1 << '\n';
        return 0;
    }

    // 세 개의 점 길이 구하는 방식 3가지
    double L1 = square_dist(xa, ya, xb, yb);
    double L2 = square_dist(xb, yb, xc, yc);
    double L3 = square_dist(xa, ya, xc, yc);

    // 세 개의 조합 중 가장 큰 둘레 길이 - 가장 작은 둘레의 길이 해주기
    double square_len = 2*(L1+L2);
    double square_len2 = 2*(L1+L3);
    double square_len3 = 2*(L2+L3);

    cout << fixed;
    cout.precision(20);

    cout << max(square_len, max(square_len2, square_len3)) - min(square_len, min(square_len2, square_len3)) << '\n'; 

    return 0;
}