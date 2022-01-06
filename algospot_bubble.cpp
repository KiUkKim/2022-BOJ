#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

char graph[5][5] = {' ',};

int search_graph[5][5][10]; // 최대 10글자의 찾으려는 단어의 결과를 저장 -1로 초기화, 1 성공 0 실패

string search_word;

int search(int y, int x, int wordIdx)
{
    // 범위 체크
    if(x < 0 || x > 4 || y < 0 || y > 4)
    {
        return 0;
    }

    int ret = search_graph[y][x][wordIdx]; // 찾으려는 글자의 Idx를 저장한다.

    // 찾으려는 단어의 결과값에 -1이 아니라 결과가 있으면 그대로 반환
    if(ret != -1)
    {
        return ret;
    }

    // 내가 찾으려는 글자가 graph에 어디에 있는지 파악한다.
    if(search_word[wordIdx] != graph[y][x])
    {
        return ret = 0;
    }

    // 위 조건으로 처음 글자가 있는 곳을 찾을 것이다.
    // 다음 글자를 찾기 위해서 wordIdx를 증가시킨다.
    wordIdx++;

    // 찾으려는 글자의 인덱스가 입력한 글자보다 커질 경우, 다 찾았음을 의미한다.
    if(wordIdx >= search_word.size())
    {
        return ret = 1;
    }

    // 재귀적으로 탐색한다. 대각선좌상, 상, 대각선우상, 좌, 우, 대각선좌하, 하, 대각선우하
    return ret = (search(y-1, x-1, wordIdx) || search(y-1, x, wordIdx) || search(y-1, x+1, wordIdx) || search(y, x-1, wordIdx) || search(y, x+1, wordIdx) || search(y+1, x-1, wordIdx) || search(y+1, x, wordIdx) || search(y+1, x+1, wordIdx));

}

int main()
{
    fastio;
    
    int n; // n은 test case수, m은 찾으려는 단어의 수

    cin >> n;

    for(int k = 0; k < n; k++)
    {
        for(int i = 0 ; i < 5; i++)
        {
            for(int j = 0 ; j < 5; j++)
            {
                cin >> graph[i][j];
            }
        }

        int m;
        cin >> m;

        for(int t = 0 ; t < m ; t++)
        {
            // 찾으려는 단어가 반복될 때 마다 해당 결과값 저장 배열을 초기화
            memset(search_graph, -1, sizeof(search_graph));

            cin >> search_word;

            bool foundtrue = false; // 찾을 수 있는지 판단

            for(int l = 0; l < 5; l++)
            {
                for(int m = 0; m < 5; m++)
                {
                    if(search(l, m, 0) == 1)
                    {
                        foundtrue = true;
                        break;
                    }
                }
                if(foundtrue)
                {
                    break;
                }
            }

            if(foundtrue)
            {
                cout << search_word << " YES" << '\n';
            }
            else{
                cout << search_word << " NO" << '\n';
            }
        }
    }



    return 0;
}