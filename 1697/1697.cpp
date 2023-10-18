#include <iostream>
#include <queue>
using namespace std;
void move(int &a, int i)
{
	if (i == 0)
		a += 1;
	else if (i == 1)
		a -= 1;
	else if (i == 2)
	{
		a *=2;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	cin >> a >> b;
	int *visit = new int[(b+1)*2];
	for (int i = 0;  i < 2*(b+1); i++)
		visit[i] = 0;
	if (a == b)
	{
		cout << "0";
		return 0;
	}
	if (a > b)
	{
		cout << a - b;
		return 0;
	}
	queue<pair<int, int>> Q;
	Q.push({a,0});
	visit[a] = 1;
	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 3; i++)
		{
			int vx = x;
			move(vx, i);
			if (vx == b)
			{
				cout << y + 1;
				return 0;
			}
			if (vx == x)
				continue;
			if (vx > b + 1)
				continue;
			if (x - b > 0 && vx - b > 0)
			{
				if (x - b < vx - b)
					continue;
			}
			if (vx < 0)
				continue;
			if (visit[vx] == 0)
			{
				visit[vx] = 1;
				Q.push({vx, y+1});
			}
		}
	}

}