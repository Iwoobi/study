#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int row,col;
	int rot[2];
	cin >> row >> col;
	char **map = new char*[row];
	queue<pair<pair<int, int>, int> > Q;
	for (int i = 0; i < row; i++)
	{
		map[i] = new char[col];
		for (int j = 0 ; j < col; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'J')
			{
				rot[0] = i;
				rot[1] = j;
			}
			if  (map[i][j] == 'F')
				Q.push({{i, j}, -1});
		}
	}
	int dx[4] = {0,0,1,-1};
	int dy[4] = {1,-1,0,0};
	Q.push({{rot[0],rot[1]}, 0});
	while (!Q.empty())
	{
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int val = Q.front().second;
		Q.pop();
		for (int d = 0; d < 4; d++)
		{
			int vx = x + dx[d];
			int vy = y + dy[d];
			if (vx < 0 || vx >= row || vy >= col || vy < 0)
			{
				if (val != -1)
				{
					cout << val + 1;
					return 0;
				}
				else
					continue;
			}
			if (map[vx][vy] == '#')
				continue;
			if (map[vx][vy] == '.')
			{
				if (val == -1)
				{
					map[vx][vy] = 'F';
					Q.push({{vx,vy}, -1});
				}
				else
				{
					map[vx][vy] = 'J';
					Q.push({{vx,vy}, val + 1});
				}
			}
		}
	}
	cout  << "IMPOSSIBLE";
}