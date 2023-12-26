#include <iostream>
#include <queue>
using namespace std;
int map[100][100][100];
int visit[100][100][100];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m,h;
    cin >> n >> m >> h;
    int dx[6] = {1, -1, 0, 0, 0 ,0};
    int dy[6] = {0,0, 1, -1,0,0};
    int dz[6] = {0, 0, 0, 0, 1, -1};
    int ans = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> map[i][j][k];
            }
        }
    }
    queue<pair<pair<int,int>,pair<int, int>>> qu;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (visit[i][j][k])
                    continue;
                if (map[i][j][k] == 1)
                {
                    qu.push(make_pair(make_pair(i,j),make_pair(k,0)));
                    visit[i][j][k] = 1;
                }
            }
        }
    }
    while (!qu.empty())
    {
        int xx,yy,zz;
        zz = qu.front().first.first;
        yy = qu.front().first.second;
        xx = qu.front().second.first;
        int deep =qu.front().second.second;
        qu.pop();
        for (int nn = 0; nn < 6; nn++)
        {
            int nz = zz + dz[nn];
            int ny = yy + dy[nn];
            int nx = xx + dx[nn];
            if (nz >= h || nz < 0 || ny >= m || ny < 0 || nx >= n || nx <0)
                continue;
            if (map[nz][ny][nx] != 0)
                continue;
            visit[nz][ny][nx] = 1;
            ans = deep + 1;
            qu.push(make_pair(make_pair(nz,ny),make_pair(nx,deep + 1)));
            map[nz][ny][nx] = 1;
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (map[i][j][k] == 0)
                {
                    cout << "-1";
                    return 0;
                }
                    
            }
        }
    }
    cout << ans;

}