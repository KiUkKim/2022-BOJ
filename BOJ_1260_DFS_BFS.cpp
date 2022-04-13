#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

// 간선
vector <int> graph[10001];

// 정점
bool visited[1001] = {false, };


int n, m, v;


// stack으로 구현한 DFS
void Stack_DFS(int verse)
{
    stack<int> dfs;

    dfs.push(verse);


    // stack이 비워진다면 dfs 탐색 완료
    while(!dfs.empty()){
        int visitVerse;
        visitVerse = dfs.pop();
        visited[visitVerse] = true;
        cout << visitVerse << ' ';

        for(int i=0; i < n; i++)
        {
            if(graph[visitVerse][i] == 1 && !visited[visitVerse])
            {
                dfs.push(graph[visitVerse][i]);
                break;
            }
        }
    }
}


int main()
{
    fastio;

    cin >> n >> m >> v;

    for(int i=0; i < m; i++)
    {
        int v1, v2;

        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for(int i=1; i < n+1; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    Stack_DFS(v);


    return 0;
}