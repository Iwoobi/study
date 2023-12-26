#include <iostream>
#include <queue>
using namespace std;

void dfs()
{
    int x,y;
    int dx[4] = {1, -1, 0,0};
    int dy[4] = {0,0,1,-1};
    cin >> x >> y;
    queue<pair<pair<int,int>,pair<int,int>>> dq;
    char **map = new char*[y];
    int **visit = new int*[y];
    int lot_x,lot_y;
    for (int i = 0; i < y; i++)
    {
        map[i] = new char[x];
        visit[i] = new int[x];
        fill_n(visit[i], x, 0);
        for (int j = 0; j < x; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == '*')
            {
                dq.push(make_pair(make_pair(i,j),make_pair(0,1)));
                visit[i][j] = 1;
            }
            else if (map[i][j] == '@')
            {
                lot_x = i;
                lot_y = j;
            }
        }
    }
    dq.push(make_pair(make_pair(lot_x, lot_y),make_pair(0,0)));
    visit[lot_x][lot_y] = 1;
    while (!dq.empty())
    {
        int xx = dq.front().first.first;
        int yy = dq.front().first.second;
        int d = dq.front().second.first;
        int type = dq.front().second.second;
        dq.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if (nx < 0 || ny < 0 || nx >= y || ny >= x)
            {
                if (type == 0)
                {
                    cout << d + 1 << "\n";
                    for (int i = 0; i < y; i++)
                    {
                        delete[] map[i];
                        delete[] visit[i];
                    }
                    delete[] map;
                    delete[] visit;
                    return;
                }
                continue;
            }
            if (map[nx][ny] == '#')
                continue;
            if (type == 0)
            {
                if (map[nx][ny] == '*')
                    continue;
            }
            if (type == 1)
            {
                if (map[nx][ny] == '*')
                    continue;
                map[nx][ny] = '*';
            }
            if (visit[nx][ny] == 1)
                continue;
            visit[nx][ny] = 1;
            dq.push(make_pair(make_pair(nx, ny),make_pair(d+1,type)));
        }
    }

    cout << "IMPOSSIBLE\n";
    for (int i = 0; i < y; i++)
    {
        delete[] map[i];
        delete[] visit[i];
    }
    delete[] map;
    delete[] visit;
    
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n ;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        dfs();
    }
}