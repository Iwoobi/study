#include <iostream>
#include <queue>
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int x, y;
    cin >> x >> y;
    int ***visit = new int **[x];
    int **map = new int *[x];
    for (int i = 0; i < x; i++)
    {
        visit[i] = new int*[y];
        map[i] = new int[y];
        for (int j = 0; j < y; j++)
        {
            visit[i][j] = new int[2];
        }
    }
}