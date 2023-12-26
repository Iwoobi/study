#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int **map = new int*[n];
    int **visit = new int*[n];
    for (int i = 0; i < n; i++)
    {
        map[i] = new int[n];
        visit[i] = new int[n];
        fill_n(visit[i],n,0);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char tmp;
            cin >> tmp;
            map[i][j] = tmp - '0';
        }
    }
    stack<pair<int,int>> st;
    vector<int> res;
    int dx[4] = {1, -1, 0,0};
    int dy[4] = {0,0,1,-1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visit[i][j])
                continue;
            if (map[i][j] == 0)
                continue;
            visit[i][j] = 1;
            st.push(make_pair(i,j));
            int size = 0;
            while(!st.empty())
            {
                int xx = st.top().second;
                int yy = st.top().first;
                st.pop();
                size++;
                for (int nn = 0; nn < 4; nn++)
                {
                    int nx = xx + dx[nn];
                    int ny = yy + dy[nn];
                    if (nx >= n || ny >= n || ny <0 || nx<0)
                        continue;
                    if (visit[ny][nx] || map[ny][nx] == 0)
                        continue;
                    visit[ny][nx] = 1;
                    st.push(make_pair(ny,nx));
                }
            }
            if (size)
                res.push_back(size);
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << '\n';
    }
}