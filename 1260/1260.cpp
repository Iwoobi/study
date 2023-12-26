#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int visit[1000];
vector<int> v[1000];
void dfs(int start)
{
    visit[start] = 1;
    cout << start + 1 << " ";
    for (vector<int>::iterator it = v[start].begin(); it != v[start].end(); it++)
    {
        if (visit[*it])
            continue;
        dfs(*it);
    }
}
void bfs(int &start)
{
    queue<int> q;
    q.push(start - 1);
    visit[start - 1] = 1;
    while(!q.empty())
    {
        int cur = q.front();
        cout << cur + 1 << ' ';
        q.pop();
        for (vector<int>::iterator it = v[cur].begin(); it != v[cur].end(); it++)
        {
            if (visit[*it])
                continue;
            q.push(*it);
            visit[*it] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int node,e,start;
    cin >> node >> e >> start;
    for (int i = 0; i < e; i++)
    {
        int st,ed;
        cin >> st;
        cin >> ed;
        v[st - 1].push_back(ed - 1);
        v[ed - 1].push_back(st - 1);
    }
    for (int i = 0; i < node; i++)
        sort(v[i].begin(), v[i].end());
    dfs(start - 1);
    cout << "\n";
    fill(visit, visit + node, 0);
    bfs(start);
}