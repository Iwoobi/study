#include <iostream>
#include <queue>
using namespace std;

void    dfs(int n, int x, int y)
{
    char ***map = new char**[n];
    int ***visit = new int**[n];
    queue<pair<pair<int,int>,pair<int,int>>> qu;
    string input;
    for (int i = 0; i < n; i++)
    {
        map[i] = new char*[x];
        visit[i] = new int*[x];
        for (int j = 0 ; j < x; j++)
        {
            map[i][j] = new char[y];
            visit[i][j] = new int[y];
            fill_n(visit[i][j], y, 0);
            cin >> input;
            for (int k = 0; k < y; k++)
            {
                map[i][j][k] = input[k]; 
                if (map[i][j][k] == 'S')
                {
                    qu.push(make_pair(make_pair(i,j),make_pair(k,0)));
                    visit[i][j][k] = 1;
                }
            }
        }
    }
    int dx[6] = {1, -1, 0, 0, 0, 0};
    int dy[6] = {0, 0, 1, -1, 0,0};
    int dn[6] = {0,0,0,0,1,-1};
    while (!qu.empty())
    {
        int nnn = qu.front().first.first;
        int xx = qu.front().first.second;
        int yy = qu.front().second.first;
        int gl = qu.front().second.second;
        qu.pop();
        for (int i = 0; i < 6; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            int nn = nnn + dn[i];
            if (nn >= n || ny >= y || nx >= x || nx < 0 || ny < 0|| nn <0)
                continue;
            if (visit[nn][nx][ny])
                continue;
            if (map[nn][nx][ny] == '#')
                continue;
            if (map[nn][nx][ny] == 'E')
            {
                cout <<"Escaped in "<<gl + 1<< " minute(s).\n";
                return;
            }
            visit[nn][nx][ny] = 1;
            qu.push(make_pair(make_pair(nn,nx),make_pair(ny,gl+1)));
        }
    }
    cout << "Trapped!\n";
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,x,y;
    while (1)
    {
        cin >> n >> x>> y;
        if (n == 0 || x == 0 || y == 0)
            return 0;
        dfs(n,x,y);
    }
}