#include <iostream>
#include <stack>
using namespace std;
bool visit1[100][100];
bool visit2[100][100];
char map[100][100];
char color;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int nx,ny;
    int res = 0;
    int res1 = 0;
    stack<pair<int,int>> st;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visit1[i][j])
                continue;
            visit1[i][j] = true;
            color = map[i][j];
            res++;
            st.push(make_pair(i,j));
            while (!st.empty())
            {
               nx = st.top().first;
               ny = st.top().second;
               visit1[nx][ny] = true;
               st.pop();
               for (int k = 0; k < 4; k++)
               {
                    int ddx = nx + dx[k];
                    int ddy = ny + dy[k];
                    if (ddx >= n || ddx < 0 || ddy >= n || ddy < 0)
                        continue;
                    if (visit1[ddx][ddy])
                        continue;
                    if (map[ddx][ddy] != color)
                        continue;
                    st.push(make_pair(ddx,ddy));
               }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visit2[i][j])
                continue;
            visit2[i][j] = true;
            color = map[i][j];
            res1++;
            st.push(make_pair(i,j));
            while (!st.empty())
            {
               nx = st.top().first;
               ny = st.top().second;
               visit2[nx][ny] = true;
               st.pop();
               for (int k = 0; k < 4; k++)
               {
                    int ddx = nx + dx[k];
                    int ddy = ny + dy[k];
                    if (ddx >= n || ddx < 0 || ddy >= n || ddy < 0)
                        continue;
                    if (visit2[ddx][ddy])
                        continue;
                    if (color == 'R' || color == 'G')
                    {
                        if (map[ddx][ddy] == 'B')
                            continue;
                    }
                    else if (map[ddx][ddy] != color)
                        continue;
                    st.push(make_pair(ddx,ddy));
               }
            }
        }
    }
    cout << res << ' ' << res1;
}