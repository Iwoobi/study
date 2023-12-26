#include <iostream>
#include <stack>
using namespace std;
int map[100][100];
int visit[100][100];
int list[101];

int dfs(int max,int n)
{
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < n; i++)
    {
        fill_n(visit[i],n,0);
    }
    stack<pair<int,int>> st;
    int size = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visit[i][j])
                continue;
            if (map[i][j] <= max)
                continue;
            size++;
            st.push(make_pair(i,j));
            visit[i][j] = 1;
            while(!st.empty())
            {
                int xx = st.top().first;
                int yy = st.top().second;
                st.pop();
                for (int nn = 0; nn < 4; nn++)
                {
                    int nx = xx + dx[nn];
                    int ny = yy + dy[nn];
                    if (nx >= n || ny >= n || nx <0|| ny<0)
                        continue;
                    if (visit[nx][ny])
                        continue;
                    if (map[nx][ny] <= max)
                        continue;
                    visit[nx][ny] = 1;
                    st.push(make_pair(nx,ny));   
                }
            }
        }
    }
    return size;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (list[map[i][j]] == 0)
                list[map[i][j]] = 1;
        }
    }
    list[0] = 1;
    int res = 0;
    int max = 0;
    for (int i = 0; i <= 100; i++)
    {
        if (list[i])
        {
            res = dfs(i, n);
            if (max < res)
                max = res;
        }
    }
    cout << max;
    
}