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

    int cas;
    int fest_day; // 공연장 대여 할 수 있는 날
    int band_ava; // 섭외된 밴드 수
    int value; // 공연장 비용
    double min; // 최소값 비교를 위함
    double sum; // 합계를 위함
    vector<int> fest; // 공연장 비용 저장을 위한 vector

    cout.precision(11); // 소수점 아래 자리수 설정
    
    cin >> cas;
    
    while(cas)
    {
        cin >> fest_day >> band_ava;
        min = 9999;

        for(int i = 0; i < fest_day; i ++)
        { 
            cin >> value;

            fest.push_back(value);
        }

        while(band_ava <= fest_day)
        {
            for(int i = 0 ; i < fest.size() - band_ava + 1 ; i++)
            {
                sum = 0;
                for(int j = i; j < i + band_ava; j++)
                {
                    sum += fest[j];
                }
                if(min > (sum / band_ava) )
                {
                    min = (sum / band_ava);
                }
            }
            band_ava++;
        }

        cout << min << '\n';
        fest.clear();
        cas--;
    }

    return 0;
}