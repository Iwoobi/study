#include <iostream>
#include <deque>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a;
	int x,y;
	cin >> x >> y;
	int **map;
	int **visit;
	map = new int*[x];
	for (int i = 0; i < x; i++)
		map[i] = new int[y];
	for (int i =0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> map[i][j];
		}
	}
	visit = new int*[x];
	for (int i = 0; i < x; i++)
		visit[i] = new int[y];
	for (int i =0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			visit[i][j] = 0;
		}
	}
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	deque< pair<int, int> > deq;
	int max = 0;
	int size = 0;
	int count = 0;
	for (int i =0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			size = 0;
			if (visit[i][j] == 0 && map[i][j] == 1)
			{
				count++;
				int vis_x;
				int vis_y;
				deq.push_back(make_pair(i, j));
				size++;
				visit[i][j] = 1;
				while (!deq.empty())
				{
					vis_x = deq.front().first;
					vis_y = deq.front().second;
					deq.pop_front();
					for (int kk = 0; kk < 4; kk++)
					{
						int xx;
						int yy;
						xx = vis_x + dx[kk];
						yy = vis_y + dy[kk];
						if (xx < 0 || xx >= x || yy < 0 || yy >= y)
							continue;
						if (visit[xx][yy] == 0 && map[xx][yy] == 1)
						{
							visit[xx][yy] = 1;
							size++;
							deq.push_back(make_pair(xx, yy));
						}
					}
				}
				if (size > max)
					max = size;
			}
		}
	}
	cout << count << "\n" << max;

}