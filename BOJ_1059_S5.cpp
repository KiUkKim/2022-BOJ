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

    int n, num, search_num;
    int S[50] = {0,};
    int search_s[2] = {0,};
    cin >> n;

    for(int i=0; i < n; i++)
    {
        cin >> S[i];
    }

    sort(S, S+n);

    cin >> search_num;

    for(int i = 0; i < n; i++)
    {
        // 특이 조건, 정렬 배열에서 0번째 배열이 search_num보다 클 경우
        if(search_num < S[0])
        {
            search_s[0] = 0;
            search_s[1] = S[0];
            break;
        }
        else if(search_num > S[i] && search_num < S[i+1])
        {
            search_s[0] = S[i];
            search_s[1] = S[i+1];
            break;
        }
        else
        {
            search_s[0] = -1;
        }
    }
    

    int cnt = 0;

    while(true)
    {   
        // 범위내에 존재하지 않는다면 0을 출력 (집합에서 최적의 구간을 찾을 수 없다.)
        if(search_s[0] == - 1)
        {
            break;
        }

        // 조건 1. A+1이 찾으려는 숫자와 같을 때, 앞쪽에 위치.
        // 이 때, B-1에서 찾으려는 숫자만큼 카운팅
        if(search_num == search_s[0] + 1)
        {
            cnt += search_s[1] - search_num - 1;
            break;
        }

        // 조건 2. 

        // 조건 3. A+1이 찾으려는 숫자와 같지 않을 때, 뒤쪽에 위치
        // 이 때, A+1이 찾으려는 숫자와 같아 질 때 까지 카운팅 증가
        // 카운팅은 B-찾으려는 숫자만큼 카운팅
        else{
            cnt += search_s[1] - search_num;
        }

        search_s[0] += 1;
    }

    cout << cnt << '\n';

    return 0;
}