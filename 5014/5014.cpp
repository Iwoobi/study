#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    queue<pair<int,int>> qu;
    int n,s,g,u,d;
    cin >> n >> s>> g >> u >>d;
    qu.push(make_pair(s,0));
    int *visit = new int[n];
    fill_n(visit,n,0);
    int dx[2];
    dx[0] = u;
    dx[1] =-1 * d;
    if (s == g)
    {
        cout << 0;
        return 0;
    }
    while (!qu.empty())
    {
        int xx = qu.front().first;
        int lot = qu.front().second;
        visit[xx - 1] = 1;
        qu.pop();
        for (int i = 0; i < 2; i++)
        {
            int nx = xx + dx[i];
            if (nx > n || nx < 1)
                continue;
            if (visit[nx - 1])
                continue;
            if (nx == g)
            {
                cout << lot + 1;
                return 0;
            }
            visit[nx - 1] = 1;
            qu.push(make_pair(nx, lot + 1));
        }
    } 
    cout << "use the stairs";
}