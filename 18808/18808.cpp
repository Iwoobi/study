#include <iostream>

using namespace std;
int size_x, size_y;
int row,col;
int count;
int xx;
int yy;

int diff(int ** &map, int **s, int x, int y)
{
	for (int i = 0; i < xx; i++)
	{
		for (int j = 0; j < yy; j++)
		{
			if(s[i][j] == 1)
			{
				if (map[x + i][y + j] != 0)
					return 0;
			}
		}
	}
	return 1;
}
void	rot(int **s, int** &copy, int lev)
{
	if (lev == 0)
	{
		for (int i = 0; i < size_x; i++)
		{
			for (int j =0; j < size_y; j++)
			{
				copy[i][j] = s[i][j];
			}
		}
	}
	else if (lev == 1)
	{
		for (int i = 0; i < size_y; i++)
		{
			for (int j =0; j < size_x; j++)
			{
				copy[i][j] = s[size_x - j - 1][i];
			}
		}
	}
	else if (lev == 2)
	{
		for (int i = 0; i < size_x; i++)
		{
			for (int j =0; j < size_y; j++)
			{
				copy[i][j] = s[size_x - i - 1][size_y - j - 1];
			}
		}
	}
	else if (lev == 3)
	{
		for (int i = 0; i < size_y; i++)
		{
			for (int j =0; j < size_x; j++)
			{
				copy[i][j] = s[j][size_y - 1 - i];
			}
		}
	}
}
int func(int** &map, int **s,int xx, int yy)
{
		for (int i = 0; i <= row - xx; i++)
		{
			for (int j = 0; j <= col - yy; j++)
			{
				if (diff(map,s,i,j))
				{
					for (int k = 0; k < xx; k++)
					{
						for (int q =0; q < yy; q++)
						{
							if (s[k][q] == 1)
							{
								count++;
								map[i+k][j+q] = s[k][q];
							}
						}
					}
					return 1;
				}
			}
		}
		return 0;
}

void start(int** &map, int **s)
{
	for (int qq = 0; qq < 4; qq++)
	{
		int **map2;
		if (qq == 1 || qq == 3)
		{
			xx = size_y;
			yy = size_x;
			map2 = new int*[size_y];
			for (int aa =0; aa < size_y; aa++)
			{
				map2[aa] = new int[size_x];
			}
		}
		else
		{
			xx = size_x;
			yy = size_y;
			map2 = new int*[size_x];
			for (int aa =0; aa < size_x; aa++)
			{
				map2[aa] = new int[size_y];
			}
		}
		rot(s, map2, qq);
		
		if (func(map, map2,xx,yy))
		{
			if (qq == 1 || qq == 3)
			{
				for(int i = 0 ; i < size_y; i++)
					delete[] map2[i];
				delete[] map2;
			}
			else
			{
				for (int i = 0; i < size_x ; i++)
					delete[] map2[i];
				delete[] map2;
			}
			return ;
		}
		if (qq == 1 || qq == 3)
		{
			for(int i = 0 ; i < size_y; i++)
				delete[] map2[i];
			delete[] map2;
		}
		else
		{
			for (int i = 0; i < size_x ; i++)
				delete[] map2[i];
			delete[] map2;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> row >> col;
	int **map = new int*[row];
	for (int i = 0; i < row; i++)
	{
		map[i] = new int[col];
		for(int j = 0; j < col; j++)
		{
			map[i][j] = 0;
		}
	}
	int loop;
	cin >> loop;
	for (int i = 0; i < loop; i++)
	{
		cin >> size_x >> size_y;
		int **s = new int*[size_x];
		for (int j = 0; j < size_x; j++)
		{
			s[j] = new int[size_y];
			for (int k = 0; k < size_y; k++)
			{
				cin >> s[j][k]; 
			}
		}
		start(map, s);

		for(int j = 0; j < size_x; j++)
		{
			delete[] s[j];
		}
		delete[] s;
	}
	cout << count;
}