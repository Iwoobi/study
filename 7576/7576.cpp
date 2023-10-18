#include <iostream>
#include <deque>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int row,col;
	cin >> col>> row;
	deque<pair<pair<int, int>, int > > Q;
	char **map = new char*[row];
	char a;
	for (int i = 0; i < row; i++)
	{
		map[i] = new char[col];
		for (int j = 0; j < col; j++)
		{
		
			cin >> map[i][j];
			if (map[i][j] == '-')
				cin >> a;
			if	(map[i][j] == '1')
				Q.push_back({{i,j}, 0});
		}
	}
	// for (int i = 0; i < row; i++)
	// {
	// 	for (int j = 0; j < col; j++)
	// 	{
	// 		cout << map[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	// cout << "\n\n\n\n\n";
	int dx[4] = {0,0,1,-1};
	int dy[4] = {1,-1,0,0};
	int max = 0;
	while (!Q.empty())
	{
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int val = Q.front().second;
		Q.pop_front();
		if (max < val)
			max = val;
		for (int d = 0; d < 4; d++)
		{
			int vx = x + dx[d];
			int vy = y + dy[d];
			if (vx >= row || vx <0 || vy >= col || vy < 0)
				continue;
			if (map[vx][vy] == '0')
			{
				map[vx][vy] = '2';
				Q.push_back({{vx,vy}, val + 1});
			}
		}
	}
	// for (int i = 0; i < row; i++)
	// {
	// 	for (int j = 0; j < col; j++)
	// 	{
	// 		cout << visit[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	// cout << "\n";

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (map[i][j] == '0')
			{
				cout << "-1";
				return 0;
			}
		}
	}
	cout << max;
}