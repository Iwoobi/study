#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    int x,y,m;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    cin >> n;
    int xx,yy;
    for (int i = 0; i < n; i++)
    {
        int res = 0;
        stack<pair<int,int> > st;
        cin >> x >> y >> m;
        int **visit = new int*[x];
        int **map = new int*[x];
        for (int p = 0; p < x; p++)
        {
            visit[p] = new int[y];
            map[p] = new int[y];
            fill_n(visit[p], y, 0);
            fill_n(map[p], y, 0);
        }
        int lotx,loty;
        for (int j = 0; j < m; j++)
        {
            cin >> lotx >> loty;
            map[lotx][loty] = 1;
        }
        for (int p = 0; p < x; p++)
        {
            for (int q = 0; q < y; q++)
            {
                if (visit[p][q])
                    continue;
                if (map[p][q] == 1)
                {
                    st.push(make_pair(p,q));
                    res++;
                }
                while (!st.empty())
                {
                    xx = st.top().first;
                    yy = st.top().second;
                    st.pop();
                    visit[xx][yy] = 1;
                    for (int ii = 0; ii < 4; ii++)
                    {
                        int dxx = xx + dx[ii];
                        int dyy = yy + dy[ii];
                        if (dxx >= x || dxx < 0 || dyy >= y || dyy < 0)
                            continue;
                        if (visit[dxx][dyy])
                            continue;
                        if (map[dxx][dyy])
                        {
                            st.push(make_pair(dxx,dyy));
                        }
                    }
                }
                
            }
        }
        for (int j = 0; j < x; j++)
        {
            delete[] visit[j];
            delete[] map[j];
        }
        cout << res << '\n';
    }
}