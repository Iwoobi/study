#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> v[N + 1];
    for (int i = 0; i < N - 1; i++)
    {
        int st,en;
        cin >> st >> en;
        v[st].push_back(en);
        v[en].push_back(st);

    }
    int par[N + 1];
    fill(par, par + N + 1, 0);
    par[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int node;
        node = q.front();
        q.pop();
        for (vector<int>::iterator it = v[node].begin(); it != v[node].end(); it++)
        {
            if (par[*it] != 0)  continue;
            par[*it] = node;
            q.push(*it);
        }
    }
    for (int i = 2; i < N + 1; i++)
        cout << par[i] << "\n";
}