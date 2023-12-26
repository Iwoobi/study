#include <iostream>
#include <queue>
using namespace std;
void dfs()
{
    queue<pair<pair<int,int>,int>> qu;
    int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int l;
    cin >> l;
    int **map = new int*[l];
    int **visit = new int *[l];
    for (int xx = 0; xx < l; xx++)
    {
        map[xx] = new int[l];
        visit[xx] = new int[l];
        fill_n(visit[xx],l,0);
        fill_n(map[xx],l,0);
    }
    int x,y,gx,gy;
    cin >> x >> y >> gx >> gy;
    if (x == gx && y == gy)
        cout << "0\n";
    qu.push(make_pair(make_pair(x,y), 0));
    visit[x][y] = 1;
    while (!qu.empty())
    {
        
        int xx = qu.front().first.first;
        int yy = qu.front().first.second;
        int d = qu.front().second;
        qu.pop();
        for (int a = 0; a < 8; a++)
        {
            int nx = xx + dx[a];
            int ny = yy + dy[a];
            if (nx >= l || ny >=l || nx < 0 || ny < 0)
                continue;
            if (visit[nx][ny])
                continue;
            if (nx == gx && ny == gy)
            {
                cout << d + 1 << '\n';
                for (int aa = 0; aa < l; aa++)
                {
                    delete[] map[aa];
                    delete[] visit[aa];
                }
                delete map;
                delete visit;
                return;
            }
            visit[nx][ny] = 1;
            // cout << "asd\n";
            // cout << "x : " << nx << " y : "<< ny << " d : "<< d<<'\n';

            qu.push(make_pair(make_pair(nx,ny), d+1));
        }
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        dfs();
    }
    
    
}