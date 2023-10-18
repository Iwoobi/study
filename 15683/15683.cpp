#include <iostream>
#include <vector>


using namespace std;
vector<pair<int,int> > v;
int row,col;
int res;
int	left(int count, int*** map, int x, int y)
{
	for (int i = y; i >= 0; i--)
	{
		if ((*map)[x][i] == 6)
			return count;
		if ((*map)[x][i] == 0)
		{
			(*map)[x][i] = 7;
			count--;
		}
	}
	return count;
}
int rigth(int count, int*** map, int x, int y)
{
	for (int i = y; i < col; i++)
	{
		if ((*map)[x][i] == 6)
			return count;
		if ((*map)[x][i] == 0)
		{
			(*map)[x][i] = 7;
			count--;
		}
	}
	return count;
}
int  top(int count, int*** map, int x, int y)
{
	for (int i = x; i >= 0; i--)
	{
		if ((*map)[i][y] == 6)
			return count;
		if ((*map)[i][y] == 0)
		{
			(*map)[i][y] = 7;
			count--;
		}
	}
	return count;
}
int down(int count, int*** map, int x, int y)
{
	for (int i = x; i < row; i++)
	{
		if ((*map)[i][y] == 6)
			return count;
		if ((*map)[i][y] == 0)
		{
			(*map)[i][y] = 7;
			count--;
		}
	}
	return count;
}
void copy_char(int*** map, int*** copy)
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			(*copy)[i][j] = (*map)[i][j];
		}
	}
}

void func(int** map, int lev, int count)
{
	int **copy = new int*[row];
	int val;
	for (int i =0; i < row; i++)
		copy[i] = new int[col];
	if (lev == v.size())
	{
		if (count < res)
			res = count;
		return;
	}
	copy_char(&map, &copy);
	if (map[v[lev].first][v[lev].second] == 1)
	{
		val = top(count, &copy,v[lev].first,v[lev].second);
		func(copy, lev + 1, val);
		copy_char(&map, &copy);
		val = down(count, &copy,v[lev].first,v[lev].second);
		func(copy, lev + 1, val);
		copy_char(&map, &copy);
		val = left(count, &copy,v[lev].first,v[lev].second);
		func(copy, lev + 1, val);
		copy_char(&map, &copy);
		val = rigth(count, &copy,v[lev].first,v[lev].second);
		func(copy, lev + 1, val);
		copy_char(&map, &copy);
	}
	else if (map[v[lev].first][v[lev].second] == 2)
	{
		val = top(count, &copy,v[lev].first,v[lev].second);
		val = down(val, &copy,v[lev].first,v[lev].second);
		func(copy, lev + 1, val);
		copy_char(&map, &copy);
		val = left(count, &copy,v[lev].first,v[lev].second);
		val = rigth(val, &copy,v[lev].first,v[lev].second);
		func(copy, lev + 1, val);
		copy_char(&map, &copy);
	}
	else if (map[v[lev].first][v[lev].second] == 3)
	{
		val = top(count,&copy,v[lev].first,v[lev].second);
		val = rigth(val, &copy,v[lev].first,v[lev].second);
		func(copy, lev + 1, val);
		copy_char(&map, &copy);
		val = top(count, &copy,v[lev].first,v[lev].second);
		val = left(val,&copy,v[lev].first,v[lev].second);
		func(copy, lev + 1, val);
		copy_char(&map, &copy);
		val = left(count, &copy,v[lev].first,v[lev].second);
		val = down(val, &copy,v[lev].first,v[lev].second);
		func(copy, lev + 1, val);
		copy_char(&map, &copy);
		val = rigth(count, &copy,v[lev].first,v[lev].second);
		val = down(val, &copy,v[lev].first,v[lev].second);
		func(copy, lev + 1, val);
		copy_char(&map, &copy);

	}
	else if (map[v[lev].first][v[lev].second] == 4)
	{
		val = top(count, &copy,v[lev].first,v[lev].second);
		val = left(val, &copy,v[lev].first,v[lev].second);
		val = rigth(val, &copy,v[lev].first,v[lev].second);
		func(copy, lev + 1, val);
		copy_char(&map, &copy);
		val = top(count, &copy,v[lev].first,v[lev].second);
		val = down(val, &copy,v[lev].first,v[lev].second);
		val = rigth(val, &copy,v[lev].first,v[lev].second);
		func(copy, lev + 1, val);
		copy_char(&map, &copy);
		val = down(count, &copy,v[lev].first,v[lev].second);
		val = left(val, &copy,v[lev].first,v[lev].second);
		val = rigth(val, &copy,v[lev].first,v[lev].second);
		func(copy, lev + 1, val);
		copy_char(&map, &copy);
		val = top(count, &copy,v[lev].first,v[lev].second);
		val = left(val, &copy,v[lev].first,v[lev].second);
		val = down(val, &copy,v[lev].first,v[lev].second);
		func(copy, lev + 1, val);
		copy_char(&map, &copy);

	}
	else if (map[v[lev].first][v[lev].second] == 5)
	{
		val = top(count, &copy,v[lev].first,v[lev].second);
		val = down(val, &copy,v[lev].first,v[lev].second);
		val = left(val, &copy,v[lev].first,v[lev].second);
		val = rigth(val, &copy,v[lev].first,v[lev].second);
		func(copy, lev + 1, val);
	}

}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> row >> col;
	res = row * col;
	int **map = new int*[row];
	int count = 0;
	for(int i = 0; i < row; i++)
	{
		map[i] = new int[col];
		for(int j =0; j < col; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
				count++;
			else{
				if (map[i][j] != 6)
				{
					v.push_back({i,j});
				}
			}
		}
	}
	func(map, 0, count);
	cout << res;

}