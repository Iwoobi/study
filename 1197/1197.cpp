#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;
int *p;

int find(int x)
{
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}


int diff_f(int a, int b)
{
    a = find(a); b = find(b);
    if (a == b) return 0;
    if (p[a] == p[b]) p[a]--;
    if (p[a] < p[b]) p[b] = a;
    else p[a] = b;
    return 1;
}   
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int node, E;
    cin >> node >> E;
    tuple<int, int, int> edge[E];
    p = new int[E + 1];
    fill(p, p+E + 1, -1);
    for(int i = 0; i < E; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        edge[i] = {c, a, b};
    }
    sort(edge, edge + E);
    int cnt = 0, sol = 0;
    for (int i = 0; i < E; i++)
    {
        int a,b,c;
        tie(c, a, b) = edge[i];
        if (!diff_f(a,b))
            continue;

        sol += c;
        cnt++;
        if (cnt == node - 1)
            break;
    }
    cout << sol;
}