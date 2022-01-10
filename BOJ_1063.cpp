#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

// R, L, B, T, RT, LT, RB, LB
int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

int main()
{
    fastio;

    string king, stone;
    int kx, ky, sx, sy, N;
    string location;
    int dir = 0;

    cin >> king >> stone >> N;

    for(int i = 0; i < 2; i++)
    {
        // 앞 글자 영어
        if(i == 0)
        {
            ky = king[i] - 'A';
            sy = stone[i] - 'A';
        }

        else{
            kx = '8' - king[i];
            sx = '8' - stone[i];
        }
    }

    while(N--)
    {
        cin >> location;

        // 초기 조건 범위 그대로 일때는 위치 변화 x
        if(location == "R")
        {
            dir = 0;
        }
        else if(location == "L")
        {
            dir = 1;
        }
        else if(location == "B")
        {
            dir = 2;
        }
        else if(location == "T")
        {
            dir = 3;
        }
        else if(location == "RT")
        {
            dir = 4;
        }
        else if(location == "LT")
        {
            dir = 5;
        }
        else if(location == "RB")
        {
            dir = 6;
        }
        else{
            dir = 7;
        }
        
        int kingLocation_dy = ky + dy[dir];
        int kingLocation_dx = kx + dx[dir];

        if(kingLocation_dy < 0 || kingLocation_dy >= 8 || kingLocation_dx < 0 || kingLocation_dx >= 8)
        {
            continue;
        }
        
        if(kingLocation_dy == sy && kingLocation_dx == sx)
        {
            int stoneLocation_dy = sy + dy[dir];
            int stoneLocation_dx = sx + dx[dir];
            if(stoneLocation_dy < 0 || stoneLocation_dy >= 8 || stoneLocation_dx < 0 || stoneLocation_dx >= 8)
            {
                continue;
            }
            sy = stoneLocation_dy;
            sx = stoneLocation_dx;
        }

        ky = kingLocation_dy;
        kx = kingLocation_dx;
    }

    cout << (char)(ky + 'A') << (char)('8' - kx) << '\n';
    cout << (char)(sy + 'A') << (char)('8' - sx) << '\n';

    return 0;
}