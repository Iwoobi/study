#include <iostream>
#include <queue>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	queue<pair< pair<int, int>, int > > Q;
	int row,col;
	int dx[4] = {0, 0, 1 , -1};
	int dy[4] = {1, -1, 0, 0};
	cin >> row >> col;
	string *map = new string[row];
	int **visit = new int*[row];
	for (int i = 0; i < row; i++)
	{
		cin >> map[i];
		visit[i] = new int[col];
		for (int j = 0; j < col; j++)
		{
			visit[i][j] = 0;
		}
	}
	Q.push(make_pair(make_pair(0, 0), 1));
	visit[0][0] = 1;
	while(!Q.empty())
	{
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int val_map = Q.front().second;
		Q.pop();
		for (int d = 0; d < 4; d++)
		{
			int vis_x = x + dx[d];
			int vis_y = y + dy[d];
			if (vis_x >= row || vis_y >= col || vis_x <0 || vis_y <0) continue;
			if (visit[vis_x][vis_y] == 0 && map[vis_x][vis_y] == '1')
			{
				visit[vis_x][vis_y] = val_map + 1;
				Q.push(make_pair(make_pair(vis_x, vis_y), val_map + 1));
			}
		}
	}
	cout << visit[row - 1][col - 1];
}

