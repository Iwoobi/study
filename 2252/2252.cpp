#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int node, E;
    cin >> node >> E;
    vector<int> v[node];
    int indrg[node];
    fill(indrg, indrg + node, 0);
    for (int i = 0; i < E; i++)
    {
        int a,b;
        cin >> a >>  b;
        v[a - 1].push_back(b - 1);
        indrg[b - 1] += 1;
    }
    queue<int> q;
    for (int i = 0; i < node; i++)
    {
        if (indrg[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int cur;
        cur = q.front();
        cout << cur + 1 << " ";
        if (indrg[cur])
            indrg[cur] -= 1;
        q.pop();
        for (vector<int>::iterator it = v[cur].begin(); it != v[cur].end(); it++)
        {
            indrg[*it] -= 1;
            if (indrg[*it]) continue;
            q.push(*it);
        }
    }
}