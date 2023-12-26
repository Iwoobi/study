#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int x,y,n;
    cin >> y >> x >> n;
    int **map = new int*[y];
    int **visit = new int*[y];
    for (int i = 0; i < y; i++)
    {
        visit[i] = new int[x];
        map[i] = new int[x];
        fill_n(visit[i], x, 0);
        fill_n(map[i], x, 0);
    }
    int sx,sy,fx,fy;
    for (int i = 0; i < n; i++)
    {
        cin >> sx >> sy >> fx >> fy;
        for (int yy = 0; yy < fy - sy; yy++)
        {
            for (int xx = 0; xx < fx - sx; xx++)
            {
                map[sy + yy][sx + xx] = 1;
            }
        }
    }
    stack<pair<int,int>> st;
    vector<int> res;
    int total = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (visit[i][j])
                continue;
            if (map[i][j] == 1)
                continue;
            visit[i][j] = 1;
            total++;
            int size = 0;
            st.push(make_pair(i,j));
            while (!st.empty())
            {
                int xx = st.top().second;
                int yy = st.top().first;
                size++;
                st.pop();
                for (int nn = 0; nn < 4; nn++)
                {
                    int nx = xx + dx[nn];
                    int ny = yy + dy[nn];
                    if (nx >= x || ny >= y || nx < 0 || ny < 0)
                        continue;
                    if (visit[ny][nx] || map[ny][nx])
                        continue;
                    visit[ny][nx] = 1;
                    st.push(make_pair(ny,nx));
                }
            }
            res.push_back(size);
        }
    }
    cout << total << "\n";
    sort(res.begin(), res.end());
    for (int j = 0; j < res.size(); j++)
    {
        cout << res[j] << " ";
    }
}